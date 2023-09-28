#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd = open ("1char.txt", O_RDONLY);
	int i = 0;
	while (i < 2)
	{
		char *buffer = get_next_line(fd);
		if (!buffer)
			printf("f\n");
		else
			printf("%s\n", buffer);
		free(buffer);
		i++;
	}
	return (0);
}