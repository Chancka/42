#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i = 1;
	std::string	str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (argv && argv[i])
	{
		str = argv[i];
		int	j = 0;
		while (str[j])
		{
			str[j] = toupper(str[j]);
			j++;
		}
		std::cout << str << std::endl;
		i++;
	}
}
