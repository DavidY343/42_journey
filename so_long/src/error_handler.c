
# include "../headers/so_long.h"
# include "../headers/macros.h"

void	msg_error(char *text)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(text, 2);
	exit(1);
}