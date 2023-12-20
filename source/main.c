/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:09:45 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 17:20:43 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_hooks(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->win, DestroyNotify, NoEventMask, key_hook_destroy, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}

void	set_values(t_map *info, t_game *game, t_image *image1)
{
	game->ceiling_color = get_trgb(0, info->ce_color.r,
			info->ce_color.g, info->ce_color.b);
	game->floor_color = get_trgb(0, info->fl_color.r,
			info->fl_color.g, info->fl_color.b);
	game->img1 = image1;
	game->map = info->map;
	game->ray->img = info->img;
	game->ray->tex = info->textures;
	game->ray->pos_x = info->start_pos.start_row + 0.5;
	game->ray->pos_y = info->start_pos.start_col + 0.5;
	if (!SHOW_MOUSE)
		mlx_mouse_hide(game->mlx, game->win);
	mlx_mouse_move(game->mlx,
		game->win, game->win_width / 2, game->win_height / 2);
}

int	main(int argc, char **argv)
{
	t_game			game;
	t_image			image1;
	t_raycasting	ray;
	t_input			input;
	t_map			info;

	if (argc != 2)
		return (ft_printf("Error\nInvalid number of arguments"), 1);
	if (!ending_cub(argv[1]))
		return (ft_printf("Error\nInvalid name of map"), 2);
	input = read_map(argv[1]);
	if (!input.exit)
		return (ft_printf("Error\nInvalid map"));
	if (!file_check(&input))
		return (free_array(input.map), free_identifier(&input), \
		ft_printf("Error\nInvalid textures"));
	init_struct(&game);
	ft_bzero(&ray, sizeof(t_raycasting));
	game.ray = &ray;
	init_win(&game);
	if (!convert_struct(&input, &info, &game))
		return (failed_convert(&game, &info), \
		ft_printf("Error\nInvalid textures"));
	init_image(&game, &image1);
	set_values(&info, &game, &image1);
	if (!(game.error))
		game_hooks(&game);
	return (end_program(&game), 0);
}
