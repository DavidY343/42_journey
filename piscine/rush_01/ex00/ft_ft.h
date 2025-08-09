/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalah-d <lsalah-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:32:05 by lsalah-d          #+#    #+#             */
/*   Updated: 2023/08/27 19:37:03 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FT_H
# define FT_FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_node
{
	unsigned int	key;
	char			*value;
	struct s_node	*next;
}	t_node;

int					ft_strlen(char *str);
char				*ft_strdup(char *src);
unsigned int		ft_atoi(char *str);
void				ft_putstr(char *str, int op);

#endif
