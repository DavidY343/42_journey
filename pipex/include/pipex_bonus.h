/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:02 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/25 15:42:13 by root             ###   ########.fr       */
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
# include "../libft/get_next_line/get_next_line.h"

typedef struct s_params
{
	int		fd[2];
	pid_t	pid;
	int		in_fd;
	int		out_fd;
	int		i;
	int		p0;
	char	**argv;
	char	**envp;
	int		argc;
} t_params;

void	msg_error(char *text);
char	*path_handler(char *cmd, char **env);
void	ft_free(char **string);
#endif
