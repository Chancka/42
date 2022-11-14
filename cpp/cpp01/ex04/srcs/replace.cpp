#include "../includes/replace.hpp"

void	replace(std::string filename, std::string s1, std::string s2)
{
	std::string		readLine;
	std::fstream	file;
	std::ofstream	fileReplace;
	std::size_t		found = 0;
	std::string		name_replace;

	name_replace = filename + ".replace";
	file.open(filename.c_str());
	fileReplace.open(name_replace.c_str());
	if (s1 == s2)
	{
		while (std::getline(file, readLine))
			fileReplace << readLine << std::endl;
		return ;
	}
	while(std::getline(file, readLine))
	{
		found = readLine.find(s1);
		while (found != std::string::npos)
		{
			readLine = readLine.substr(0, found) + s2 + readLine.substr(found + s1.length());
			found = readLine.find(s1);
		}
		fileReplace << readLine << std::endl;
	}
	file.close();
	fileReplace.close();
}
