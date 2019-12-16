/* potluck.h -- Potluck C++ utility library.
   RELEASE VERSION 1.13 -- 16th December 2019

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

#pragma once

#define POTLUCK_USING_GURU_MEDITATION	// Comment out this line if you are NOT using my Guru Meditation library and/or do not want to include the stack-trace code.
#define POTLUCK_USING_JSONCPP			// Comment out this line if you are NOT using JsonCpp.
//#define POTLUCK_USING_ZLIB			// Uncomment this line if you're using zlib.

#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>


#ifdef POTLUCK_USING_JSONCPP
namespace Json { class Value; }
#endif

#ifdef POTLUCK_USING_ZLIB
struct gzfile_s;
typedef struct gzFile_s *gzFile;
#endif

// If we're NOT using the Guru Meditation system, this'll just make the stack_trace() call do nothing.
#ifndef POTLUCK_USING_GURU_MEDITATION
#define stack_trace() (void)0
#endif


namespace potluck
{

#define USE_NAME_GENERATOR	// Disable this to NOT use the name-generator system. This will save a fair amount of compilation time and binary size.


extern unsigned int	prand_seed;		// Pseudorandom number seed.

unsigned int	build_version();	// Returns a build version integer.
std::tuple<double, double, double>	calc_beam(int start_x, int start_y, int end_x, int end_y);	// Calculates a beam between two points.
std::string		capitalize_first(std::string str);	// Capitalizes the first letter of a string, if needed.
bool			check_flag(unsigned int flags, unsigned int flag_to_check);	// Checks to see if a flag is set.
void			collapse_list(std::vector<std::string> &vec);	// Collapses a string vector list, combining duplicates.
std::string		comma_list(std::vector<std::string> vec, bool use_and = true);	// Converts a vector to a comma-separated list.
#ifdef USE_NAME_GENERATOR
std::string		consonant();	// Picks a consonant from the table, for forming atoms.
#endif
unsigned int	count_lines(std::string file);	// Counts the number of lines in a file.
unsigned int	count_lines_in_dir(std::string dir, bool recursion = false);	// Counts the number of lines in all files in a directory.
unsigned int	crc32c(unsigned int crc, const unsigned char *buf, size_t len);	// Simple CRC32 implementation.
time_t			date_modified(std::string file);	// Returns the modified date/time of a file, or 0 if the file is not found.
std::string		decode_compressed_string(std::string cb);	// Decodes a compressed string (e.g. 4cab2z becomes ccccabzz).
void			dev_timer_start();	// Starts a timer for debugging/testing purposes.
float			dev_timer_stop();	// Stops the timer and reports the result.
bool			directory_exists(std::string dir);	// Checks if a directory exists.
unsigned int	file_crc32(std::string file);		// Returns the CRC32 checksum of a given file.
bool			file_exists(std::string file);		// Checks if a file exists.
std::vector<std::string>	files_in_dir(std::string directory);	// Returns a list of files in a given directory.
bool			find_and_replace(std::string &input, std::string to_find, std::string to_replace);	// Find and replace one string with another.
std::string		find_between(std::string source, std::string before, std::string after);	// Finds a piece of a string between two other strings.
std::string		ftos(double num);	// Converts a float or double to a string.
unsigned int	fuzz(unsigned int num);	// Fuzzes a number, giving an estimate (e.g. 123456 becoomes 100000).
float			grid_dist(long long x1, long long y1, long long x2, long long y2);	// Determines the difference between two points on a grid.
float			grid_dist(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2);	// As above, but for a three-dimensional grid.
#ifdef POTLUCK_USING_ZLIB
std::string		gz_read_string(const gzFile &file_load);	// Reads an unencrypted string from a zlib binary file, with size markers. Harder than it sounds.
void			gz_write_string(const gzFile &file_save, std::string data);	// Writes a string to a zlib binary save file, with length markers.
void			gz_write_string_clear(const gzFile &file_save, std::string data);	// Writes a clear-text string to a zlib binary file.
#endif
unsigned int	hash(std::string s);	// FNV string hash.
unsigned int	htoi(std::string hex_str);	// Converts a hex string back to an integer.
bool			in_string(std::string input, std::string check);	// Simple way to check if a string is in another string.
std::string		intoroman(unsigned short number);	// Converts a number into Roman numerals.
std::string		intostr_k(unsigned long long num, unsigned int precision);	// Converts an int into a k-style string; for example 10000 becomes 10k.
std::string		intostr_pretty(int num);	// Returns a 'pretty' version of a number in string format, such as "12,345".
std::string		intostr_pretty64(unsigned long long num);	// 64-bit version.
bool			is_file(std::string filename);	// Checks if a filename is a file or directory.
bool			is_odd(unsigned int num);	// Checks if a number is odd.
std::string		itoh(unsigned int num, unsigned char min_len);	// Converts an integer into a hex string.
std::string		itos(long long num);	// Converts an integer to a string.
#ifdef POTLUCK_USING_JSONCPP
Json::Value		load_json(std::string filename);	// Loads an individual JSON file, with error-checking.
#endif
std::vector<std::string>	load_text(std::string filename);	// Loads a text file into a string vector.
void			make_dir(std::string dir);	// Makes a new directory, if it doesn't already exist.
std::string		metadata_to_string(std::unordered_map<std::string, std::string> md);	// Converts a metadata unordered_map into a string.
unsigned int	mixup(unsigned int num, bool big_mix = false);	// Mixes up an integer a little (or a lot).
#ifdef USE_NAME_GENERATOR
void			namegen_init();	// Initializes the random name generator. This function will be called automatically if the namegen system is used without setting up first.
#endif
std::string		number_to_word(unsigned long long number);	// Converts small numbers into words.
std::string		parse_meta(std::string metadata, std::string key);	// Returns the value of a key in specified metadata, if any.
double			perlin(double x, double y, double zoom, double p, int octaves);	// Simple perlin noise generation.
double			perlin_findnoise2(double x, double y);	// Pseudo-random number generator for Perlin noise generation.
double			perlin_interpolate(double a, double b, double x);	// Cosine interpolation.
double			perlin_noise(double x, double y);	// Generate noise for a given coordinate.
unsigned char	perlin_rgb(double x, double y, double zoom, double p, int octaves);	// Wrapper to generate a 0-255 RGB value for the given coord.
std::string		possessive(std::string noun);	// Turns "cat" into "cat's", but "Jeeves" into "Jeeves'".
unsigned int	prand(unsigned int lim);	// Simpler, easily-seedable pseudorandom number generator.
#ifdef USE_NAME_GENERATOR
std::string		random_designation();	// Generates a random designation string, such as AFJ-427.
#endif
std::string		random_line(std::string filename, unsigned int lines);	// Returns a random line from a text file.
#ifdef USE_NAME_GENERATOR
std::string		random_name(bool female);	// Generates a random human name.
std::string		random_word_v1();	// Generates a random word, using the v1 method.
std::string		random_word_v2();	// Generates a random word, using the v2 method.
#endif
void			remove_directory(std::string dir);	// Attempts to delete a directory and everything within.
std::string		right_align_percentage(unsigned char percent);	// Right-aligns a percentage string.
unsigned int	rnd(unsigned int max);	// Returns a random number between 1 and max.
unsigned int	roll(std::string dice);	// 'Rolls' a specified amount of dice.
double			round_to(double num, unsigned int digits);	// Rounds a float to a specified number of digits.
float			round_to_two(float num);	// Rounds a float to two decimal places.
std::string		set_to_string(std::set<unsigned int> the_set);	// Converts a set of integers into a string.
unsigned char	sneaky_xor(unsigned char src, unsigned char mask);	// It's like XOR, but sneakier.
std::string		str_repeat(std::string source, int repeats);	// Repeats a string a number of times.
std::wstring	str_to_wstr(std::string str);	// Converts a string to a wstring.
std::string		str_tolower(std::string str);	// Converts a string to lower-case.
std::string		str_toupper(std::string str);	// Converts a string to upper-case.
std::vector<std::string>	string_explode(std::string str, std::string separator);	// String split/explode function.
std::unordered_map<std::string, std::string>	string_to_metadata(std::string metadata);	// Converts a metadata string into an unordered_map.
void			string_to_set(std::string set_string, std::set<unsigned int> &the_set);	// Converts a string of integers into a set.
std::string		timestamp(bool pretty);	// Returns a timestamp in the format of: 1802152346
void			touch(std::string file);	// Creates an empty placeholder file.
std::string		trim_excess_spaces(std::string source);	// Trims out leading, trailing, and excess (more than one at a time) spaces from a string.
void			txt_to_map(std::string filename, std::map<std::string, std::string> &map, bool process_tags);	// Reads a raw text file into a map.
std::string		uitos(unsigned long long num);	// Unsigned version of itos().
std::vector<std::string>	vector_split(std::string source, unsigned int line_len);	// Splits a string into a vector of strings, to a given line length.
#ifdef USE_NAME_GENERATOR
std::string		vowel();	// Picks a vowel from the table, for forming atoms.
#endif
int				word_count(std::string str, std::string word);	// Returns a count of the amount of times a string is found in a parent string.

}	// namespace potluck
