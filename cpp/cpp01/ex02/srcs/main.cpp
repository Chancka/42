#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "___________ADDRESSE______________" << std::endl;
	std::cout << "Addresse de la string en memoire : " << &str << std::endl;
	std::cout << "Addresse stocke dans stringPTR : " << &stringPTR << std::endl;
	std::cout << "Adresse stocke dans stringREF : " << &stringREF << std::endl;
	std::cout << "___________VALEUR________________" << std::endl;
	std::cout << "Valeur de la string : " << str << std::endl;
	std::cout << "Valeur pointe par stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur pointe par stringREF : " << stringREF << std::endl;
}
