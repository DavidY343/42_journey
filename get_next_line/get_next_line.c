/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:32:45 by david             #+#    #+#             */
/*   Updated: 2023/09/21 08:56:21 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *preview)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (!(ft_strchr(preview, '\n')) && bytes_read != 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((!(preview) && bytes_read == 0) || bytes_read == -1) // quizas tb para el caso final !preview && bytes_read = 0
		{
			free(buffer);
			free(preview);
			return (0);
		}
		preview = ft_strjoin(preview, buffer);
		free(buffer);
	}
	return (preview);
}

char	*ft_get_line(char *preview)
{
	char    *line;
	int		i;
	
	i = 0;
	while (preview[i] != '\0' && preview[i] != '\n')
		i++;
	if (preview[i] == '\0')
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (preview[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = -1;
	while (preview[++i] != '\0' && preview[i] != '\n')
		line[i] = preview[i];
	if (preview[i] == '\n')
	{	
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_situation_handler(char *preview)
{
	int		i;
	int		j;
	char	*leftovers;
	int		len_preview;

	i = 0;
	j = 0;
	len_preview = ft_strlen(preview);
	while (preview[i] != '\0' && preview[i] != '\n')
		i++;
	if (preview[i] == '\0')
	{
		free(preview);
		return (0);
	}
	leftovers = (char *)malloc(sizeof(char) * (len_preview - i + 1));
	while(preview[++i] != '\0')
		leftovers[j++] = preview[i];
	leftovers[j] = '\0';
	free(preview);
	return (leftovers);

}

char	*get_next_line(int fd)
{
	static char	*preview;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    preview = ft_read_fd(fd, preview);
	if (!preview)
		return (0);
	line = ft_get_line(preview);
	if (!line)
		return (0);
	preview = ft_situation_handler(preview);
	return (line);
}
