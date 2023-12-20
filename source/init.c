/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:27:14 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 20:13:38 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_game *game)
{
	void	*mlx;

	ft_bzero(game, sizeof(t_game));
	mlx = mlx_init();
	if (mlx)
	{
		game->mlx = mlx;
		game->win_height = WIN_HEIGHT;
		game->win_width = WIN_WIDTH;
		game->time = get_time();
		game->time_frame = get_time();
	}
	else
		ft_printf("Error\nmlx initialization error!\n");
}

void	init_win(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "cub3d");
	if (!game->win)
		ft_printf("Error\nWindow creation failed!\n");
}

void	init_image(t_game *game, t_image *img)
{
	img->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}
