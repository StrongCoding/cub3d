/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:01:20 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/14 10:41:11 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void fill_struct(t_minimap *mm, t_game *game)
{
	mm->map = game->map;
	mm->count_w = WIN_WIDTH / 2 - (MAP_PLAYER / 2) / MAP_WALL;
	mm->count_h = WIN_HEIGHT / 2 - (MAP_PLAYER / 2) / MAP_WALL;
	mm->pos_x_zero = WIN_WIDTH / 6 / 2;
	mm->pos_y_zero = WIN_HEIGHT / 6 / 2;
}

static void	draw_player(t_game *game)
{
	int i;
	int j;

	j = MAP_PLAYER / 2 * -1;
	while (j < MAP_PLAYER / 2)
	{
		i = MAP_PLAYER / 2 * -1;
		while (i < MAP_PLAYER / 2)
		{
			my_mlx_pixel_put(game->img1,  WIN_WIDTH / 6 / 2 + i, WIN_HEIGHT / 6 / 2 + j, game->ceiling_color);
			i++;
		}
		j++;
	}
}

static void	draw_map(t_game *game)
{

	game->img2 = NULL;
}

void	minimap(t_game *game)
{
	t_minimap	mm;
	int			i;
	int			j;

	j = 0;
	while (j < WIN_HEIGHT / 6)
	{
		i = 0;
		while (i < WIN_WIDTH / 6)
		{
			my_mlx_pixel_put(game->img1, i, j, game->floor_color);
			i++;
		}
		j++;
	}
	fill_struct(&mm, game);
	draw_player(game);
	draw_map(game);
}