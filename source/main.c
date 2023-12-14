/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:45 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/14 10:34:34 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game			game;
	t_image			image1;
	t_image			image2;
	t_raycasting	ray;
	t_input			input;
	t_map			info;

	if (argc != 2)
		return (ft_printf("Error\nInvalid number of arguments"), 1);
	if (!ending_cub(argv[1]))
		return (ft_printf("Error\nInvalid name of map"));
	input = read_map(argv[1]);
	if (!input.exit)
		return (ft_printf("Error\nInvalid map"));
	init_struct(&game);
	ft_bzero(&ray, sizeof(t_raycasting));
	game.ray = &ray;
	init_win(&game);
	if (!convert_struct(&input, &info, &game))
		return (free_array(input.map), ft_printf("Error\nInvalid textures"));
	init_image(&game, &image1);
	game.ceiling_color = get_trgb(0, info.ce_color.r, info.ce_color.g, info.ce_color.b);
	game.floor_color = get_trgb(0, info.fl_color.r, info.fl_color.g, info.fl_color.b);
	init_image(&game, &image2);
	usleep(1000000);
	game.img1 = &image1;
	game.img2 = &image2;
	game.map = info.map;
	ray.img = info.img;
	ray.tex = info.textures;
	game.ray->pos_x = info.start_pos.start_row + 0.5;
	game.ray->pos_y = info.start_pos.start_col + 0.5;
	// game.ray->dir_x = -1;
	// game.ray->plane_y = 0.66;
	printf("game loop starting\n");
	if (!(game.error))
	{
		//minimap(&game);
		mlx_hook(game.win, KeyPress, KeyPressMask, key_hook, &game);
		mlx_hook(game.win, DestroyNotify, NoEventMask, key_hook_destroy, &game);
		mlx_hook(game.win, Expose, ExposureMask, expose_hook, &game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_loop(game.mlx);
	}
	// ft_close_programm(game);
	return (0);
}
