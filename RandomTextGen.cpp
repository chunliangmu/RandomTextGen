#include<random>
#include<ctime>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdbool>

/*
class RandChar
{
private:
	std::default_random_engine e;
	
	RandChar() {
		this->e.seed(static_cast<unsigned int>(std::time(NULL)));
	}
	~RandChar() { }
};
*/

char get_rand_char(bool readable = true) {
	static std::default_random_engine e(static_cast<unsigned int>(std::time(NULL)));
	static std::uniform_int_distribution<int> d_lim(32, 126);
	static std::uniform_int_distribution<int> d_all(0, 255);
	char ans;
	if (readable) ans = static_cast<char>(d_lim(e));
	else ans = static_cast<char>(d_all(e));
	return ans;
}


char get_rand_char(std::string library) {
	static std::default_random_engine e(static_cast<unsigned int>(std::time(NULL)));
	std::uniform_int_distribution<int> d_lib(0, library.size() - 1);
	return library[d_lib(e)];
}


std::string get_rand_string(std::size_t length = 12, bool print_it = false) {
	std::size_t i = 0;
	std::string txt;
	char c;
	while (i < length) {
		c = get_rand_char(true);
		if (true
			//|| ('0' < c && c < '9')
			//|| ('a' < c && c < 'z')
			//|| ('A' < c && c < 'Z')
			)
		{
			txt.push_back(c);
			//std::cout << c;
			i++;
		}
	}
	if (print_it) std::cout << txt << std::endl;
	return txt;
}


std::string get_rand_string(std::string library, std::size_t length = 12, bool print_it = false) {
	static std::default_random_engine e(static_cast<unsigned int>(std::time(NULL)));
	std::uniform_int_distribution<int> d_lib(0, library.size() - 1);
	std::string txt;
	char c;
	for (std::size_t i = 0; i < length; i++) {
		txt.push_back(library[d_lib(e)]);
	}
	if (print_it) std::cout << txt << std::endl;
	return txt;
}


int create_rand_file(
	std::string outfilename,
	std::size_t size_min = 1024u, std::size_t size_max = 2048u,
	bool readable = true)
{
	static std::default_random_engine e(static_cast<unsigned int>(std::time(NULL)));
	static std::uniform_int_distribution<std::size_t> d(size_min, size_max);
	std::size_t outfilesize = d(e);
	std::ofstream outfile;
	outfile.open(outfilename, std::ios::out);
	if (outfile.is_open()) {
		std::cout << "Openning/Overwriting file:  \"" + outfilename + "\""
			<< " with " << outfilesize << " characters." << std::endl;
		for (std::size_t i = 0; i < outfilesize; i++) {
			outfile << get_rand_char(readable);
		}
		outfile.close();
	}
	else {
		std::cout << "Error: failed to open file:  \"" + outfilename + "\"" << std::endl;
	}

	return 0;
}


int main() {

	const unsigned int filesize_min = 4 * 1024 * 1024;	// MB
	const unsigned int filesize_max = filesize_min * 2;
	const std::string txt_delimiter(79, '-');
	std::string char_library;
	char txt_exit;
	for (char i = 'A'; i <= 'Z'; i++) char_library.push_back(i);
	for (char i = 'a'; i <= 'z'; i++) char_library.push_back(i);
	for (char i = '0'; i <= '9'; i++) char_library.push_back(i);
	char_library += "!\"#$%&'()*+,-./:;=>?@[\\]^_`{|}~";

	std::cout << "Characters library:\n" << char_library << std::endl;
	std::cout << txt_delimiter << std::endl;

	get_rand_string(char_library, 16, true);
	//create_rand_file("temp_RandomChars.txt", filesize_min, filesize_max, true);
	//create_rand_file("temp_RandomChars.txt", filesize_min, filesize_max, false);

	std::cout << txt_delimiter << std::endl;
	std::cout << "Press any key to exit...";
	std::getchar();
	return 0;
}