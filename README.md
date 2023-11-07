# 42_swap
IMPORTANTE EL OTRO DIA PROBE EL SO_LONG CON MI FT_PRINTF Y ME DIO SEGFAULT ADJUNTO CODIGO
int	main(int argc, char **argv)
{

	if (argc != 2)
		msg_error("You must run it with only one parameter!\n");
	int result = ft_strrncmp(argv[1], ".ber", 4);
	ft_printf("%s\n", result);
	if (result != 0)
		msg_error("You must include a ber file!\n");
	ft_putstr_fd("todo guud\n", 2);
	return (0);
}
--Lista
1.- 42evaluators que es
2.- Coaliciones y squads todavia puedo hacer una?
3.- hacer setup de vscoode para que funcione como vim
4.- francinnete, paco y esas cosas
5.- Info util para algunos proyectos y sobre la MLX: https://harm-smits.github.io/42docs/
Para practicar los examenes: https://grademe.fr/
El tester mas amado para los primeros proyectos: https://github.com/xicodomingues/francinette
Visualizer para el push_swap: https://github.com/o-reo/push_swap_visualizer (editado) 
