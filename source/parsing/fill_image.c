/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:51:45 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/20 10:51:45 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	fill_image(t_map *map, t_game *game, int count)
{
	map->textures[count]->img = mlx_xpm_file_to_image(game->mlx, \
	map->textures[count]->relative_path, &map->textures[count]->width, \
	&map->textures[count]->height);
	map->img[count]->addr = mlx_get_data_addr(map->textures[count]->img, \
	&map->img[count]->bits_per_pixel, &map->img[count]->line_length, \
	&map->img[count]->endian);
}
