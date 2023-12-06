/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:45 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/06 09:37:47 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_image		image1;
	t_image		image2;

	// if (argc != 2)
	// {
	// 	ft_printf("Error\nwrong parameter count\n");
	// 	return (1);
	// }
	// if (ft_check_argv(argv) < 1)
	// 	return (1);
	init_struct(&game);
	init_win(&game);
	usleep(1000000);
	test_wall(&game);
	test_image1(&game, &image1);
	test_image2(&game, &image2);
	usleep(3000000);
	printf("test\n");
	mlx_put_image_to_window(game.mlx, game.win,
		image1.img, 400, 300);
	usleep(3000000);
	printf("test 2\n");
	mlx_put_image_to_window(game.mlx, game.win,
		image2.img, 400, 300);
	if (!(game.error))
	{
		mlx_hook(game.win, KeyPress, KeyPressMask, key_hook, &game);
		mlx_hook(game.win, DestroyNotify, NoEventMask, key_hook_destroy, &game);
		mlx_hook(game.win, Expose, ExposureMask, expose_hook, &game);
		// mlx_loop_hook(game.mlx, ft_frame, &game);
		mlx_loop(game.mlx);
	}
	// ft_close_programm(game);
	return (0);
}
