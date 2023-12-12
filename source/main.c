/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:45 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/12 11:00:56 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game			game;
	t_image			image1;
	t_image			image2;
	t_raycasting	ray;
	char			**map;

	map = malloc(sizeof(char *) * 24);
	map[0] = ft_strdup("111111111111111111111111");
	map[1] = ft_strdup("100000000000000000000001");
	map[2] = ft_strdup("100000000000000000000001");
	map[3] = ft_strdup("100000000000000000000001");
	map[4] = ft_strdup("100000000000000000000001");
	map[5] = ft_strdup("100000000011111000000001");
	map[6] = ft_strdup("100000000000000000000001");
	map[7] = ft_strdup("100000000000000000000001");
	map[8] = ft_strdup("100000000000000000000001");
	map[9] = ft_strdup("100000000000000000000001");
	map[10] = ft_strdup("100000000000000000000001");
	map[11] = ft_strdup("100000000000000000000001");
	map[12] = ft_strdup("100000000000000000000001");
	map[13] = ft_strdup("100000000000011111100001");
	map[14] = ft_strdup("100000000000000000000001");
	map[15] = ft_strdup("100000000000000000000001");
	map[16] = ft_strdup("100000000000000000000001");
	map[17] = ft_strdup("100000000000000000000001");
	map[18] = ft_strdup("100000000000000000000001");
	map[19] = ft_strdup("100000000000000000000001");
	map[20] = ft_strdup("100100000000011100000001");
	map[21] = ft_strdup("111111111000000011111111");
	map[22] = ft_strdup("100000000000000000000001");
	map[23] = ft_strdup("111111111111111111111111");
	init_struct(&game);
	ft_bzero(&ray, sizeof(t_raycasting));
	game.map = map;
	game.ceiling_color = get_trgb(0, 0, 255, 255);
	game.floor_color = get_trgb(0, 102, 51, 0);
	game.ray = &ray;
	init_win(&game);
	init_image(&game, &image1);
	init_image(&game, &image2);
	usleep(1000000);
	// test_image1(&game, &image1);
	game.img1 = &image1;
	game.img2 = &image2;
	game.ray->pos_x = 22;
	game.ray->pos_y = 12;
	game.ray->dir_x = -1;
	game.ray->plane_y = 0.66;
	printf("game loop starting\n");
	if (!(game.error))
	{
		mlx_hook(game.win, KeyPress, KeyPressMask, key_hook, &game);
		mlx_hook(game.win, DestroyNotify, NoEventMask, key_hook_destroy, &game);
		mlx_hook(game.win, Expose, ExposureMask, expose_hook, &game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_loop(game.mlx);
	}
	// ft_close_programm(game);
	return (0);
}
