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

static void	fill_struct(t_minimap *mm, t_game *game)
{
	mm->map = game->map;
	mm->count_w = WIN_WIDTH / 6 / MAP_WALL;
	mm->count_h = WIN_HEIGHT / 6 / MAP_WALL;
	mm->pos_w = WIN_HEIGHT / 2 - (MAP_PLAYER / 2);
	mm->pos_h = WIN_HEIGHT / 2 - (MAP_PLAYER / 2);
	mm->pos_x_zero = WIN_WIDTH / 6 / 2;
	mm->pos_y_zero = WIN_HEIGHT / 6 / 2;
}

static void	draw_fov(t_game *game, t_minimap *mm)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_PLAYER)
	{
		j = 0;
		while (j < i)
		{
			my_mlx_pixel_put(game->img1, i + mm->pos_x_zero , j + mm->pos_y_zero, get_trgb(0, 179, 43, 43));
			j++;
		}
		i++;
	}
	i = MAP_PLAYER - 1;
	while (i > game->ray->pos_x)
	{
		j = 0;
		while (j < i)
		{
			my_mlx_pixel_put(game->img1, i + mm->pos_x_zero, j + mm->pos_y_zero, get_trgb(0, 179, 43, 43));
			j++;
		}
		i--;
	}
}

void	minimap(t_game *game)
{
	t_minimap	mm;
	int			length;

	length = 0;
	while (game->map[length])
		length++;
	fill_struct(&mm, game);
	draw_mm_space(game, &mm, length, mm.count_h / 2 * -1);
	draw_mm_player(game);
	draw_fov(game, &mm);
	draw_mm_wall(game, &mm, length, mm.count_h / 2 * -1);
}
