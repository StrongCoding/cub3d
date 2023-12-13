/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:36:13 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/13 21:01:43 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_vertical_line(int x, int y_start, int y_end, int color, t_image *img)
{
	while (y_start <= y_end)
	{
		my_mlx_pixel_put(img, x, y_start, color);
		y_start++;
	}
}

int	my_mlx_pixel_get(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_ground_ceiling(t_image *img, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (y < game->win_height / 2)
				my_mlx_pixel_put(img, x, y, game->ceiling_color);
			else
				my_mlx_pixel_put(img, x, y, game->floor_color);
			x++;
		}
		y++;
	}
}

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_square(t_image *img)
{
	int	i;
	int	j;

	i = img->line_length;
	i = i / 4 / 8;
	printf("line length: %d\n", img->line_length);
	while (i < img->line_length / 4 / 8 * 3)
	{
		j = img->line_length / 4 / 8;
		while (j < img->line_length / 4 / 8 * 3)
		{
			my_mlx_pixel_put(img, i, j, get_trgb(0, 255, 255, 255));
			j++;
		}
		i++;
	}
}
