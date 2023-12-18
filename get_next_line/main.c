#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
typedef struct s_data
{
	char	**map;
	int		width;
	int		height;
}	t_data;

static void	read_map(int fd, t_data *data)
{
	char	*line;
	char	*map_str;

	line = NULL;
	map_str = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map_str = ft_strjoin(map_str, line);
		free(line);
	}
	close(fd);
	free(map_str);
}

int	main()
{
	t_data data;
	int fd = open("map.ber", O_RDONLY);
	read_map(fd, &data);
	return (0);
}