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
	mm->count_w = WIN_WIDTH / 6  / MAP_WALL;
	mm->count_h = WIN_HEIGHT / 6 / MAP_WALL;
	mm->pos_w = WIN_HEIGHT / 2 - (MAP_PLAYER / 2);
	mm->pos_h = WIN_HEIGHT / 2 - (MAP_PLAYER / 2);
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
			if (j == MAP_PLAYER / 2 * -1 || j == MAP_PLAYER / 2 - 1 || j == 0 || i == MAP_PLAYER / 2 * -1 || i == MAP_PLAYER / 2 - 1 || i == 0)
				my_mlx_pixel_put(game->img1,  WIN_WIDTH / 6 / 2 + i + (MAP_PLAYER / 2), WIN_HEIGHT / 6 / 2 + j + (MAP_PLAYER / 2), get_trgb(0, 14, 3, 3));
			else
				my_mlx_pixel_put(game->img1,  WIN_WIDTH / 6 / 2 + i + (MAP_PLAYER / 2), WIN_HEIGHT / 6 / 2 + j + (MAP_PLAYER / 2), get_trgb(0, 215, 0, 0));
			i++;
		}
		j++;
	}
}

static void	draw_square(int x, int y, int color, t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < MAP_WALL)
	{
		j = 0;
		while (j < MAP_WALL)
		{
			my_mlx_pixel_put(game->img1, i + x, j + y, color);
			j++;
		}
		i++;
	}
}

static void	draw_wall(t_game *game, t_minimap *mm, int length)
{
	int i;
	int j;
	int num;
	int color;
	int	k;

	k = mm->count_h / 2 * -1;
	j = 0;
	color = get_trgb(0, 130, 255, 25);
	while (k < mm->count_h / 2)
	{
		i = 0;
		num = mm->count_w / 2 * -1;
		while (num < mm->count_w / 2)
		{
			if ((int)game->ray->pos_y + num >= 0 && (int)game->ray->pos_x + k >= 0 && (int)game->ray->pos_y + num <= ft_strlen(game->map[0]) && (int)(int)game->ray->pos_x + k < length && game->map[(int)game->ray->pos_x + k][(int)game->ray->pos_y + num] == '1')
				draw_square((MAP_WALL * i), (MAP_WALL * j), color, game);
			num++;
			i++;
		}
		k++;
		j++;
	}
	game->img2 = NULL;
}

static void	draw_space(t_game *game, t_minimap *mm, int length)
{
	int i;
	int j;
	int num;
	int color;
	int	k;

	k = mm->count_h / 2 * -1;
	j = 0;
	color = get_trgb(0, 30, 25, 255);
	while (k < mm->count_h / 2)
	{
		i = 0;
		num = mm->count_w / 2 * -1;
		while (num < mm->count_w / 2)
		{
			if ((int)game->ray->pos_y + num >= 0 && (int)game->ray->pos_x + k >= 0 && (int)game->ray->pos_y + num <= ft_strlen(game->map[0]) && (int)(int)game->ray->pos_x + k < length && game->map[(int)game->ray->pos_x + k][(int)game->ray->pos_y + num] == '0')
				draw_square((MAP_WALL * i), (MAP_WALL * j), color, game);
			num++;
			i++;
		}
		k++;
		j++;
	}
	game->img2 = NULL;
}

void	minimap(t_game *game)
{
	t_minimap	mm;
	int 		length;

	length = 0;
	while (game->map[length])
		length++;
	fill_struct(&mm, game);
	draw_space(game, &mm, length);
	draw_player(game);
	draw_wall(game, &mm, length);
}