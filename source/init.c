/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:27:14 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/14 15:10:58 by dnebatz          ###   ########.fr       */
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
		// game->door = ft_newsprite("sprites/door.xpm");
		// game->door->img = mlx_xpm_file_to_image(game->mlx,
		// 		game->door->relative_path, &game->door->width,
		// 		&game->door->height);
		// game->door_img->img = game->door->img;
		// game->door_img->addr = mlx_get_data_addr(game->door_img->img, &game->door_img->bits_per_pixel, &game->door_img->line_length, &game->door_img->endian);
		game->win_height = WIN_HEIGHT;
		game->win_width = WIN_WIDTH;
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
