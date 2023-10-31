/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyanez-m <dyanez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 00:22:02 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/10/31 17:10:39 by dyanez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
}	t_params;

// redirection.c
void	pipex_child(t_params *params);
void	pipex_dad(t_params *params);
void	pipex(t_params *params);

// here_doc.c
void	here_doc_case(t_params *params);
void	here_doc(t_params *params);
void	here_doc_terminal(t_params *params);
// pipex_bonus.c
void	ft_exec(char *param, char **envp);
// pipex_utils.c
void	msg_error(char *text);
char	*path_handler(char *cmd, char **env);
void	ft_free(char **string);
#endif
