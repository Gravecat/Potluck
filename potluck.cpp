/* potluck.cpp -- Potluck C++ utility library.
   RELEASE VERSION 1.1 -- 12th December 2019

MIT License

Copyright (c) 2019 Raine Simmons.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <dirent.h>
#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#endif
#include <fstream>
#include <random>
#include <regex>
#include <sstream>
#include <sys/stat.h>

#include "pcg_random.hpp"
#include "potluck.h"

#ifdef USING_GURU_MEDITATION
#include "guru.h"
#else
#include <stdexcept>
#endif

#ifdef USING_JSONCPP
#include "jsoncpp/json/json.h"
#endif


namespace potluck
{

std::chrono::time_point<std::chrono::system_clock>	dev_timer;	// Timer used for testing.
pcg32			*pcg = nullptr;	// PCG random number generator.
unsigned int	prand_seed = 0;	// Pseudorandom number seed.

#ifdef USE_NAME_GENERATOR
#include "potluck-namegen.h"	// Static strings used in the random name generator.
bool			namegen_initialized = false;	// Has the name generation system been initialized yet?
#endif


// Build version generation.
#define BUILD_YEAR_CH0 (__DATE__[ 7])
#define BUILD_YEAR_CH1 (__DATE__[ 8])
#define BUILD_YEAR_CH2 (__DATE__[ 9])
#define BUILD_YEAR_CH3 (__DATE__[10])
#define BUILD_MONTH_IS_JAN (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_FEB (__DATE__[0] == 'F')
#define BUILD_MONTH_IS_MAR (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r')
#define BUILD_MONTH_IS_APR (__DATE__[0] == 'A' && __DATE__[1] == 'p')
#define BUILD_MONTH_IS_MAY (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y')
#define BUILD_MONTH_IS_JUN (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n')
#define BUILD_MONTH_IS_JUL (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l')
#define BUILD_MONTH_IS_AUG (__DATE__[0] == 'A' && __DATE__[1] == 'u')
#define BUILD_MONTH_IS_SEP (__DATE__[0] == 'S')
#define BUILD_MONTH_IS_OCT (__DATE__[0] == 'O')
#define BUILD_MONTH_IS_NOV (__DATE__[0] == 'N')
#define BUILD_MONTH_IS_DEC (__DATE__[0] == 'D')
#define BUILD_MONTH_CH0 ((BUILD_MONTH_IS_OCT || BUILD_MONTH_IS_NOV || BUILD_MONTH_IS_DEC) ? '1' : '0')
#define BUILD_MONTH_CH1 \
    ( \
        (BUILD_MONTH_IS_JAN) ? '1' : \
        (BUILD_MONTH_IS_FEB) ? '2' : \
        (BUILD_MONTH_IS_MAR) ? '3' : \
        (BUILD_MONTH_IS_APR) ? '4' : \
        (BUILD_MONTH_IS_MAY) ? '5' : \
        (BUILD_MONTH_IS_JUN) ? '6' : \
        (BUILD_MONTH_IS_JUL) ? '7' : \
        (BUILD_MONTH_IS_AUG) ? '8' : \
        (BUILD_MONTH_IS_SEP) ? '9' : \
        (BUILD_MONTH_IS_OCT) ? '0' : \
        (BUILD_MONTH_IS_NOV) ? '1' : \
        (BUILD_MONTH_IS_DEC) ? '2' : \
        /* error default */    '?' \
    )
#define BUILD_DAY_CH0 ((__DATE__[4] >= '0') ? (__DATE__[4]) : '0')
#define BUILD_DAY_CH1 (__DATE__[ 5])
#define BUILD_HOUR_CH0 (__TIME__[0])
#define BUILD_HOUR_CH1 (__TIME__[1])
#define BUILD_MIN_CH0 (__TIME__[3])
#define BUILD_MIN_CH1 (__TIME__[4])
#define BUILD_SEC_CH0 (__TIME__[6])
#define BUILD_SEC_CH1 (__TIME__[7])

static const char cc_date[] = { BUILD_YEAR_CH2, BUILD_YEAR_CH3, BUILD_MONTH_CH0, BUILD_MONTH_CH1, BUILD_DAY_CH0, BUILD_DAY_CH1, BUILD_HOUR_CH0, BUILD_HOUR_CH1, BUILD_MIN_CH0, BUILD_MIN_CH1, '\0' };


// Returns a build version integer.
unsigned int build_version()
{
	return atoi(potluck::cc_date);
}


// Calculates a beam between two points.
std::tuple<double, double, double>	calc_beam(int start_x, int start_y, int end_x, int end_y)
{
	const int diff_x = abs(end_x - start_x), diff_y = abs(end_y - start_y);
	double result_x = 0, result_y = 0, result_z = 0;

	if (diff_x > diff_y)
	{
		result_x = 1.0;
		result_y = (static_cast<double>(diff_y) / diff_x);
		result_z = diff_x;
	}
	else
	{
		result_y = 1.0;
		result_x = (static_cast<double>(diff_x) / diff_y);
		result_z = diff_y;
	}
	if (end_x < start_x) result_x = -result_x;
	if (end_y < start_y) result_y = -result_y;

	return std::make_tuple(result_x, result_y, result_z);
}

