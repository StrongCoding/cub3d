/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:01:20 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/13 15:01:20 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < 100)
	{
		i = 0;
		while (i < 100)
		{
			my_mlx_pixel_put(game->img1, 1, 1, game->floor_color);
			mlx_put_image_to_window(game->mlx, game->win, game->img1, i, j);
			i++;
		}
		j++;
	}
}