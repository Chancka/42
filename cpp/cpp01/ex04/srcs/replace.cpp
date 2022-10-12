#include "../includes/replace.hpp"

void	replace(std::string filename, std::string s1, std::string s2)
{
	std::string	readLine;
	std::ifstream	file (filename);
	std::ofstream	fileReplace (filename + ".replace");
	std::size_t		found = 0;

	while(std::getline(file, readLine))
	{
		found = readLine.find(s1);
		if (found != std::string::npos)
			readLine = readLine.substr(0, found) + s2 + readLine.substr(found + s1.length());
		fileReplace << readLine << std::endl;
	}
}
