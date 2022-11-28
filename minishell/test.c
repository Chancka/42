#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	DIR				*dirp;
	struct dirent	*dir_content;
	char			*tab[255];

	dirp = opendir(".");
	if (!dirp)
		return (0);
	dir_content = readdir(dirp);
	int	i = 0;
	while (dir_content)
	{
		tab[i] = dir_content->d_name;
		printf("%s\n", tab[i]);
		i++;
		dir_content = readdir(dirp);
	}
	closedir(dirp);
}
