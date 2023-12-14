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
			my_mlx_pixel_put(game->img1, i, j, game->floor_color);
			i++;
		}
		j++;
	}
}