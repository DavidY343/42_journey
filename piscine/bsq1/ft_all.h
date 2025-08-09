/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:20:42 by jonjimen          #+#    #+#             */
/*   Updated: 2023/08/30 13:02:47 by jonjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALL_H
# define FT_ALL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void	rel_hd(int num, char **hd);
void	free_memory(char **matrix, char *buf, char *hd, int num);
void	print_sol(char **matrix, int row, int col);
void	translate_sol(char **matrix, int row, int col, char *buffer);
char	*get_header(char *buffer);
int		check_header(char **header);
int		check_matrix( char *buf, char *hd, int num);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*next_line(char *buffer);

#endif