// Capitalizes the first letter of a string, if needed.
std::string capitalize_first(std::string str)
{
	stack_trace();
	if (!str.size()) return "";
	if (str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
	return str;
}

// Checks to see if a flag is set.
bool check_flag(unsigned int flags, unsigned int flag_to_check)
{
	return ((flags & flag_to_check) == flag_to_check);
}

// Collapses a string vector list, combining duplicates.
void collapse_list(std::vector<std::string> &vec)
{
	stack_trace();
	if (vec.size() < 2) return;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::string entry = vec.at(i);
		int total_count = 1;
		for (unsigned int j = i + 1; j < vec.size(); j++)
		{
			if (vec.at(j) == entry)
			{
				total_count++;
				vec.erase(vec.begin() + j);
				j--;
			}
		}
		if (total_count > 1) vec.at(i) = entry + " (" + potluck::itos(total_count) + ")";
	}
}

// Converts a vector to a comma-separated list.
std::string comma_list(std::vector<std::string> vec, bool use_and)
{
	stack_trace();
	if (!vec.size()) return "";
	if (vec.size() == 1) return vec.at(0);
	std::string plus = " and ";
	if (!use_and) plus = " or ";
	else if (vec.size() == 2) return vec.at(0) + plus + vec.at(1);

	std::string str;
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		str += vec.at(i);
		if (i < vec.size() - 1)
		{
			if (i == vec.size() - 2) str += plus;
			else str += ", ";
		}
	}

	return str;
}

#ifdef USE_NAME_GENERATOR
// Picks a consonant from the table, for forming atoms.
std::string consonant()
{
	stack_trace();
	if (!potluck::namegen_initialized) namegen_init();
	const int pos = potluck::rnd(potluck::consonant_block.size()) - 1;
	return potluck::consonant_block.substr(pos, 1);
}
#endif

// Counts the number of lines in a file.
unsigned int count_lines(std::string file)
{
	stack_trace();
	std::ifstream fh(file);
	unsigned int count = 0;
	std::string line;
	while (std::getline(fh, line))
		count++;
	fh.close();
	return count;
}

// Counts the number of lines in all files in a directory.
unsigned int count_lines_in_dir(std::string dir, bool recursion)
{
	stack_trace();
	std::vector<std::string> filenames = potluck::files_in_dir(dir);
	unsigned int count = 0;
	for (auto fn : filenames)
	{
		fn = dir + "/" + fn;
		if (potluck::directory_exists(fn))
		{
			if (!recursion) continue;
			count += potluck::count_lines_in_dir(fn, true);
		}
		else count += potluck::count_lines(fn);
	}
	return count;
}

// Simple CRC32 implementation.
unsigned int crc32c(unsigned int crc, const unsigned char *buf, size_t len)
{
	stack_trace();
	crc = ~crc;
	while(len--)
	{
		crc ^= *buf++;
		for (int k = 0; k < 8; k++)
			crc = crc & 1 ? (crc >> 1) ^ 0x82f63b78 : crc >> 1;
	}
	return ~crc;
}

// Returns the modified date/time of a file, or 0 if the file is not found.
time_t date_modified(std::string file)
{
	stack_trace();
	struct stat result;
	if (stat(file.c_str(), &result) == 0)
		return result.st_mtime;
	return 0;
}

// Decodes a compressed string (e.g. 4cab2z becomes ccccabzz).
std::string decode_compressed_string(std::string cb)
{
	stack_trace();
	std::string result;
	while(cb.size())
	{
		std::string letter = cb.substr(0, 1);
		cb = cb.substr(1);
		if (letter[0] >= '0' && letter[0] <= '9')
		{
			int number = letter[0] - '0';
			letter = cb.substr(0, 1);
			cb = cb.substr(1);
			while (letter[0] >= '0' && letter[0] <= '9')
			{
				number *= 10;
				number += letter[0] - '0';
				letter = cb.substr(0, 1);
				cb = cb.substr(1);
			}
			result += std::string(number, letter[0]);
		}
		else result += letter;
	}
	return result;
}

// Starts a timer for debugging/testing purposes.
void dev_timer_start()
{
	potluck::dev_timer = std::chrono::system_clock::now();
}

// Stops the timer and reports the result.
float dev_timer_stop()
{
	std::chrono::duration<float> elapsed_seconds = std::chrono::system_clock::now() - potluck::dev_timer;
	return elapsed_seconds.count();
}

// Checks if a directory exists.
bool directory_exists(std::string dir)
{
	stack_trace();
	struct stat info;
	if (stat(dir.c_str(), &info) != 0) return false;
	if (info.st_mode & S_IFDIR) return true;
	else return false;
}

// Returns the CRC32 checksum of a given file.
unsigned int file_crc32(std::string file)
{
	stack_trace();
	if (!potluck::file_exists(file)) return 0;

	std::ifstream handle(file, std::ios::binary | std::ios::ate);
	if (!handle.good()) return 0;
	std::streamsize size = handle.tellg();
	handle.seekg(0, std::ios::beg);
	std::vector<char> buffer(size);
	if (!handle.read(buffer.data(), size))
	{
		handle.close();
		return 0;
	}
	handle.close();
	return potluck::crc32c(0, (unsigned char*)buffer.data(), size);
}

// Checks if a file exists.
bool file_exists(std::string file)
{
	stack_trace();
	struct stat info;
	return (stat(file.c_str(), &info) == 0);
}

// Returns a list of files in a given directory.
std::vector<std::string> files_in_dir(std::string directory)
{
	stack_trace();
	DIR *dir;
	struct dirent *ent;
	std::vector<std::string> files;
	if (!(dir = opendir(directory.c_str()))) return files;
	while ((ent = readdir(dir)))
	{
		std::string filename = std::string(ent->d_name);
		if (filename == "." || filename == "..") continue;
		files.push_back(filename);
	}
	closedir(dir);
	return files;
}

