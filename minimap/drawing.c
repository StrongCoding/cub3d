/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:49:06 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/18 10:49:06 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mm_player(t_game *game)
{
	int	i;
	int	j;

	j = MAP_PLAYER / 2 * -1;
	while (j < MAP_PLAYER / 2)
	{
		i = MAP_PLAYER / 2 * -1;
		while (i < MAP_PLAYER / 2)
		{
			if (j == MAP_PLAYER / 2 * -1 || j == MAP_PLAYER / 2 - 1 || j == 0 \
			|| i == MAP_PLAYER / 2 * -1 || i == MAP_PLAYER / 2 - 1 || i == 0)
				my_mlx_pixel_put(game->img1, WIN_WIDTH / 6 / 2 + i + \
				(MAP_PLAYER / 2), WIN_HEIGHT / 6 / 2 + j + (MAP_PLAYER / 2), \
				get_trgb(0, 14, 3, 3));
			else
				my_mlx_pixel_put(game->img1, WIN_WIDTH / 6 / 2 + i + \
				(MAP_PLAYER / 2), WIN_HEIGHT / 6 / 2 + j + (MAP_PLAYER / 2), \
				get_trgb(0, 215, 0, 0));
			i++;
		}
		j++;
	}
}

static void	draw_square(int x, int y, int color, t_game *game)
{
	int		i;
	int		j;
	int 	rotated_x;
	int 	rotated_y;
	double	angle;

	angle = 0 * M_PI / 180.0;
	i = 0;
	while (i < MAP_WALL)
	{
		j = 0;
		while (j < MAP_WALL)
		{
			rotated_x = (int)((i - MAP_WALL / 2) * cos(angle) - (j - MAP_WALL / 2) * sin(angle) + x + MAP_WALL / 2);
			rotated_y = (int)((i - MAP_WALL / 2) * sin(angle) + (j - MAP_WALL / 2) * cos(angle) + y + MAP_WALL / 2);
			if (rotated_x >= 0 && rotated_x < WIN_WIDTH / 6 && rotated_y >= 0 && rotated_y <= WIN_HEIGHT / 6)
				my_mlx_pixel_put(game->img1, rotated_x, rotated_y, color);
			j++;
		}
		i++;
	}
}

void	draw_mm_wall(t_game *game, t_minimap *mm, int length, int k)
{
	int	i;
	int	j;
	int	num;
	int	color;

	j = 0;
	color = get_trgb(0, 130, 255, 25);
	while (k < mm->count_h / 2)
	{
		i = 0;
		num = mm->count_w / 2 * -1 - 1;
		while (++num < mm->count_w / 2)
		{
			if ((int)game->ray->pos_y + num >= 0 && (int)game->ray->pos_x + k \
			>= 0 && (int)game->ray->pos_y + num <= ft_strlen(game->map[0]) && \
			(int)(int)game->ray->pos_x + k < length && \
			game->map[(int)game->ray->pos_x + k][(int)game->ray->pos_y + num] \
			== '1')
				draw_square((MAP_WALL * i), (MAP_WALL * j), color, game);
			i++;
		}
		k++;
		j++;
	}
	game->img2 = NULL;
}

void	draw_mm_space(t_game *game, t_minimap *mm, int length, int k)
{
	int	i;
	int	j;
	int	num;
	int	color;

	j = 0;
	color = get_trgb(0, 30, 25, 255);
	while (k < mm->count_h / 2)
	{
		i = 0;
		num = mm->count_w / 2 * -1 - 1;
		while (++num < mm->count_w / 2)
		{
			if ((int)game->ray->pos_y + num >= 0 && (int)game->ray->pos_x + k \
			>= 0 && (int)game->ray->pos_y + num <= ft_strlen(game->map[0]) && \
			(int)(int)game->ray->pos_x + k < length && \
			game->map[(int)game->ray->pos_x + k][(int)game->ray->pos_y + num] \
			== '0')
				draw_square((MAP_WALL * i), (MAP_WALL * j), color, game);
			i++;
		}
		k++;
		j++;
	}
	game->img2 = NULL;
}
