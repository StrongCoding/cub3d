/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:51:58 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 17:22:52 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all_images(t_game *game)
{
	int	i;

	i = -1;
	mlx_destroy_image(game->mlx, game->img1->img);
	while (game->ray->tex[++i])
	{
		mlx_destroy_image(game->mlx, game->ray->tex[i]->img);
		free(game->ray->tex[i]);
		free(game->ray->img[i]);
	}
	free(game->ray->tex);
	free(game->ray->img);
}

void	end_program(t_game *game)
{
	printf("exiting!\n");
	free_array(game->map);
	free_all_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	failed_convert(t_game *game, t_map *map)
{
	free_array(map->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}