// Find and replace one string with another.
bool find_and_replace(std::string &input, std::string to_find, std::string to_replace)
{
	stack_trace();
	std::string::size_type pos = 0;
	const std::string::size_type find_len = to_find.length(), replace_len = to_replace.length();
	if (find_len == 0) return false;
	bool found = false;
	while ((pos = input.find(to_find, pos)) != std::string::npos)
	{
		found = true;
		input.replace(pos, find_len, to_replace);
		pos += replace_len;
	}
	return found;
}

// Finds a piece of a string between two other strings.
std::string find_between(std::string source, std::string before, std::string after)
{
	stack_trace();
	const size_t bp = source.find(before, 0);
	if (bp == std::string::npos) return "";
	const size_t ap = source.find(after, bp);
	if (ap == std::string::npos) return "";
	return source.substr(bp + before.size(), ap - bp - before.size());
}

// Converts a float or double to a string.
std::string ftos(double num)
{
	stack_trace();
	std::stringstream ss;
	ss << num;
	return ss.str();
}

// Fuzzes a number, giving an estimate (e.g. 123456 becoomes 100000).
unsigned int fuzz(unsigned int num)
{
	stack_trace();
	if (num >= 1000000000) { num = round(num / 1000000000.0f); return num * 1000000000; }
	if (num >= 100000000) { num = round(num / 100000000.0f); return num * 100000000; }
	if (num >= 10000000) { num = round(num / 10000000.0f); return num * 10000000; }
	if (num >= 1000000) { num = round(num / 1000000.0f); return num * 1000000; }
	if (num >= 100000) { num = round(num / 100000.0f); return num * 100000; }
	if (num >= 10000) { num = round(num / 10000.0f); return num * 10000; }
	if (num >= 1000) { num = round(num / 1000.0f); return num * 1000; }
	if (num >= 100) { num = round(num / 100.0f); return num * 100; }
	if (num >= 10) { num = round(num / 10.0f); return num * 10; }
	return num;
}

// Determines the difference between two points on a grid.
float grid_dist(long long x1, long long y1, long long x2, long long y2)
{
	stack_trace();
	const long long dist_x = x2 - x1, dist_y = y2 - y1;
	const float dist = (sqrt((dist_x * dist_x) + (dist_y * dist_y)));
	return potluck::round_to_two(dist);
}

// As above, but for a three-dimensional grid.
float grid_dist(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2)
{
	stack_trace();
	const long long dist_x = x2 - x1, dist_y = y2 - y1, dist_z = z2 - z1;
	const float dist = (sqrt((dist_x * dist_x) + (dist_y * dist_y) + (dist_z * dist_z)));
	return potluck::round_to_two(dist);
}

#ifdef USING_ZLIB
// Reads an unencrypted string from a zlib binary file, with size markers. Harder than it sounds.
std::string gz_read_string(const gzFile &file_load)
{
	STACK_TRACE();
	if (!file_load)
	{
#ifdef USING_GURU_MEDITATION
		guru::halt("Invalid file handle!");
#else
		abort();
#endif
	}

	// First, read the length of the string.
	size_t datalen;
	gzread(file_load, &datalen, sizeof(datalen));

	// Create a buffer, and load the string into it.
	char *buffer = new char[datalen + 1];
	if (!buffer)
	{
#ifdef USING_GURU_MEDITATION
		guru::halt("Could not allocate memory!");
#else
		abort();
#endif
	}
	gzread(file_load, buffer, datalen);

	// Convert the c_str into a C++ string.
	std::stringstream output;
	output << buffer;
	delete[] buffer;
	return output.str();
}

// Writes a string to a zlib binary save file, with length markers.
void gz_write_string(const gzFile &file_save, std::string data)
{
	stack_trace();
	if (!file_save)
	{
#ifdef USING_GURU_MEDITATION
		guru::halt("Invalid file handle!");
#else
		abort();
#endif
	}

	// Convert the C++ string into a c_str
	const char* cdata = data.c_str();

	// First, write the length of the string.
	const size_t datalen = strlen(cdata) + 1;
	gzwrite(file_save, &datalen, sizeof(datalen));

	// Then write the data, in c_str format.
	gzwrite(file_save, cdata, datalen);
}

// Writes a clear-text string to a zlib binary file, with no markers.
void gz_write_string_clear(const gzFile &file_save, std::string data)
{
	stack_trace();
	if (!file_save)
	{
#ifdef USING_GURU_MEDITATION
		guru::halt("Invalid file handle!");
#else
		abort();
#endif
	}
	data += "\r\n";

	// Convert the C++ string into a c_str
	const char* cdata = data.c_str();
	const size_t datalen = strlen(cdata);

	// Then write the data, in c_str format.
	gzwrite(file_save, cdata, datalen);
}
#endif

// FNV string hash.
unsigned int hash(std::string s)
{
	stack_trace();
	size_t result = 2166136261U;
	std::string::const_iterator end = s.end();
	for (std::string::const_iterator iter = s.begin(); iter != end; ++iter)
		result = 127 * result + static_cast<unsigned char>(*iter);
	return result;
}

// Converts a hex string back to an integer.
unsigned int htoi(std::string hex_str)
{
	stack_trace();
	std::stringstream ss;
	ss << std::hex << hex_str;
	unsigned int result;
	ss >> result;
	return result;
}

// Simple way to check if a string is in another string.
bool instr(std::string input, std::string check)
{
	stack_trace();
	return (input.find(check, 0) != std::string::npos);
}

