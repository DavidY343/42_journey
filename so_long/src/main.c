/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:11:24 by dyanez-m          #+#    #+#             */
/*   Updated: 2023/11/07 00:57:52 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/so_long.h"

int	main(int argc, char **argv)
{

	if (argc != 2)
		msg_error("You must run it with only one parameter!\n");
	int result = ft_strrncmp(argv[1], ".ber", 4);
	ft_printf("%d\n", result);
	if (result != 0)
		msg_error("You must include a ber file!\n");
	ft_putstr_fd("todo guud\n", 2);
	return (0);
}
