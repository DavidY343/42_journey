/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:02 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/16 11:52:08 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H_BONUS
# define PIPEX_H_BONUS

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <errno.h>
# include "../libft/ft_printf/ft_printf.h"

void	msg_error(char *text);
char	*path_handler(char *cmd, char **env);
void	ft_free(char **string);
#endif