// Converts a number into Roman numerals.
std::string intoroman(unsigned short number)
{
	stack_trace();
	if (number == 0) return "0";
	if (number > 3999) return "MMMM+";
	const int values[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	const std::string numerals[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	std::string output = "";

	for (int i = 0; i < 13; i++)
	{
		while (number >= values[i])
		{
			number -= values[i];
			output += numerals[i];
		}
	}

	return output;
}

// Converts an int into a k-style string; for example 10000 becomes 10k.
std::string intostr_k(unsigned long long num, unsigned int precision)
{
	stack_trace();
	unsigned long long shortened = 0;
	double remainder = 0;
	std::string digit = "";
	if (num < 100) return potluck::itos(num);
	else if (num < 1000)
	{
		if (precision)
		{
			remainder = (num % 1000) / 1000.0f;
			shortened = num / 1000;
			digit = "k";
			if (!remainder) return potluck::itos(num);
		}
		else return potluck::itos(num);
	}
	else if (num >= 1000000000000000000ULL)
	{
		shortened = num / 1000000000000000000ULL;
		remainder = num % (1000000000000000000ULL) / 1000000000000000000.0f;
		digit = "E";
	}
	else if (num >= 1000000000000000ULL)
	{
		shortened = num / 1000000000000000ULL;
		remainder = num % (1000000000000000ULL) / 1000000000000000.0f;
		digit = "P";
	}
	else if (num >= 1000000000000ULL)
	{
		shortened = num / 1000000000000ULL;
		remainder = num % (1000000000000ULL) / 1000000000000.0f;
		digit = "T";
	}
	else if (num >= 1000000000UL)
	{
		shortened = num / 1000000000UL;
		remainder = (num % 1000000000UL) / 1000000000.0f;
		digit = "G";
	}
	else if (num >= 1000000UL)
	{
		shortened = num / 1000000UL;
		remainder = (num % 1000000UL) / 1000000.0f;
		digit = "M";
	}
	else
	{
		shortened = num / 1000;
		remainder = (num % 1000) / 1000.0f;
		digit = "k";
	}
	if (remainder && precision)
	{
		std::string remainder_str = potluck::ftos(potluck::round_to(remainder, precision)).substr(1);
		if (!remainder_str.size()) shortened++;
		std::string result = potluck::itos(shortened) + remainder_str + digit;
		return result;
	}
	if (digit.size() && !shortened) shortened = 1;
	return potluck::itos(shortened) + digit;
}

// Returns a 'pretty' version of a number in string format, such as "12,345".
std::string intostr_pretty(int num)
{
	stack_trace();
	bool negative = false;
	if (num < 0) { negative = true; num = 0-num; }
	std::string str = potluck::itos(num), output;

	// If the number is 3 or less characters long, there's no need for any processing.
	if (str.length() <= 3) return((negative ? "-" : "") + str);

	do
	{
		// Cut the string up, and insert commas where appropriate.
		output = str.substr(str.length()-3, 3) + "," + output;
		str = str.substr(0, str.length()-3);
	} while(str.length() > 3);

	// Combine the results.
	std::string result = str + "," + output;

	// Remove the trailing comma.
	result = result.substr(0, result.length()-1);

	return((negative ? "-" : "") + result);
}

// 64-bit version.
std::string intostr_pretty64(unsigned long long num)
{
	stack_trace();
	std::string str = potluck::uitos(num), output;

	// If the number is 3 or less characters long, there's no need for any processing.
	if (str.length() <= 3) return str;

	do
	{
		// Cut the string up, and insert commas where appropriate.
		output = str.substr(str.length()-3, 3) + "," + output;
		str = str.substr(0, str.length()-3);
	} while(str.length() > 3);

	// Combine the results.
	std::string result = str + "," + output;

	// Remove the trailing comma.
	result = result.substr(0, result.length()-1);
	return result;
}

// Checks if a filename is a file or directory.
bool is_file(std::string filename)
{
	stack_trace();
	struct stat s;
	if (stat(filename.c_str(), &s) == 0)
	{
		if (s.st_mode & S_IFDIR) return false;	// It's a directory.
		else if (s.st_mode & S_IFREG) return true;	// It's a file.
		else return false;	// It's something else.
	}
	return false;
}

// Checks if a number is odd.
bool is_odd(unsigned int num)
{
	return (num % 2);
}

// Converts an integer into a hex string.
std::string itoh(unsigned int num, unsigned char min_len)
{
	stack_trace();
	std::stringstream ss;
	ss << std::hex << num;
	std::string hex = ss.str();
	while (min_len && hex.size() < min_len) hex = "0" + hex;
	return hex;
}

// Converts an integer to a string.
std::string itos(long long num)
{
	stack_trace();
	std::stringstream ss;
	ss << num;
	return ss.str();
}

#ifdef USING_JSONCPP
// Loads an individual JSON file, with error-checking.
Json::Value	load_json(std::string filename)
{
	stack_trace();
	Json::Value json;
	std::ifstream file_load(filename, std::ios::in);
	try
	{
		Json::CharReaderBuilder builder;
		builder["rejectDupKeys"] = true;
		JSONCPP_STRING errs;
		bool ok = Json::parseFromStream(builder, file_load, &json, &errs);
		if (!ok)
		{
			file_load.close();
#ifdef USING_GURU_MEDITATION
			guru::halt(errs);
#else
			abort();
#endif
		}
	}
	catch (std::exception &e)
	{
		file_load.close();
#ifdef USING_GURU_MEDITATION
		guru::halt(e.what());
#else
		abort();
#endif
	}
	file_load.close();
	return json;
}
#endif

// Loads a text file into a string vector.
std::vector<std::string> load_text(std::string filename)
{
	stack_trace();
	std::vector<std::string> result;
	std::ifstream file_load(filename);
	if (!file_load.good())
	{
#ifdef USING_GURU_MEDITATION
		guru::nonfatal("Could not open file: " + filename, GURU_CRITICAL);
#endif
		return result;
	}
	std::string line;
	while (getline(file_load, line))
		result.push_back(line);
	return result;
}

// Makes a new directory, if it doesn't already exist.
void make_dir(std::string dir)
{
	stack_trace();
	if (potluck::directory_exists(dir)) return;

#if defined(_WIN32) || defined(_WIN64)
	_mkdir(dir.c_str());
#else
	mkdir(dir.c_str(), 0777);
#endif
}

// Converts a metadata unordered_map into a string.
std::string	metadata_to_string(std::unordered_map<std::string, std::string> md)
{
	stack_trace();
	std::string md_str;
	for (auto mde : md)
		md_str += mde.first + ":" + mde.second + " ";
	md_str.pop_back();
	return md_str;
}

// Mixes up an integer a little.
unsigned int mixup(unsigned int num, bool big_mix)
{
	stack_trace();
	const long long variance = num / (big_mix ? 2 : 10);
	long long result = static_cast<long long>(num) + potluck::rnd(variance * 2) - variance;
	if (result < 1) result = 1;
	return result;
}

#ifdef USE_NAME_GENERATOR
// Initializes the random name generator. This function will be called automatically if the namegen system is used without setting up first.
void namegen_init()
{
	stack_trace();
	if (potluck::namegen_initialized) return;
	potluck::namegen_initialized = true;
	potluck::consonant_block = decode_compressed_string(potluck::consonant_block);
}
#endif

// Converts small numbers into words.
// Thanks to Josh Homann on StackOverflow for this one: https://stackoverflow.com/questions/40252753/c-converting-number-to-words
std::string number_to_word(unsigned long long number)
{
	stack_trace();
	static const std::vector<std::string> ones { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	static const std::vector<std::string> teens { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen" };
	static const std::vector<std::string> tens { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	if (number < 10) return ones[number];
	else if (number < 20) return teens[number - 10];
	else if (number < 100) return tens[number / 10] + ((number % 10 != 0) ? "-" + potluck::number_to_word(number % 10) : "");
	else if (number < 1000) return potluck::number_to_word(number / 100) + " hundred" + ((number % 100 != 0) ? " " + potluck::number_to_word(number % 100) : "");
	else if (number < 1000000) return potluck::number_to_word(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + potluck::number_to_word(number % 1000) : "");
	else if (number < 1000000000UL) return potluck::number_to_word(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + potluck::number_to_word(number % 1000000) : "");
	else if (number < 1000000000000ULL) return potluck::number_to_word(number / 1000000000UL) + " billion" + ((number % 1000000000UL != 0) ? " " + potluck::number_to_word(number % 1000000000UL) : "");
	else return potluck::intostr_pretty(number);
}

// Returns the value of a key in specified metadata, if any.
std::string parse_meta(std::string metadata, std::string key)
{
	stack_trace();
	if (!metadata.size()) return "";
	std::vector<std::string> pairs = potluck::string_explode(metadata, " ");
	std::unordered_map<std::string, std::string> data;
	for (unsigned int p = 0; p < pairs.size(); p++)
	{
		std::vector<std::string> split = potluck::string_explode(pairs.at(p), ":");
		if (split.size() != 2)
		{
#ifdef USING_GURU_MEDITATION
			guru::halt("Invalid metadata string [" + metadata + "], [" + pairs.at(p) + "]");
#else
			throw std::invalid_argument("invalid metadata string");
#endif
		}
		data.insert(std::pair<std::string, std::string>(split.at(0), split.at(1)));
	}
	if (data.find(key) == data.end()) return "";
	else return data.at(key);
}

// Simple perlin noise generation.
double perlin(double x, double y, double zoom, double p, int octaves)
{
	stack_trace();
	double getnoise = 0.0;
	for (int a = 0; a < octaves - 1; a++)
	{
		const double frequency = pow(2, a);
		const double amplitude = pow(p, a);
		getnoise += potluck::perlin_noise(x * frequency / zoom, y / zoom * frequency) * amplitude;
	}
	return getnoise;
}

// Pseudo-random number generator for Perlin noise generation.
double perlin_findnoise2(double x, double y)
{
	stack_trace();
	long long n = static_cast<long long>(x) + static_cast<long long>(y) * 57;
	n = (n << 13) ^ n;
	const long long nn = (n * (n * n * 60493 + 19990303) + 1376312589) & 0x7fffffff;
	return 1.0 - (static_cast<double>(nn) / 1073741824.0f);
}

// Cosine interpolation.
double perlin_interpolate(double a, double b, double x)
{
	stack_trace();
	const double ft = x * M_PI;
	const double f = (1.0 - cos(ft)) * 0.5;
	return a * (1.0 - f) + b * f;
}

// Generate noise for a given coordinate.
double perlin_noise(double x, double y)
{
	stack_trace();
	const double floorx = static_cast<double>(static_cast<long long>(x));
	const double floory = static_cast<double>(static_cast<long long>(y));
	double s, t, u, v;
	s = potluck::perlin_findnoise2(floorx, floory);
	t = potluck::perlin_findnoise2(floorx + 1, floory);
	u = potluck::perlin_findnoise2(floorx, floory + 1);
	v = potluck::perlin_findnoise2(floorx + 1, floory + 1);
	const double int1 = potluck::perlin_interpolate(s, t, x - floorx);
	const double int2 = potluck::perlin_interpolate(u, v, x - floorx);
	return potluck::perlin_interpolate(int1, int2, y - floory);
}

// Wrapper to generate a 0-255 RGB value for the given coord.
unsigned char perlin_rgb(double x, double y, double zoom, double p, int octaves)
{
	stack_trace();
	const double getnoise = perlin(x, y, zoom, p, octaves);
	int color = static_cast<int>((getnoise * 128.0f) + 128.0f);  // Convert to 0-256 values.
	if (color > 255) color = 255;
	if (color < 0) color = 0;
	return static_cast<unsigned char>(color);
}

// Turns "cat" into "cat's", but "Jeeves" into "Jeeves'".
std::string possessive(std::string noun)
{
	stack_trace();
	if (!noun.size()) return "";
	if (noun.at(noun.size() - 1) == 's') return noun + "'";
	else return noun + "'s";
}

// Simpler, easily-seedable pseudorandom number generator.
unsigned int prand(unsigned int lim)
{
	stack_trace();
	if (lim <= 1) return 1;
	potluck::prand_seed = (potluck::prand_seed * 0x43FD43FD + 0xC39EC3) & 0xFFFFFF;
	const float tmp = static_cast<float>(potluck::prand_seed) / 16777216.0f;
	return static_cast<unsigned int>((tmp * lim) + 1);
}

#ifdef USE_NAME_GENERATOR
// Generates a random designation string, such as AFJ-427.
std::string random_designation()
{
	stack_trace();
	std::string name;
	for (int i = 0; i < 3; i++) name += static_cast<char>(potluck::rnd(26) + 64);
	name += "-";
	for (unsigned int i = 0; i < potluck::rnd(2) + 2; i++) name += static_cast<char>(potluck::rnd(10) + 47);
	return name;
}
#endif

// Returns a random line from a text file.
std::string random_line(std::string filename, unsigned int lines)
{
	stack_trace();
	std::ifstream text_file(filename);
	const unsigned int choice = potluck::rnd(lines) - 1;
	std::string line;
	unsigned int count = 0;
	while(getline(text_file, line))
	{
		if (choice == count++)
		{
			text_file.close();
			return line;
		}
	}
	text_file.close();
	return "[error]";
}

#ifdef USE_NAME_GENERATOR
// Generates a random human name.
std::string random_name(bool female)
{
	stack_trace();
	std::string first_name, surname;
	if (female) first_name = potluck::names_f[potluck::rnd(NAMEGEN_FEMALE_NAMES) - 1];
	else first_name = potluck::names_m[potluck::rnd(NAMEGEN_MALE_NAMES) - 1];
	surname = potluck::names_s[potluck::rnd(NAMEGEN_SURNAMES) - 1];
	return first_name + " " + surname;
}

// Generates a random word, using the v1 method.
std::string random_word_v1()
{
	stack_trace();
	std::string name;	// The word in construction.
	std::string atom;	// A double-letter combination chosen for addition to the word.

	// Construct a max-length word to begin with.
	for (int i = 0; i < 4; i++)
	{
		// The type of atom chosen depends on the seed.
		const int choice = potluck::rnd(7);

		// Assign the appropriate type of atom.
		if (choice >= 1 && choice <= 3) atom = potluck::vowel() + potluck::consonant();
		else if (choice >= 4 && choice <= 7) atom = potluck::consonant() + potluck::vowel();
		else if (choice == 8 || choice == 9) atom = potluck::vowel() + potluck::vowel();
		else if (choice == 10) atom = potluck::consonant() + potluck::consonant();

		// Add the atom to the word-in-progress.
		name += atom;
	}

	// Trim the word's length down to a specified number.
	const int length = potluck::rnd(4) + 3;
	name = name.substr(0, length);

	// Make the first letter of the word capitalized.
	name.at(0) -= 32;

	return name;
}

// Generates a random word, using the v2 method.
std::string random_word_v2(bool cap)
{
	stack_trace();

	// Ends of words.
	auto pv3_t = []() -> std::string {
		stack_trace();
		if (potluck::rnd(2) == 1) return potluck::pv3_v[potluck::rnd(5) - 1] + potluck::pv3_f[potluck::rnd(40) - 1];
		else return potluck::pv3_v[potluck::rnd(5) - 1] + potluck::pv3_e[potluck::rnd(17) - 1] + "e";
	};

	std::string gen_name = "";
	switch(potluck::rnd(8))
	{
		case 1:
		case 2: gen_name = potluck::pv3_c[potluck::rnd(41) - 1] + pv3_t(); break;
		case 3: gen_name = potluck::pv3_c[potluck::rnd(41) - 1] + potluck::pv3_x[potluck::rnd(6) - 1]; break;
		case 4: gen_name = potluck::pv3_c[potluck::rnd(41) - 1] + potluck::pv3_d[potluck::rnd(8) - 1] + potluck::pv3_f[potluck::rnd(40) - 1]; break;
		case 5: gen_name = potluck::pv3_c[potluck::rnd(41) - 1] + potluck::pv3_v[potluck::rnd(5) - 1] + potluck::pv3_f[potluck::rnd(40) - 1] + pv3_t(); break;
		case 6: gen_name = potluck::pv3_i[potluck::rnd(5) - 1] + pv3_t(); break;
		case 7: gen_name = potluck::pv3_i[potluck::rnd(5) - 1] + potluck::pv3_c[potluck::rnd(41) - 1] + pv3_t(); break;
		case 8: gen_name = potluck::pv3_k[potluck::rnd(19) - 1] + potluck::pv3_v[potluck::rnd(5) - 1] + potluck::pv3_k[potluck::rnd(19) - 1] + potluck::pv3_v[potluck::rnd(5) - 1]; break;
		default: break;
	}
	if (cap) gen_name[0] = toupper((unsigned char)gen_name[0]);

	return gen_name;
}
#endif

// Attempts to delete a directory and everything within.
void remove_directory(std::string dir_str)
{
	stack_trace();
	if (!potluck::directory_exists(dir_str)) return;
	std::vector<std::string> files = potluck::files_in_dir(dir_str);
	for (auto file : files)
		remove((dir_str + "/" + file).c_str());
	rmdir(dir_str.c_str());
}

// Right-aligns a percentage string.
std::string right_align_percentage(unsigned char percent)
{
	stack_trace();
	std::string result = potluck::itos(percent) + "%";
	while (result.size() < 4) result = " " + result;
	return result;
}

// Returns a random number between 1 and max.
unsigned int rnd(unsigned int max)
{
	if (max <= 1) return max;
	stack_trace();
	if (!potluck::pcg) potluck::pcg = new pcg32(pcg_extras::seed_seq_from<std::random_device>{});
	std::uniform_int_distribution<unsigned int> uniform_dist(1, max);
	return uniform_dist(*potluck::pcg);
}

// 'Rolls' a specified amount of dice.
unsigned int roll(std::string dice)
{
	stack_trace();
	std::vector<std::string> dice_vec = potluck::string_explode(dice, "d");
	if (dice_vec.size() != 2)
	{
#ifdef USING_GURU_MEDITATION
		guru::halt("Invalid dice string: " + dice);
#else
		throw std::invalid_argument("invalid dice string: " + dice);
#endif
	}
	std::vector<std::string> dice_vec2 = potluck::string_explode(dice_vec.at(1), "+");
	dice_vec.at(1) = dice_vec2.at(0);
	if (dice_vec2.size() > 1) dice_vec.push_back(dice_vec2.at(1)); else dice_vec.push_back("0");
	const int num = atoi(dice_vec.at(0).c_str());
	const int sides = atoi(dice_vec.at(1).c_str());
	const int plus = atoi(dice_vec.at(2).c_str());
	if (num < 1 || sides < 2)
	{
#ifdef USING_GURU_MEDITATION
		guru::halt("Invalid dice string: " + dice);
#else
		throw std::invalid_argument("invalid dice string: " + dice);
#endif
	}
	unsigned int result = 0;

	// Roll them dice!
	for (int i = 0; i < num; i++)
		result += potluck::rnd(sides);
	result += plus;

	return result;
}

// Rounds a float to a specified number of digits.
double round_to(double num, unsigned int digits)
{
	stack_trace();
	const double power = pow(10, digits);
	num *= power;
	const double rounded = round(num);
	return rounded / power;
}

// Rounds a float to two decimal places.
float round_to_two(float num)
{
	stack_trace();
	return floorf(num * 100 + 0.5) / 100;
}

// Converts a set of integers into a string.
std::string set_to_string(std::set<unsigned int> the_set)
{
	stack_trace();
	if (!the_set.size()) return "";
	std::string str;
	for (auto num : the_set)
		str += potluck::itoh(num, 1) + " ";
	if (str.size()) str = str.substr(0, str.size() - 1);	// Strip off the excess space at the end.
	return str;
}

// It's like XOR, but sneakier.
unsigned char sneaky_xor(unsigned char src, unsigned char mask)
{
	if (src == mask || (src ^ mask) == ' ' || (src ^ mask) == '\n' || (src ^ mask) == 1) return src;
	else if (src == ' ') return 0;
	else if (src == 0) return ' ';
	else if (src == '\n') return 1;
	else if (src == 1) return '\n';
	else return src ^ mask;
}

// Repeats a string a number of times.
std::string str_repeat(std::string source, int repeats)
{
	stack_trace();
	std::ostringstream os;
	for (int i = 0; i < repeats; i++)
		os << source;
	return os.str();
}

// Converts a string to lower-case.
std::string str_tolower(std::string str)
{
	stack_trace();
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

// Converts a string to a wstring.
std::wstring str_to_wstr(std::string str)
{
	stack_trace();
	std::wstring result(str.length(), L' ');
	std::copy(str.begin(), str.end(), result.begin());
	return result;
}

// Converts a string to upper-case.
std::string str_toupper(std::string str)
{
	stack_trace();
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

// String split/explode function.
std::vector<std::string> string_explode(std::string str, std::string separator)
{
	stack_trace();
	std::vector<std::string> results;

	std::string::size_type pos = str.find(separator, 0);
	const int pit = separator.length();

	while(pos != std::string::npos)
	{
		if (pos == 0) results.push_back("");
		else results.push_back(str.substr(0, pos));
        str.erase(0, pos + pit);
        pos = str.find(separator, 0);
    }
    results.push_back(str);

    return results;
}

// Converts a metadata string into an unordered_map.
std::unordered_map<std::string, std::string> string_to_metadata(std::string metadata)
{
	stack_trace();
	std::unordered_map<std::string, std::string> result;
	if (!metadata.size()) return result;

	std::vector<std::string> md_exp = potluck::string_explode(metadata, " ");
	for (unsigned int i = 0; i < md_exp.size(); i++)
	{
		std::vector<std::string> md_pair = potluck::string_explode(md_exp.at(i), ":");
		if (md_pair.size() != 2)
		{
#ifdef USING_GURU_MEDITATION
			guru::nonfatal("Invalid metadata string: " + metadata, GURU_ERROR);
#endif
		}
		else result.insert(std::pair<std::string, std::string>(md_pair.at(0), md_pair.at(1)));
	}
	return result;
}

// Converts a string of integers into a set.
void string_to_set(std::string set_string, std::set<unsigned int> &the_set)
{
	stack_trace();
	the_set.clear();
	if (!set_string.size()) return;
	std::vector<std::string> split_str = potluck::string_explode(set_string, " ");
	for (auto split : split_str)
		the_set.insert(potluck::htoi(split));
}

// Returns a timestamp in the format of: 1802152346
std::string timestamp(bool pretty)
{
	stack_trace();
	time_t ltime = time(0);
	struct tm *result = localtime(&ltime);
	std::string year = potluck::itos(result->tm_year - 100);
	std::string month = potluck::itos(result->tm_mon); if (month.size() == 1) month = "0" + month;
	std::string day = potluck::itos(result->tm_mday); if (day.size() == 1) day = "0" + day;
	std::string hour = potluck::itos(result->tm_hour); if (hour.size() == 1) hour = "0" + hour;
	std::string minute = potluck::itos(result->tm_min); if (minute.size() == 1) minute = "0" + minute;

	if (pretty) return day + "/" + month + "/" + year + " " + hour + ":" + minute;
	else return year + month + day + hour + minute;
}

// Creates an empty placeholder file.
void touch(std::string file)
{
	stack_trace();
	if (potluck::file_exists(file)) return;
	FILE *fptr = fopen(file.c_str(), "wb");
	fclose(fptr);
}

// Trims out leading, trailing, and excess (more than one at a time) spaces from a string.
std::string trim_excess_spaces(std::string source)
{
	stack_trace();
	return std::regex_replace(source, std::regex("^ +| +$|( ) +"), "$1");
}

// Reads a raw text file into a map.
void txt_to_map(std::string filename, std::map<std::string, std::string> &map, bool process_tags)
{
	stack_trace();
	std::vector<std::string> vec;
	std::string line, tag, data;
	std::ifstream file_load(filename.c_str(), std::ios::in);
	while (file_load.is_open() && file_load.good())
	{
		getline(file_load, line);
		if (process_tags)
		{
			if (!line.size()) continue;   // Ignore empty lines.
			if (line[0] == '/' && line[1] == '/') continue; // Ignore comment lines.
			unsigned int pos = line.find(":");
			tag = line.substr(0, pos);
			data = line.substr(pos + 1);
			tag = tag.substr(1, tag.size() - 2);
			vec.push_back(tag);
			vec.push_back(data);
		} else vec.push_back(line);
	}
	file_load.close();

	// Make sure the vector has an even number of elements, and is not empty.
	if (!vec.size()) vec.push_back("null");
	if (vec.size() % 2) vec.push_back("");

	// Convert the vector to a map.
	for (unsigned int i = 0; i < vec.size(); i += 2)
		map.insert(std::pair<std::string, std::string>(vec.at(i), vec.at(i + 1)));
}

// Unsigned version of itos().
std::string uitos(unsigned long long num)
{
	stack_trace();
	std::stringstream ss;
	ss << num;
	return ss.str();
}

// Splits a string into a vector of strings, to a given line length.
std::vector<std::string> vector_split(std::string source, unsigned int line_len)
{
	stack_trace();
	std::vector<std::string> result;
	if (source.size() <= line_len)
	{
		result.push_back(source);
		return result;
	}
	std::vector<std::string> words = potluck::string_explode(source, " ");
	std::string current_line;
	while (words.size())
	{
		std::string word = words.at(0);
		words.erase(words.begin());
		if (word.size() > line_len)
		{
			// If the word itself is too long for the line, break it into two, then deal with them individually.
			// We'll then deal with that in the normal way afterwards. If the second half is still too long, it'll get broken up again when we get to it.
			// This could result in more iteration for edge cases, but overall keeps the code nice and simple.
			std::string first_half = word.substr(0, line_len);
			std::string second_half = word.substr(line_len + 1);
			words.insert(words.begin(), second_half);
			words.insert(words.begin(), first_half);
			continue;
		}
		if (current_line.size() + word.size() + 1 > line_len)
		{
			result.push_back(current_line);
			current_line = word;
			continue;
		}
		if (current_line.size()) current_line += " " + word;
		else current_line = word;
	}
	if (current_line.size()) result.push_back(current_line);
	return result;
}

#ifdef USE_NAME_GENERATOR
// Picks a vowel from the table, for forming atoms.
std::string vowel()
{
	stack_trace();
	const int pos = potluck::rnd(potluck::vowel_block.size()) - 1;
	return potluck::vowel_block.substr(pos,1);
}
#endif

// Returns a count of the amount of times a string is found in a parent string.
int word_count(std::string str, std::string word)
{
	stack_trace();
	int count = 0;
	std::string::size_type word_pos = 0;
	while(word_pos != std::string::npos)
	{
		word_pos = str.find(word, word_pos);
		if (word_pos != std::string::npos)
		{
			count++;
			word_pos += word.length();
		}
	}
	return count;
}

}	// namespace potluck
