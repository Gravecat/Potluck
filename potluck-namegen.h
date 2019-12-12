/* potluck-namegen.h -- Potluck C++ utility library. This optional file contains static strings used by the random name generator.
   RELEASE VERSION 1.0 -- 12th December 2019

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

#ifdef USE_NAME_GENERATOR
std::string			consonant_block = "39c60d31f28g85hjj11k66l34m94n27pq83r88s127t14v23wxx18yz";	// NOT const, as it's decoded and expanded at runtime.
const std::string	vowel_block = "aaaaeeeeeeiiiioooou";
const std::string	pv3_c[41] = { "b", "c", "ch", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "qu", "r", "s", "sh", "t", "th", "v", "w", "y", "sp", "st", "sk", "sc", "pr", "tr", "kr", "cr", "br", "dr", "gr", "fr", "thr", "shr",
					"bl", "fl", "kl", "pl", "sl" };
const std::string	pv3_d[8] = { "aw", "ei", "ow", "ou", "ie", "ea", "ai", "oy" };
const std::string	pv3_e[17] = { "b", "c", "ch", "d", "f", "g", "dg", "l", "m", "n", "p", "r", "s", "t", "th", "v", "z" };
const std::string	pv3_f[40] = { "b", "tch", "d", "ff", "g", "gh", "ck", "ll", "m", "n", "ng", "p", "r", "ss", "sh", "t", "tt", "th", "x", "y", "zz", "rp", "rt", "rk", "rc", "rd", "rb", "rg", "rf", "rth", "rsh", "sp", "st", "sk", "sc",
					"lb", "lf", "lk", "lp", "ls" };
const std::string	pv3_i[5] = { "ex", "in", "un", "re", "de" };
const std::string	pv3_k[19] = { "b", "c", "d", "f", "g", "j", "l", "m", "n", "p", "qu", "r", "s", "t", "v", "sp", "st", "sk", "sc" };
const std::string	pv3_v[5] = { "a", "e", "i", "o", "u" };
const std::string	pv3_x[6] = { "e", "i", "o", "aw", "ow", "oy" };

#define NAMEGEN_FEMALE_NAMES	1000
#define NAMEGEN_MALE_NAMES		1000
#define NAMEGEN_SURNAMES		1996

const std::string names_s[NAMEGEN_SURNAMES] = { "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia",
		"Martinez", "Robinson", "Clark", "Rodriguez", "Lewis", "Walker", "Hall", "Allen", "Young", "Hernandez", "King", "Wright", "Lopez", "Hill", "Scott", "Green", "Adams", "Baker", "Gonzalez", "Nelson", "Carter", "Mitchell",
		"Perez", "Roberts", "Turner", "Phillips", "Campbell", "Parker", "Evans", "Edwards", "Collins", "Stewart", "Sanchez", "Morris", "Rogers", "Reed", "Cook", "Morgan", "Bell", "Murphy", "Bailey", "Rivera", "Cooper", "Richardson",
		"Howard", "Ward", "Torres", "Peterson", "Gray", "Ramirez", "James", "Watson", "Brooks", "Kelly", "Sanders", "Price", "Bennett", "Wood", "Barnes", "Ross", "Henderson", "Coleman", "Jenkins", "Perry", "Powell", "Long",
		"Patterson", "Hughes", "Flores", "Washington", "Butler", "Simmons", "Foster", "Gonzales", "Bryant", "Alexander", "Russell", "Griffin", "Diaz", "Hayes", "Myers", "Ford", "Hamilton", "Graham", "Sullivan", "Wallace", "Woods",
		"Cole", "West", "Jordan", "Owens", "Reynolds", "Fisher", "Ellis", "Harrison", "Gibson", "McDonald", "Cruz", "Marshall", "Ortiz", "Gomez", "Murray", "Freeman", "Wells", "Webb", "Simpson", "Stevens", "Tucker", "Porter", "Hunter",
		"Hicks", "Crawford", "Henry", "Boyd", "Mason", "Morales", "Kennedy", "Warren", "Dixon", "Ramos", "Reyes", "Burns", "Gordon", "Shaw", "Holmes", "Rice", "Robertson", "Hunt", "Black", "Daniels", "Palmer", "Mills", "Nichols",
		"Grant", "Knight", "Ferguson", "Rose", "Stone", "Hawkins", "Dunn", "Perkins", "Hudson", "Spencer", "Gardner", "Stephens", "Payne", "Pierce", "Berry", "Matthews", "Arnold", "Wagner", "Willis", "Watkins", "Olson", "Carroll",
		"Duncan", "Snyder", "Hart", "Cunningham", "Bradley", "Lane", "Andrews", "Ruiz", "Harper", "Riley", "Armstrong", "Carpenter", "Weaver", "Greene", "Lawrence", "Elliott", "Chavez", "Sims", "Austin", "Peters", "Kelley", "Franklin",
		"Lawson", "Fields", "Gutierrez", "Ryan", "Schmidt", "Carr", "Vasquez", "Castillo", "Wheeler", "Chapman", "Oliver", "Montgomery", "Richards", "Williamson", "Johnston", "Banks", "Meyer", "Bishop", "McCoy", "Howell", "Alvarez",
		"Morrison", "Hansen", "Fernandez", "Garza", "Harvey", "Little", "Burton", "Stanley", "Nguyen", "George", "Jacobs", "Reid", "Fuller", "Lynch", "Dean", "Gilbert", "Garrett", "Romero", "Welch", "Larson", "Frazier", "Burke",
		"Hanson", "Mendoza", "Moreno", "Bowman", "Medina", "Fowler", "Brewer", "Hoffman", "Carlson", "Silva", "Pearson", "Holland", "Douglas", "Fleming", "Jensen", "Vargas", "Byrd", "Davidson", "Hopkins", "Terry", "Herrera", "Wade",
		"Soto", "Walters", "Curtis", "Neal", "Caldwell", "Lowe", "Jennings", "Barnett", "Graves", "Jimenez", "Horton", "Shelton", "Barrett", "O'Brien", "Castro", "Sutton", "Gregory", "McKinney", "Lucas", "Miles", "Craig", "Chambers",
		"Holt", "Lambert", "Fletcher", "Watts", "Bates", "Hale", "Rhodes", "Pena", "Beck", "Newman", "Haynes", "McDaniel", "Mendez", "Bush", "Vaughn", "Parks", "Dawson", "Santiago", "Norris", "Hardy", "Love", "Steele", "Curry",
		"Powers", "Schultz", "Barker", "Guzman", "Page", "Munoz", "Ball", "Keller", "Chandler", "Weber", "Leonard", "Walsh", "Lyons", "Ramsey", "Wolfe", "Schneider", "Mullins", "Benson", "Sharp", "Bowen", "Daniel", "Barber",
		"Cummings", "Hines", "Baldwin", "Griffith", "Valdez", "Hubbard", "Salazar", "Reeves", "Warner", "Stevenson", "Burgess", "Santos", "Tate", "Cross", "Garner", "Mann", "Mack", "Moss", "Thornton", "Dennis", "McGee", "Farmer",
		"Delgado", "Aguilar", "Vega", "Glover", "Manning", "Cohen", "Harmon", "Rodgers", "Robbins", "Newton", "Todd", "Blair", "Higgins", "Ingram", "Reese", "Cannon", "Strickland", "Townsend", "Potter", "Goodwin", "Walton", "Rowe",
		"Hampton", "Ortega", "Patton", "Swanson", "Joseph", "Francis", "Goodman", "Yates", "Becker", "Erickson", "Hodges", "Rios", "Conner", "Adkins", "Webster", "Norman", "Malone", "Hammond", "Flowers", "Cobb", "Moody", "Quinn",
		"Blake", "Maxwell", "Pope", "Floyd", "Osborne", "Paul", "McCarthy", "Guerrero", "Lindsey", "Estrada", "Sandoval", "Gibbs", "Tyler", "Gross", "Fitzgerald", "Stokes", "Doyle", "Sherman", "Saunders", "Wise", "Gill", "Alvarado",
		"Greer", "Padilla", "Simon", "Waters", "Nunez", "Ballard", "Schwartz", "McBride", "Houston", "Christensen", "Klein", "Pratt", "Briggs", "Parsons", "McLaughlin", "Zimmerman", "French", "Buchanan", "Moran", "Copeland", "Pittman",
		"Brady", "McCormick", "Holloway", "Brock", "Poole", "Frank", "Logan", "Owen", "Bass", "Marsh", "Drake", "Wong", "Jefferson", "Park", "Morton", "Abbott", "Sparks", "Patrick", "Norton", "Huff", "Clayton", "Massey", "Lloyd",
		"Carson", "Bowers", "Roberson", "Barton", "Tran", "Lamb", "Harrington", "Casey", "Boone", "Cortez", "Clarke", "Mathis", "Singleton", "Wilkins", "Cain", "Bryan", "Underwood", "Hogan", "McKenzie", "Collier", "Luna", "Phelps",
		"McGuire", "Allison", "Bridges", "Wilkerson", "Nash", "Summers", "Atkins", "Wilcox", "Pitts", "Conley", "Marquez", "Burnett", "Richard", "Cochran", "Chase", "Davenport", "Hood", "Gates", "Clay", "Ayala", "Sawyer", "Roman",
		"Vazquez", "Hodge", "Acosta", "Flynn", "Espinoza", "Nicholson", "Monroe", "Wolf", "Morrow", "Kirk", "Randall", "Anthony", "Whitaker", "O'Connor", "Skinner", "Ware", "Molina", "Kirby", "Huffman", "Bradford", "Charles", "Gilmore",
		"Dominguez", "O'Neal", "Bruce", "Lang", "Combs", "Kramer", "Heath", "Hancock", "Gallagher", "Gaines", "Shaffer", "Short", "Wiggins", "Mathews", "McClain", "Fischer", "Wall", "Small", "Melton", "Hensley", "Bond", "Dyer",
		"Cameron", "Grimes", "Contreras", "Christian", "Wyatt", "Baxter", "Snow", "Mosley", "Shepherd", "Larsen", "Hoover", "Beasley", "Glenn", "Petersen", "Whitehead", "Meyers", "Keith", "Garrison", "Vincent", "Shields", "Horn",
		"Savage", "Olsen", "Schroeder", "Hartman", "Woodard", "Mueller", "Kemp", "Booth", "Patel", "Calhoun", "Wiley", "Eaton", "Cline", "Navarro", "Harrell", "Lester", "Humphrey", "Parrish", "Duran", "Hutchinson", "Hess", "Dorsey",
		"Bullock", "Robles", "Beard", "Dalton", "Avila", "Vance", "Rich", "Blackwell", "York", "Johns", "Blankenship", "Trevino", "Salinas", "Campos", "Pruitt", "Moses", "Callahan", "Golden", "Montoya", "Hardin", "Guerra", "McDowell"
		"Carey", "Stafford", "Gallegos", "Henson", "Wilkinson", "Booker", "Merritt", "Miranda", "Atkinson", "Decker", "Hobbs", "Preston", "Tanner", "Knox", "Pacheco", "Stephenson", "Glass", "Rojas", "Serrano", "Marks", "Hickman",
		"English", "Sweeney", "Strong", "Prince", "McClure", "Conway", "Walter", "Roth", "Maynard", "Farrell", "Lowery", "Hurst", "Nixon", "Weiss", "Trujillo", "Ellison", "Sloan", "Juarez", "Winters", "McLean", "Randolph", "Leon",
		"Boyer", "McCall", "Gentry", "Carrillo", "Kent", "Ayers", "Lara", "Shannon", "Sexton", "Pace", "Hull", "LeBlanc", "Browning", "Velasquez", "Leach", "Chang", "House", "Sellers", "Herring", "Noble", "Foley", "Bartlett",
		"Mercado", "Landry", "Durham", "Walls", "Barr", "McKee", "Bauer", "Rivers", "Everett", "Bradshaw", "Pugh", "Velez", "Rush", "Estes", "Dodson", "Morse", "Sheppard", "Weeks", "Camacho", "Bean", "Barron", "Livingston",
		"Middleton", "Spears", "Branch", "Blevins", "Chen", "Kerr", "McConnell", "Hatfield", "Harding", "Ashley", "Solis", "Herman", "Frost", "Giles", "Blackburn", "William", "Pennington", "Woodward", "Finley", "McIntosh", "Koch",
		"Best", "Solomon", "McCullough", "Dudley", "Nolan", "Blanchard", "Rivas", "Brennan", "Mejia", "Kane", "Benton", "Joyce", "Buckley", "Haley", "Valentine", "Maddox", "Russo", "McKnight", "Buck", "Moon", "McMillan", "Crosby",
		"Berg", "Dotson", "Mays", "Roach", "Church", "Chan", "Richmond", "Meadows", "Faulkner", "Knapp", "Kline", "Barry", "Ochoa", "Jacobson", "Avery", "Hendricks", "Horne", "Shepard", "Hebert", "Cherry", "Cardenas", "McIntyre",
		"Whitney", "Waller", "Holman", "Donaldson", "Cantu", "Terrell", "Morin", "Gillespie", "Fuentes", "Tillman", "Sanford", "Bentley", "Peck", "Salas", "Rollins", "Gamble", "Battle", "Santana", "Cabrera", "Cervantes", "Howe",
		"Hinton", "Hurley", "Spence", "Zamora", "Yang", "McNeil", "Suarez", "Case", "Petty", "Gould", "McFarland", "Sampson", "Carver", "Bray", "Rosario", "MacDonald", "Stout", "Hester", "Melendez", "Dillon", "Farley", "Hopper",
		"Galloway", "Potts", "Bernard", "Joyner", "Stein", "Aguirre", "Osborn", "Mercer", "Bender", "Franco", "Rowland", "Sykes", "Benjamin", "Travis", "Pickett", "Crane", "Sears", "Mayo", "Dunlap", "Hayden", "Wilder", "McKay",
		"Coffey", "McCarty", "Ewing", "Cooley", "Vaughan", "Bonner", "Cotton", "Holder", "Stark", "Ferrell", "Cantrell", "Fulton", "Lynn", "Lott", "Calderon", "Rosa", "Pollard", "Hooper", "Burch", "Mullen", "Riddle", "Levy", "David",
		"Duke", "O'Donnell", "Michael", "Britt", "Frederick", "Daugherty", "Berger", "Dillard", "Alston", "Jarvis", "Frye", "Riggs", "Chaney", "Odom", "Duffy", "Fitzpatrick", "Valenzuela", "Merrill", "Mayer", "Alford", "McPherson",
		"Acevedo", "Donovan", "Barrera", "Albert", "Cote", "Reilly", "Compton", "Raymond", "Mooney", "McGowan", "Craft", "Cleveland", "Clemons", "Wynn", "Nielsen", "Baird", "Stanton", "Snider", "Rosales", "Bright", "Witt", "Stuart",
		"Hays", "Holden", "Rutledge", "Kinney", "Clements", "Castaneda", "Slater", "Hahn", "Emerson", "Conrad", "Burks", "Delaney", "Pate", "Lancaster", "Sweet", "Justice", "Tyson", "Sharpe", "Whitfield", "Talley", "Macias", "Irwin",
		"Burris", "Ratliff", "McCray", "Madden", "Beach", "Goff", "Cash", "Bolton", "McFadden", "Levine", "Good", "Byers", "Kirkland", "Kidd", "Workman", "Carney", "Dale", "McLeod", "Holcomb", "England", "Finch", "Head", "Burt",
		"Hendrix", "Sosa", "Haney", "Franks", "Sargent", "Nieves", "Downs", "Rasmussen", "Bird", "Hewitt", "Lindsay", "Foreman", "Valencia", "O'Neil", "Vinson", "Hyde", "Forbes", "Gilliam", "Guthrie", "Wooten", "Huber", "Barlow",
		"Boyle", "McMahon", "Buckner", "Rocha", "Puckett", "Langley", "Knowles", "Cooke", "Velazquez", "Whitley", "Noel", "Vang", "Shea", "Rouse", "Hartley", "Mayfield", "Elder", "Rankin", "Hanna", "Cowan", "Lucero", "Arroyo",
		"Slaughter", "Haas", "Minor", "Kendrick", "Shirley", "Kendall", "Boucher", "Archer", "Boggs", "Dougherty", "Andersen", "Newell", "Crowe", "Wang", "Friedman", "Bland", "Swain", "Holley", "Felix", "Pearce", "Childs",
		"Yarbrough", "Galvan", "Proctor", "Meeks", "Lozano", "Mora", "Rangel", "Bacon", "Schaefer", "Rosado", "Helms", "Boyce", "Goss", "Stinson", "Smart", "Lake", "Ibarra", "Hutchins", "Covington", "Reyna", "Gregg", "Werner",
		"Crowley", "Hatcher", "Mackey", "Bunch", "Womack", "Polk", "Jamison", "Dodd", "Childers", "Camp", "Villa", "Springer", "Mahoney", "Dailey", "Belcher", "Lockhart", "Griggs", "Costa", "Connor", "Brandt", "Winter", "Walden",
		"Moser", "Tracy", "Tatum", "McCann", "Akers", "Lutz", "Pryor", "Orozco", "McAllister", "Lugo", "Davies", "Shoemaker", "Madison", "Rutherford", "Newsome", "Magee", "Chamberlain", "Blanton", "Simms", "Godfrey", "Flanagan",
		"Crum", "Cordova", "Escobar", "Downing", "Sinclair", "Donahue", "Krueger", "McGinnis", "Gore", "Farris", "Webber", "Corbett", "Andrade", "Starr", "Lyon", "Yoder", "Hastings", "McGrath", "Spivey", "Krause", "Harden",
		"Crabtree", "Hollis", "Brandon", "Arrington", "Ervin", "Clifton", "Ritter", "McGhee", "Bolden", "Maloney", "Gagnon", "Dunbar", "Ponce", "Pike", "Mayes", "Heard", "Beatty", "Mobley", "Kimball", "Butts", "Montes", "Herbert",
		"Grady", "Eldridge", "Braun", "Hamm", "Gibbons", "Seymour", "Moyer", "Manley", "Herron", "Plummer", "Elmore", "Cramer", "Gary", "Rucker", "Hilton", "Blue", "Pierson", "Fontenot", "Field", "Rubio", "Grace", "Goldstein",
		"Elkins", "Wills", "Novak", "John", "Hickey", "Worley", "Gorman", "Katz", "Dickinson", "Broussard", "Fritz", "Woodruff", "Crow", "Christopher", "Britton", "Forrest", "Nance", "Lehman", "Bingham", "Zuniga", "Whaley", "Shafer",
		"Coffman", "Steward", "Neely", "Numbers", "Mata", "Manuel", "Davila", "McCabe", "Kessler", "Emery", "Bowling", "Hinkle", "Welsh", "Pagan", "Goldberg", "Goins", "Crouch", "Cuevas", "Quinones", "McDermott", "Hendrickson",
		"Samuels", "Denton", "Bergeron", "Ivey", "Locke", "Haines", "Thurman", "Snell", "Hoskins", "Byrne", "Milton", "Winston", "Arthur", "Arias", "Stanford", "Corbin", "Beltran", "Chappell", "Hurt", "Downey", "Dooley", "Tuttle",
		"Couch", "Payton", "McElroy", "Crockett", "Groves", "Clement", "Leslie", "Cartwright", "Dickey", "McGill", "Dubois", "Muniz", "Erwin", "Self", "Tolbert", "Dempsey", "Cisneros", "Sewell", "Latham", "Garland", "Vigil", "Tapia",
		"Sterling", "Rainey", "Norwood", "Lacy", "Stroud", "Meade", "Amos", "Tipton", "Lord", "Kuhn", "Hilliard", "Bonilla", "Teague", "Courtney", "Gunn", "Greenwood", "Correa", "Reece", "Weston", "Trent", "Pineda", "Phipps", "Frey",
		"Kaiser", "Ames", "Paige", "Gunter", "Schmitt", "Milligan", "Espinosa", "Carlton", "Bowden", "Lowry", "Pritchard", "Costello", "Piper", "Lovell", "Drew", "Sheehan", "Quick", "Hatch", "Dobson", "Singh", "Jeffries", "Sorensen",
		"Meza", "Fink", "Donnelly", "Burrell", "Bruno", "Tomlinson", "Colbert", "Billings", "Ritchie", "Helton", "Sutherland", "Peoples", "McQueen", "Gaston", "Thomason", "McKinley", "Givens", "Crocker", "Vogel", "Robison", "Dunham",
		"Coker", "Swartz", "Keys", "Lilly", "Ladner", "Hannah", "Willard", "Richter", "Hargrove", "Edmonds", "Brantley", "Albright", "Murdock", "Boswell", "Muller", "Quintero", "Padgett", "Kenney", "Daly", "Connolly", "Pierre",
		"Inman", "Quintana", "Lund", "Barnard", "Villegas", "Simons", "Land", "Huggins", "Tidwell", "Sanderson", "Bullard", "McClendon", "Duarte", "Draper", "Meredith", "Marrero", "Dwyer", "Abrams", "Stover", "Goode", "Fraser",
		"Crews", "Bernal", "Smiley", "Godwin", "Fish", "Conklin", "McNeal", "Baca", "Esparza", "Crowder", "Bower", "Nicholas", "Chung", "Brewster", "McNeill", "Dick", "Leal", "Coates", "Raines", "McCain", "McCord", "Miner",
		"Holbrook", "Swift", "Dukes", "Carlisle", "Aldridge", "Ackerman", "Starks", "Ricks", "Holliday", "Ferris", "Hairston", "Sheffield", "Lange", "Fountain", "Marino", "Doss", "Betts", "Kaplan", "Carmichael", "Bloom", "Ruffin",
		"Penn", "Kern", "Bowles", "Sizemore", "Larkin", "Dupree", "Jewell", "Silver", "Seals", "Metcalf", "Hutchison", "Farr", "Castle", "McCauley", "Hankins", "Gustafson", "Deal", "Curran", "Waddell", "Ramey", "Cates", "Pollock",
		"Major", "Irvin", "Cummins", "Messer", "Heller", "DeWitt", "Funk", "Cornett", "Galindo", "Cano", "Hathaway", "Singer", "Pham", "Enriquez", "Aaron", "Salgado", "Pelletier", "Painter", "Wiseman", "Blount", "Hand", "Temple",
		"Houser", "Doherty", "Mead", "McGraw", "Toney", "Swan", "Melvin", "Capps", "Blanco", "Wesley", "Thomson", "McManus", "Fair", "Burkett", "Post", "Gleason", "Rudolph", "Dickens", "Cormier", "Voss", "Rushing", "Rosenberg",
		"Hurd", "Dumas", "Benitez", "Arellano", "Story", "Marin", "Caudill", "Bragg", "Huerta", "Gipson", "Colvin", "Biggs", "Vela", "Platt", "Cassidy", "Tompkins", "McCollum", "Gabriel", "Dolan", "Daley", "Crump", "Street", "Sneed",
		"Kilgore", "Grove", "Grimm", "Davison", "Brunson", "Prater", "Marcum", "Devine", "Kyle", "Dodge", "Stratton", "Rosas", "Choi", "Tripp", "Ledbetter", "Hightower", "Haywood", "Feldman", "Epps", "Yeager", "Posey", "Sylvester",
		"Scruggs", "Cope", "Stubbs", "Richey", "Overton", "Trotter", "Sprague", "Cordero", "Butcher", "Burger", "Stiles", "Burgos", "Woodson", "Horner", "Bassett", "Purcell", "Haskins", "Akins", "Abraham", "Hoyt", "Ziegler",
		"Spaulding", "Hadley", "Grubbs", "Sumner", "Murillo", "Zavala", "Shook", "Lockwood", "Jarrett", "Driscoll", "Dahl", "Thorpe", "Sheridan", "Redmond", "Putnam", "McRae", "Cornell", "Felton", "Romano", "Joiner", "Sadler",
		"Hedrick", "Hager", "Hagen", "Fitch", "Coulter", "Thacker", "Mansfield", "Langston", "Guidry", "Ferreira", "Corley", "Conn", "Rossi", "Lackey", "Cody", "Baez", "Saenz", "McNamara", "Darnell", "Michel", "McMullen", "McKenna",
		"Link", "Engel", "Browne", "Roper", "Peacock", "Eubanks", "Drummond", "Stringer", "Pritchett", "Parham", "Mims", "Landers", "Grayson", "Stacy", "Schafer", "Egan", "Timmons", "O'Hara", "Keen", "Hamlin", "Finn", "Cortes",
		"McNair", "Louis", "Clifford", "Nadeau", "Moseley", "Michaud", "Rosen", "Oakes", "Jeffers", "Calloway", "Beal", "Bautista", "Winn", "Suggs", "Stern", "Stapleton", "Lyles", "Laird", "Montano", "Diamond", "Dawkins", "Roland",
		"Hagan", "Goldman", "Bryson", "Barajas", "Lovett", "Segura", "Metz", "Lockett", "Langford", "Hinson", "Eastman", "Rock", "Hooks", "Woody", "Smallwood", "Shapiro", "Crowell", "Whalen", "Triplett", "Hooker", "Chatman",
		"Aldrich", "Cahill", "Youngblood", "Ybarra", "Stallings", "Sheets", "Samuel", "Reeder", "Person", "Pack", "Lacey", "Connelly", "Bateman", "Winkler", "Wilkes", "Masters", "Hackett", "Granger", "Gillis", "Schmitz", "Sapp",
		"Napier", "Souza", "Lanier", "Weir", "Otero", "Ledford", "Burroughs", "Babcock", "Ventura", "Siegel", "Dugan", "Clinton", "Christie", "Bledsoe", "Atwood", "Wray", "Varner", "Spangler", "Otto", "Anaya", "Staley", "Kraft",
		"Fournier", "Eddy", "Belanger", "Wolff", "Thorne", "Bynum", "Burnette", "Boykin", "Swenson", "Purvis", "Pina", "Khan", "Duvall", "Darby", "Xiong", "Kauffman", "Healy", "Engle", "Corona", "Benoit", "Valle", "Steiner", "Spicer",
		"Shaver", "Randle", "Lundy", "Chin", "Calvert", "Staton", "Neff", "Kearney", "Darden", "Oakley", "Medeiros", "McCracken", "Crenshaw", "Block", "Beaver", "Perdue", "Dill", "Whittaker", "Tobin", "Cornelius", "Washburn",
		"Hogue", "Goodrich", "Easley", "Bravo", "Dennison", "Vera", "Shipley", "Kerns", "Jorgensen", "Crain", "Abel", "Villalobos", "Maurer", "Keene", "Sierra", "Witherspoon", "Staples", "Pettit", "Kincaid", "Eason", "Madrid",
		"Echols", "Lusk", "Stahl", "Currie", "Thayer", "Shultz", "Sherwood", "McNally", "Seay", "North", "Maher", "Kenny", "Hope", "Gagne", "Barrow", "Nava", "Myles", "Moreland", "Honeycutt", "Hearn", "Diggs", "Caron", "Whitten",
		"Westbrook", "Ragland", "Queen", "Munson", "Meier", "Looney", "Kimble", "Jolly", "Hobson", "London", "Goddard", "Culver", "Burr", "Presley", "Connell", "Tovar", "Marcus", "Huddleston", "Hammer", "Ashby", "Salter", "Root",
		"Pendleton", "O'Leary", "Nickerson", "Myrick", "Judd", "Jacobsen", "Elliot", "Bain", "Adair", "Starnes", "Sheldon", "Matos", "Light", "Busby", "Herndon", "Hanley", "Bellamy", "Jack", "Doty", "Bartley", "Yazzie", "Rowell",
		"Parson", "Gifford", "Cullen", "Barnhart", "Talbot", "Mock", "Crandall", "Connors", "Bonds", "Whitt", "Gage", "Bergman", "Addison", "Marion", "Lujan", "Dowdy", "Jernigan", "Bouchard", "Dutton", "Rhoades", "Ouellette",
		"Kiser", "Rubin", "Herrington", "Hare", "Denny", "Blackman", "Babb", "Allred", "Rudd", "Paulson", "Ogden", "Koenig", "Jacob", "Irving", "Geiger", "Begay", "Parra", "Champion", "Lassiter", "Hawk", "Esposito", "Waldron",
		"Vernon", "Ransom", "Prather", "Keenan", "Jean", "Grover", "Chacon", "Sands", "Roark", "Parr", "Mayberry", "Greenberg", "Coley", "Bruner", "Whitman", "Skaggs", "Shipman", "Means", "Leary", "Hutton", "Romo", "Medrano", "Ladd",
		"Kruse", "Friend", "Darling", "Askew", "Valentin", "Schulz", "Alfaro", "Tabor", "Mohr", "Gallo", "Bermudez", "Pereira", "Isaac", "Bliss", "Reaves", "Flint", "Comer", "Boston", "Woodall", "Naquin", "Guevara", "Earl", "DeLong",
		"Carrier", "Pickens", "Brand", "Tilley", "Schaffer", "Read", "Knutson", "Fenton", "Doran", "Vann", "Prescott", "McLain", "Landis", "Corcoran", "Ambrose", "Zapata", "Hemphill", "Faulk", "Call", "Dove", "Aragon", "Whitlock",
		"Trejo", "Tackett", "Shearer", "Saldana", "Hanks", "Gold", "Driver", "McKinnon", "Koehler", "Champagne", "Pool", "Keyes", "Goodson", "Foote", "Early", "Lunsford", "Goldsmith", "Flood", "Winslow", "Sams", "Reagan", "Jameson",
		"Picard", "Janeway", "Sisko", "Griffiths", "Begum", "Hussain", "Ahmed", "Kaur", "Rees", "Tesla", "Shah", "Parry", "Nicholls", "Hodgson", "Robson", "O'Neill", "Akhtar", "Bibi", "Miah", "Burrows", "Parkinson", "Ashton", "Davey",
		"Birch", "Morley", "Humphreys", "Bull", "O'Sullivan", "Brookes", "Schofield", "Houghton", "Rahman", "Coles", "Naylor", "Marsden", "Pickering", "Chadwick", "Howarth", "Gough", "Power", "Allan", "Gardiner", "Turnbull", "Wallis",
		"Mahmood", "Iqbal", "Rowley", "Metcalfe", "Charlton", "Whitehouse", "Storey", "Bevan", "Hargreaves", "Mistry", "Howells", "Parkes", "Lees", "Forster", "Humphries", "Mellor", "Konietzko", "Cifarelli", "Selway", "Durante",
		"Esch", "Naomi", "Rieflin", "Skold", "Vuorinen", "Hietala", "Jansen", "Turunen", "Vanska", "Olzon", "Duff", "Vogt" };

const std::string names_f[NAMEGEN_FEMALE_NAMES] = { "Mary", "Patricia", "Linda", "Barbara", "Elizabeth", "Jennifer", "Maria", "Susan", "Margaret", "Dorothy", "Lisa", "Nancy", "Karen", "Betty", "Helen", "Sandra", "Donna", "Carol",
		"Ruth", "Sharon", "Michelle", "Laura", "Sarah", "Kimberly", "Deborah", "Jessica", "Shirley", "Cynthia", "Angela", "Melissa", "Brenda", "Amy", "Anna", "Rebecca", "Virginia", "Kathleen", "Pamela", "Martha", "Debra", "Amanda",
		"Stephanie", "Carolyn", "Christine", "Marie", "Janet", "Catherine", "Frances", "Ann", "Joyce", "Diane", "Alice", "Julie", "Heather", "Teresa", "Doris", "Gloria", "Evelyn", "Jean", "Cheryl", "Mildred", "Katherine", "Joan",
		"Ashley", "Judith", "Rose", "Janice", "Kelly", "Nicole", "Judy", "Christina", "Kathy", "Theresa", "Beverly", "Denise", "Tammy", "Irene", "Jane", "Lori", "Rachel", "Marilyn", "Andrea", "Kathryn", "Louise", "Sara", "Anne",
		"Jacqueline", "Wanda", "Bonnie", "Julia", "Ruby", "Lois", "Tina", "Phyllis", "Norma", "Paula", "Diana", "Annie", "Lillian", "Emily", "Robin", "Peggy", "Crystal", "Gladys", "Rita", "Dawn", "Connie", "Florence", "Tracy", "Edna",
		"Tiffany", "Carmen", "Rosa", "Cindy", "Grace", "Wendy", "Victoria", "Edith", "Kim", "Sherry", "Sylvia", "Josephine", "Thelma", "Shannon", "Sheila", "Ethel", "Ellen", "Elaine", "Marjorie", "Carrie", "Charlotte", "Monica",
		"Esther", "Pauline", "Emma", "Juanita", "Anita", "Rhonda", "Hazel", "Amber", "Eva", "Debbie", "April", "Leslie", "Clara", "Lucille", "Jamie", "Joanne", "Eleanor", "Valerie", "Danielle", "Megan", "Alicia", "Suzanne", "Michele",
		"Gail", "Bertha", "Darlene", "Veronica", "Jill", "Erin", "Geraldine", "Lauren", "Cathy", "Joann", "Lorraine", "Lynn", "Sally", "Regina", "Erica", "Beatrice", "Dolores", "Bernice", "Audrey", "Yvonne", "Annette", "June",
		"Samantha", "Marion", "Dana", "Stacy", "Ana", "Renee", "Ida", "Vivian", "Roberta", "Holly", "Brittany", "Melanie", "Loretta", "Yolanda", "Jeanette", "Laurie", "Katie", "Kristen", "Vanessa", "Alma", "Sue", "Elsie", "Beth",
		"Jeanne", "Vicki", "Carla", "Tara", "Rosemary", "Eileen", "Terri", "Gertrude", "Lucy", "Tonya", "Ella", "Stacey", "Wilma", "Gina", "Kristin", "Jessie", "Natalie", "Agnes", "Vera", "Willie", "Charlene", "Bessie", "Delores",
		"Melinda", "Pearl", "Arlene", "Maureen", "Colleen", "Allison", "Tamara", "Joy", "Georgia", "Constance", "Lillie", "Claudia", "Jackie", "Marcia", "Tanya", "Nellie", "Minnie", "Marlene", "Heidi", "Glenda", "Lydia", "Viola",
		"Courtney", "Marian", "Stella", "Caroline", "Dora", "Jo", "Vickie", "Mattie", "Terry", "Maxine", "Irma", "Mabel", "Marsha", "Myrtle", "Lena", "Christy", "Deanna", "Patsy", "Hilda", "Gwendolyn", "Jennie", "Nora", "Margie",
		"Nina", "Cassandra", "Leah", "Penny", "Kay", "Priscilla", "Naomi", "Carole", "Brandy", "Olga", "Billie", "Dianne", "Tracey", "Leona", "Jenny", "Felicia", "Sonia", "Miriam", "Velma", "Becky", "Bobbie", "Violet", "Kristina",
		"Toni", "Misty", "Mae", "Shelly", "Daisy", "Ramona", "Sherri", "Erika", "Katrina", "Claire", "Lindsey", "Lindsay", "Geneva", "Guadalupe", "Belinda", "Margarita", "Sheryl", "Cora", "Faye", "Ada", "Natasha", "Sabrina", "Isabel",
		"Marguerite", "Hattie", "Harriet", "Molly", "Cecilia", "Kristi", "Brandi", "Blanche", "Sandy", "Rosie", "Joanna", "Iris", "Eunice", "Angie", "Inez", "Lynda", "Madeline", "Amelia", "Alberta", "Genevieve", "Monique", "Jodi",
		"Janie", "Maggie", "Kayla", "Sonya", "Jan", "Lee", "Kristine", "Candace", "Fannie", "Maryann", "Opal", "Alison", "Yvette", "Melody", "Luz", "Susie", "Olivia", "Flora", "Shelley", "Kristy", "Mamie", "Lula", "Lola", "Verna",
		"Beulah", "Antoinette", "Candice", "Juana", "Jeannette", "Pam", "Kelli", "Hannah", "Whitney", "Bridget", "Karla", "Celia", "Latoya", "Patty", "Shelia", "Gayle", "Della", "Vicky", "Lynne", "Sheri", "Marianne", "Kara",
		"Jacquelyn", "Erma", "Blanca", "Myra", "Leticia", "Pat", "Krista", "Roxanne", "Angelica", "Johnnie", "Robyn", "Francis", "Adrienne", "Rosalie", "Alexandra", "Brooke", "Bethany", "Sadie", "Bernadette", "Traci", "Jody",
		"Kendra", "Jasmine", "Nichole", "Rachael", "Chelsea", "Mable", "Ernestine", "Muriel", "Marcella", "Elena", "Krystal", "Angelina", "Nadine", "Kari", "Estelle", "Dianna", "Paulette", "Lora", "Mona", "Doreen", "Rosemarie",
		"Angel", "Desiree", "Antonia", "Hope", "Ginger", "Janis", "Betsy", "Christie", "Freda", "Mercedes", "Meredith", "Lynette", "Teri", "Cristina", "Eula", "Leigh", "Meghan", "Sophia", "Eloise", "Rochelle", "Gretchen", "Cecelia",
		"Raquel", "Henrietta", "Alyssa", "Jana", "Kelley", "Gwen", "Kerry", "Jenna", "Tricia", "Laverne", "Olive", "Alexis", "Tasha", "Silvia", "Elvira", "Casey", "Delia", "Sophie", "Kate", "Patti", "Lorena", "Kellie", "Sonja",
		"Lila", "Lana", "Darla", "May", "Mindy", "Essie", "Mandy", "Lorene", "Elsa", "Josefina", "Jeannie", "Miranda", "Dixie", "Lucia", "Marta", "Faith", "Lela", "Johanna", "Shari", "Camille", "Tami", "Shawna", "Elisa", "Ebony",
		"Melba", "Ora", "Nettie", "Tabitha", "Ollie", "Jaime", "Winifred", "Kristie", "Marina", "Alisha", "Aimee", "Rena", "Myrna", "Marla", "Tammie", "Latasha", "Bonita", "Patrice", "Ronda", "Sherrie", "Addie", "Francine", "Deloris",
		"Stacie", "Adriana", "Cheri", "Shelby", "Abigail", "Celeste", "Jewel", "Cara", "Adele", "Rebekah", "Lucinda", "Dorthy", "Chris", "Effie", "Trina", "Reba", "Shawn", "Sallie", "Aurora", "Lenora", "Etta", "Lottie", "Kerri",
		"Trisha", "Nikki", "Estella", "Francisca", "Josie", "Tracie", "Marissa", "Karin", "Brittney", "Janelle", "Lourdes", "Laurel", "Helene", "Fern", "Elva", "Corinne", "Kelsey", "Ina", "Bettie", "Elisabeth", "Aida", "Caitlin",
		"Ingrid", "Iva", "Eugenia", "Christa", "Goldie", "Cassie", "Maude", "Jenifer", "Therese", "Frankie", "Dena", "Lorna", "Janette", "Latonya", "Candy", "Morgan", "Consuelo", "Tamika", "Rosetta", "Debora", "Cherie", "Polly",
		"Dina", "Jewell", "Fay", "Jillian", "Dorothea", "Nell", "Trudy", "Esperanza", "Patrica", "Kimberley", "Shanna", "Helena", "Carolina", "Cleo", "Stefanie", "Rosario", "Ola", "Janine", "Mollie", "Lupe", "Alisa", "Lou", "Maribel",
		"Susanne", "Bette", "Susana", "Elise", "Cecile", "Isabelle", "Lesley", "Jocelyn", "Paige", "Joni", "Rachelle", "Leola", "Daphne", "Alta", "Ester", "Petra", "Graciela", "Imogene", "Jolene", "Keisha", "Lacey", "Glenna",
		"Gabriela", "Keri", "Ursula", "Lizzie", "Kirsten", "Shana", "Adeline", "Mayra", "Jayne", "Jaclyn", "Gracie", "Sondra", "Carmela", "Marisa", "Rosalind", "Charity", "Tonia", "Beatriz", "Marisol", "Clarice", "Jeanine", "Sheena",
		"Angeline", "Frieda", "Lily", "Robbie", "Shauna", "Millie", "Claudette", "Cathleen", "Angelia", "Gabrielle", "Autumn", "Katharine", "Summer", "Jodie", "Staci", "Lea", "Christi", "Jimmie", "Justine", "Elma", "Luella",
		"Margret", "Dominique", "Socorro", "Rene", "Martina", "Margo", "Mavis", "Callie", "Bobbi", "Maritza", "Lucile", "Leanne", "Jeannine", "Deana", "Aileen", "Lorie", "Ladonna", "Willa", "Manuela", "Gale", "Selma", "Dolly",
		"Sybil", "Abby", "Lara", "Dale", "Ivy", "Dee", "Winnie", "Marcy", "Luisa", "Jeri", "Magdalena", "Ofelia", "Meagan", "Audra", "Matilda", "Leila", "Cornelia", "Bianca", "Simone", "Bettye", "Randi", "Virgie", "Latisha", "Barbra",
		"Georgina", "Eliza", "Leann", "Bridgette", "Rhoda", "Haley", "Adela", "Nola", "Bernadine", "Flossie", "Ila", "Greta", "Ruthie", "Nelda", "Minerva", "Lilly", "Terrie", "Letha", "Hilary", "Estela", "Valarie", "Brianna",
		"Rosalyn", "Earline", "Catalina", "Ava", "Mia", "Clarissa", "Lidia", "Corrine", "Alexandria", "Concepcion", "Tia", "Sharron", "Rae", "Dona", "Ericka", "Jami", "Elnora", "Chandra", "Lenore", "Neva", "Marylou", "Melisa",
		"Tabatha", "Serena", "Avis", "Allie", "Sofia", "Jeanie", "Odessa", "Nannie", "Harriett", "Loraine", "Penelope", "Milagros", "Emilia", "Benita", "Allyson", "Ashlee", "Tania", "Tommie", "Esmeralda", "Karina", "Eve", "Pearlie",
		"Zelma", "Malinda", "Noreen", "Tameka", "Saundra", "Hillary", "Amie", "Althea", "Rosalinda", "Jordan", "Lilia", "Alana", "Gay", "Clare", "Alejandra", "Elinor", "Michael", "Lorrie", "Jerri", "Darcy", "Earnestine", "Carmella",
		"Taylor", "Noemi", "Marcie", "Liza", "Annabelle", "Louisa", "Earlene", "Mallory", "Carlene", "Nita", "Selena", "Tanisha", "Katy", "Julianne", "John", "Lakisha", "Edwina", "Maricela", "Margery", "Kenya", "Dollie", "Roxie",
		"Roslyn", "Kathrine", "Nanette", "Charmaine", "Lavonne", "Ilene", "Kris", "Tammi", "Suzette", "Corine", "Kaye", "Jerry", "Merle", "Chrystal", "Lina", "Deanne", "Lilian", "Juliana", "Aline", "Luann", "Kasey", "Maryanne",
		"Evangeline", "Colette", "Melva", "Lawanda", "Yesenia", "Nadia", "Madge", "Kathie", "Eddie", "Ophelia", "Valeria", "Nona", "Mitzi", "Mari", "Georgette", "Claudine", "Fran", "Alissa", "Roseann", "Lakeisha", "Susanna", "Reva",
		"Deidre", "Chasity", "Sheree", "Carly", "James", "Elvia", "Alyce", "Deirdre", "Gena", "Briana", "Araceli", "Katelyn", "Rosanne", "Wendi", "Tessa", "Berta", "Marva", "Imelda", "Marietta", "Marci", "Leonor", "Arline", "Sasha",
		"Madelyn", "Janna", "Juliette", "Deena", "Aurelia", "Josefa", "Augusta", "Liliana", "Young", "Christian", "Lessie", "Amalia", "Savannah", "Anastasia", "Vilma", "Natalia", "Rosella", "Lynnette", "Corina", "Alfreda", "Leanna",
		"Carey", "Amparo", "Coleen", "Tamra", "Aisha", "Wilda", "Karyn", "Cherry", "Queen", "Maura", "Mai", "Evangelina", "Rosanna", "Hallie", "Erna", "Enid", "Mariana", "Lacy", "Juliet", "Jacklyn", "Freida", "Madeleine", "Mara",
		"Hester", "Cathryn", "Lelia", "Casandra", "Bridgett", "Angelita", "Jannie", "Dionne", "Annmarie", "Katina", "Beryl", "Phoebe", "Millicent", "Katheryn", "Diann", "Carissa", "Maryellen", "Liz", "Lauri", "Helga", "Gilda",
		"Adrian", "Rhea", "Marquita", "Hollie", "Tisha", "Tamera", "Angelique", "Francesca", "Britney", "Kaitlin", "Lolita", "Florine", "Rowena", "Reyna", "Twila", "Fanny", "Janell", "Ines", "Concetta", "Bertie", "Alba", "Brigitte",
		"Alyson", "Vonda", "Pansy", "Elba", "Noelle", "Letitia", "Kitty", "Deann", "Brandie", "Louella", "Leta", "Felecia", "Sharlene", "Lesa", "Beverley", "Robert", "Isabella", "Herminia", "Terra", "Celina" };

const std::string names_m[NAMEGEN_MALE_NAMES] = { "James", "John", "Robert", "Michael", "William", "David", "Richard", "Charles", "Joseph", "Thomas", "Christopher", "Daniel", "Paul", "Mark", "Donald", "George", "Kenneth", "Steven",
		"Edward", "Brian", "Ronald", "Anthony", "Kevin", "Jason", "Matthew", "Gary", "Timothy", "Jose", "Larry", "Jeffrey", "Frank", "Scott", "Eric", "Stephen", "Andrew", "Raymond", "Gregory", "Joshua", "Jerry", "Dennis", "Walter",
		"Patrick", "Peter", "Harold", "Douglas", "Henry", "Carl", "Arthur", "Ryan", "Roger", "Joe", "Juan", "Jack", "Albert", "Jonathan", "Justin", "Terry", "Gerald", "Keith", "Samuel", "Willie", "Ralph", "Lawrence", "Nicholas", "Roy",
		"Benjamin", "Bruce", "Brandon", "Adam", "Harry", "Fred", "Wayne", "Billy", "Steve", "Louis", "Jeremy", "Aaron", "Randy", "Howard", "Eugene", "Carlos", "Russell", "Bobby", "Victor", "Martin", "Ernest", "Phillip", "Todd",
		"Jesse", "Craig", "Alan", "Shawn", "Clarence", "Sean", "Philip", "Chris", "Johnny", "Earl", "Jimmy", "Antonio", "Danny", "Bryan", "Tony", "Luis", "Mike", "Stanley", "Leonard", "Nathan", "Dale", "Manuel", "Rodney", "Curtis",
		"Norman", "Allen", "Marvin", "Vincent", "Glenn", "Jeffery", "Travis", "Jeff", "Chad", "Jacob", "Lee", "Melvin", "Alfred", "Kyle", "Francis", "Bradley", "Jesus", "Herbert", "Frederick", "Ray", "Joel", "Edwin", "Don", "Eddie",
		"Ricky", "Troy", "Randall", "Barry", "Alexander", "Bernard", "Mario", "Leroy", "Francisco", "Marcus", "Micheal", "Theodore", "Clifford", "Miguel", "Oscar", "Jay", "Jim", "Tom", "Calvin", "Alex", "Jon", "Ronnie", "Bill",
		"Lloyd", "Tommy", "Leon", "Derek", "Warren", "Darrell", "Jerome", "Floyd", "Leo", "Alvin", "Tim", "Wesley", "Gordon", "Dean", "Greg", "Jorge", "Dustin", "Pedro", "Derrick", "Dan", "Lewis", "Zachary", "Corey", "Herman",
		"Maurice", "Vernon", "Roberto", "Clyde", "Glen", "Hector", "Shane", "Ricardo", "Sam", "Rick", "Lester", "Brent", "Ramon", "Charlie", "Tyler", "Gilbert", "Gene", "Marc", "Reginald", "Ruben", "Brett", "Angel", "Nathaniel",
		"Rafael", "Leslie", "Edgar", "Milton", "Raul", "Ben", "Chester", "Cecil", "Duane", "Franklin", "Andre", "Elmer", "Brad", "Gabriel", "Ron", "Mitchell", "Roland", "Arnold", "Harvey", "Jared", "Adrian", "Karl", "Cory", "Claude",
		"Erik", "Darryl", "Jamie", "Neil", "Jessie", "Christian", "Javier", "Fernando", "Clinton", "Ted", "Mathew", "Tyrone", "Darren", "Lonnie", "Lance", "Cody", "Julio", "Kelly", "Kurt", "Allan", "Nelson", "Guy", "Clayton", "Hugh",
		"Max", "Dwayne", "Dwight", "Armando", "Felix", "Jimmie", "Everett", "Jordan", "Ian", "Wallace", "Ken", "Bob", "Jaime", "Casey", "Alfredo", "Alberto", "Dave", "Ivan", "Johnnie", "Sidney", "Byron", "Julian", "Isaac", "Morris",
		"Clifton", "Willard", "Daryl", "Ross", "Virgil", "Andy", "Marshall", "Salvador", "Perry", "Kirk", "Sergio", "Marion", "Tracy", "Seth", "Kent", "Terrance", "Rene", "Eduardo", "Terrence", "Enrique", "Freddie", "Wade", "Austin",
		"Stuart", "Fredrick", "Arturo", "Alejandro", "Jackie", "Joey", "Nick", "Luther", "Wendell", "Jeremiah", "Evan", "Julius", "Dana", "Donnie", "Otis", "Shannon", "Trevor", "Oliver", "Luke", "Homer", "Gerard", "Doug", "Kenny",
		"Hubert", "Angelo", "Shaun", "Lyle", "Matt", "Lynn", "Alfonso", "Orlando", "Rex", "Carlton", "Ernesto", "Cameron", "Neal", "Pablo", "Lorenzo", "Omar", "Wilbur", "Blake", "Grant", "Horace", "Roderick", "Kerry", "Abraham",
		"Willis", "Rickey", "Jean", "Ira", "Andres", "Cesar", "Johnathan", "Malcolm", "Rudolph", "Damon", "Kelvin", "Rudy", "Preston", "Alton", "Archie", "Marco", "Wm", "Pete", "Randolph", "Garry", "Geoffrey", "Jonathon", "Felipe",
		"Bennie", "Gerardo", "Ed", "Dominic", "Robin", "Loren", "Delbert", "Colin", "Guillermo", "Earnest", "Lucas", "Benny", "Noel", "Spencer", "Rodolfo", "Myron", "Edmund", "Garrett", "Salvatore", "Cedric", "Lowell", "Gregg",
		"Sherman", "Wilson", "Devin", "Sylvester", "Kim", "Israel", "Jermaine", "Forrest", "Wilbert", "Leland", "Simon", "Guadalupe", "Clark", "Irving", "Carroll", "Bryant", "Owen", "Rufus", "Woodrow", "Sammy", "Kristopher", "Mack",
		"Levi", "Marcos", "Gustavo", "Jake", "Lionel", "Marty", "Taylor", "Ellis", "Dallas", "Gilberto", "Clint", "Nicolas", "Laurence", "Ismael", "Orville", "Drew", "Jody", "Ervin", "Dewey", "Al", "Wilfred", "Josh", "Hugo",
		"Ignacio", "Caleb", "Tomas", "Sheldon", "Erick", "Frankie", "Stewart", "Doyle", "Darrel", "Rogelio", "Terence", "Santiago", "Alonzo", "Elias", "Bert", "Elbert", "Ramiro", "Conrad", "Pat", "Noah", "Grady", "Phil", "Cornelius",
		"Lamar", "Rolando", "Clay", "Percy", "Dexter", "Bradford", "Merle", "Darin", "Amos", "Terrell", "Moses", "Irvin", "Saul", "Roman", "Darnell", "Randal", "Tommie", "Timmy", "Darrin", "Winston", "Brendan", "Toby", "Van", "Abel",
		"Dominick", "Boyd", "Courtney", "Jan", "Emilio", "Elijah", "Cary", "Domingo", "Santos", "Aubrey", "Emmett", "Marlon", "Emanuel", "Jerald", "Edmond", "Emil", "Dewayne", "Will", "Otto", "Teddy", "Reynaldo", "Bret", "Morgan",
		"Jess", "Trent", "Humberto", "Emmanuel", "Stephan", "Louie", "Vicente", "Lamont", "Stacy", "Garland", "Miles", "Micah", "Efrain", "Billie", "Logan", "Heath", "Rodger", "Harley", "Demetrius", "Ethan", "Eldon", "Rocky",
		"Pierre", "Junior", "Freddy", "Eli", "Bryce", "Antoine", "Robbie", "Kendall", "Royce", "Sterling", "Mickey", "Chase", "Grover", "Elton", "Cleveland", "Dylan", "Chuck", "Damian", "Reuben", "Stan", "August", "Leonardo",
		"Jasper", "Russel", "Erwin", "Benito", "Hans", "Monte", "Blaine", "Ernie", "Curt", "Quentin", "Agustin", "Murray", "Jamal", "Devon", "Adolfo", "Harrison", "Tyson", "Burton", "Brady", "Elliott", "Wilfredo", "Bart", "Jarrod",
		"Vance", "Denis", "Damien", "Joaquin", "Harlan", "Desmond", "Elliot", "Darwin", "Ashley", "Gregorio", "Buddy", "Xavier", "Kermit", "Roscoe", "Esteban", "Anton", "Solomon", "Scotty", "Norbert", "Elvin", "Williams", "Nolan",
		"Carey", "Rod", "Quinton", "Hal", "Brain", "Rob", "Elwood", "Kendrick", "Darius", "Moises", "Son", "Marlin", "Fidel", "Thaddeus", "Cliff", "Marcel", "Ali", "Jackson", "Raphael", "Bryon", "Armand", "Alvaro", "Jeffry", "Dane",
		"Joesph", "Thurman", "Ned", "Sammie", "Rusty", "Michel", "Monty", "Rory", "Fabian", "Reggie", "Mason", "Graham", "Kris", "Isaiah", "Vaughn", "Gus", "Avery", "Loyd", "Diego", "Alexis", "Adolph", "Norris", "Millard", "Rocco",
		"Gonzalo", "Derick", "Rodrigo", "Gerry", "Stacey", "Carmen", "Wiley", "Rigoberto", "Alphonso", "Ty", "Shelby", "Rickie", "Noe", "Vern", "Bobbie", "Reed", "Jefferson", "Elvis", "Bernardo", "Mauricio", "Hiram", "Donovan",
		"Basil", "Riley", "Ollie", "Nickolas", "Maynard", "Scot", "Vince", "Quincy", "Eddy", "Sebastian", "Federico", "Ulysses", "Heriberto", "Donnell", "Cole", "Denny", "Davis", "Gavin", "Emery", "Ward", "Romeo", "Jayson", "Dion",
		"Dante", "Clement", "Coy", "Odell", "Maxwell", "Jarvis", "Bruno", "Issac", "Mary", "Dudley", "Brock", "Sanford", "Colby", "Carmelo", "Barney", "Nestor", "Hollis", "Stefan", "Donny", "Art", "Linwood", "Beau", "Weldon", "Galen",
		"Isidro", "Truman", "Delmar", "Johnathon", "Silas", "Frederic", "Dick", "Kirby", "Irwin", "Cruz", "Merlin", "Merrill", "Charley", "Marcelino", "Lane", "Harris", "Cleo", "Carlo", "Trenton", "Kurtis", "Hunter", "Aurelio",
		"Winfred", "Vito", "Collin", "Denver", "Carter", "Leonel", "Emory", "Pasquale", "Mohammad", "Mariano", "Danial", "Blair", "Landon", "Dirk", "Branden", "Adan", "Numbers", "Clair", "Buford", "German", "Bernie", "Wilmer", "Joan",
		"Emerson", "Zachery", "Fletcher", "Jacques", "Errol", "Dalton", "Monroe", "Josue", "Dominique", "Edwardo", "Booker", "Wilford", "Sonny", "Shelton", "Carson", "Theron", "Raymundo", "Daren", "Tristan", "Houston", "Robby",
		"Lincoln", "Jame", "Genaro", "Gale", "Bennett", "Octavio", "Cornell", "Laverne", "Arron", "Antony", "Herschel", "Alva", "Giovanni", "Garth", "Cyrus", "Cyril", "Ronny", "Stevie", "Lon", "Freeman", "Erin", "Duncan", "Kennith",
		"Carmine", "Augustine", "Young", "Erich", "Chadwick", "Wilburn", "Russ", "Reid", "Myles", "Anderson", "Morton", "Jonas", "Forest", "Mitchel", "Mervin", "Zane", "Rich", "Jamel", "Lazaro", "Alphonse", "Randell", "Major",
		"Johnie", "Jarrett", "Brooks", "Ariel", "Abdul", "Dusty", "Luciano", "Lindsey", "Tracey", "Seymour", "Scottie", "Eugenio", "Mohammed", "Sandy", "Valentin", "Chance", "Arnulfo", "Lucien", "Ferdinand", "Thad", "Ezra", "Sydney",
		"Aldo", "Rubin", "Royal", "Mitch", "Earle", "Abe", "Wyatt", "Marquis", "Lanny", "Kareem", "Jamar", "Boris", "Isiah", "Emile", "Elmo", "Aron", "Leopoldo", "Everette", "Josef", "Gail", "Eloy", "Dorian", "Rodrick", "Reinaldo",
		"Lucio", "Jerrod", "Weston", "Hershel", "Barton", "Parker", "Lemuel", "Lavern", "Burt", "Jules", "Gil", "Eliseo", "Ahmad", "Nigel", "Efren", "Antwan", "Alden", "Margarito", "Coleman", "Refugio", "Dino", "Osvaldo", "Les",
		"Deandre", "Normand", "Kieth", "Ivory", "Andrea", "Trey", "Norberto", "Napoleon", "Jerold", "Fritz", "Rosendo", "Milford", "Sang", "Deon", "Christoper", "Alfonzo", "Lyman", "Josiah", "Brant", "Wilton", "Rico", "Jamaal",
		"Dewitt", "Carol", "Brenton", "Yong", "Olin", "Foster", "Faustino", "Claudio", "Judson", "Gino", "Edgardo", "Berry", "Alec", "Tanner", "Jarred", "Donn", "Trinidad", "Tad", "Shirley", "Prince", "Porfirio", "Odis", "Maria",
		"Lenard", "Chauncey", "Chang", "Tod", "Mel", "Marcelo", "Kory", "Augustus", "Keven", "Hilario", "Bud", "Sal", "Rosario", "Orval", "Mauro", "Dannie", "Zachariah", "Olen", "Anibal", "Milo", "Jed", "Frances", "Thanh", "Dillon",
		"Amado", "Newton", "Connie", "Lenny", "Tory", "Richie", "Lupe", "Horacio", "Brice", "Mohamed", "Delmer", "Dario", "Reyes", "Dee", "Mac", "Jonah", "Jerrold", "Robt", "Hank", "Sung", "Rupert", "Rolland", "Kenton", "Damion",
		"Chi", "Antone", "Waldo", "Fredric", "Bradly", "Quinn", "Kip", "Burl", "Walker", "Tyree", "Jefferey", "Ahmed", "Stanford", "Saed" };
#endif	// USE_NAME_GENERATOR
