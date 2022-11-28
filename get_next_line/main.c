#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void)
{
	// find fd
	int fd = open("get_next_line.c", O_RDONLY);
	char *str;
	int i = 0;
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
}

