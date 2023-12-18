#include "../headers/so_long.h"

void	move_d(t_game *game)
{
	int	i;

	i = 0;
}

int	key_handler(int key, t_game *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_free(game);
	}
	if (key == 13)
		move_w(game);
	if (key == 0)
		move_a(game);
	if (key == 1)
		move_s(game);
	if (key == 2)
		move_d(game);
	ft_printf("%s\n", ft_itoa(game->moves));
	return (0);
}