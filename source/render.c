/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:42:51 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/06 09:54:39 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test_wall(t_game *game)
{
	printf("putting wall\n");
	mlx_put_image_to_window(game->mlx, game->win,
		game->wall->img, 400, 300);
}

void	test_image1(t_game *game, t_image *img)
{
	img->img = mlx_new_image(game->mlx, 200, 200);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	put_square(img);
}

void	test_image2(t_game *game, t_image *img)
{
	img->img = mlx_new_image(game->mlx, 200, 200);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

