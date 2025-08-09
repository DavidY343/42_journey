/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:24:15 by jonjimen          #+#    #+#             */
/*   Updated: 2023/08/30 16:40:23 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_all.h"

char	*read_stdin(void);

char	**get_matrix(char *buffer, int num, int len_total)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	buffer = next_line(buffer);
	matrix = (char **)malloc(sizeof(char *) * num);
	while (i < num)
	{
		j = 0;
		matrix[i] = (char *)malloc(sizeof(char) * len_total / num);
		while (j < (len_total / num))
		{
			if (*buffer != '\n')
			{
				matrix[i][j] = *buffer;
				j++;
			}
			buffer++;
		}
		i++;
	}
	return (matrix);
}

int	len_buffer(char *filename)
{
	int		file;
	char	let;
	int		len;

	len = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	while (read(file, &let, 1) > 0)
		len++;
	close(file);
	return (len + 1);
}

char	*get_buffer(char *filename)
{
	int		file;
	char	*buffer;
	int		i;
	char	let;
	int		len;

	i = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	len = len_buffer(filename);
	if (len == 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * len);
	while (read(file, &let, 1) > 0)
	{
		buffer[i] = let;
		i++;
	}
	buffer[i] = '\0';
	close(file);
	return (buffer);
}

int	solve_matrix(char *buffer)
{
	int		len_total;
	int		num;
	char	*header;
	char	**matrix;

	header = get_header(buffer);
	num = check_header(&header);
	len_total = check_matrix(buffer, header, num);
	if (len_total == 0)
	{
		rel_hd(num, &header);
		free(buffer);
		free(header);
		return (-1);
	}
	matrix = get_matrix(buffer, num, len_total);
	translate_sol(matrix, num, len_total / num, header);
	print_sol(matrix, num, len_total / num);
	rel_hd(num, &header);
	free_memory(matrix, buffer, header, num);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*buffer;

	if (argc == 1)
	{
		buffer = read_stdin();
		if (solve_matrix(buffer) == -1)
			ft_putstr("map error\n");
	}
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			ft_putstr("map error\n");
		else
		{
			buffer = get_buffer(argv[i]);
			if (buffer == 0)
				ft_putstr("map error\n");
			else if (solve_matrix(buffer) == -1)
				ft_putstr("map error\n");
		}
		i++;
	}
	return (0);
}
