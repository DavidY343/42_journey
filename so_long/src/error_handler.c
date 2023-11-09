
# include "../headers/so_long.h"
# include "../headers/macros.h"

void	msg_error(char *text)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(text, 2);
	exit(1);
}

void	msg_error_param(char *text, char *param)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(text, 2);
	ft_putendl_fd(param, 2);
	exit(1);
}

void	msg_error_map(char *text, char **map)
{
	free_map(map);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(text, 2);
	exit(1);	
}