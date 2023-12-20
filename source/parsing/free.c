/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:53:28 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/19 16:50:50 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

void	free_identifier(t_input *input)
{
	if (input->no_texture)
		free(input->no_texture);
	if (input->so_texture)
		free(input->so_texture);
	if (input->we_texture)
		free(input->we_texture);
	if (input->ea_texture)
		free(input->ea_texture);
	if (input->fl_color)
		free(input->fl_color);
	if (input->ce_color)
		free(input->ce_color);
}

void	free_sprites(t_sprite **sprite)
{
	int	i;

	i = 0;
	while (sprite[i])
	{
		free(sprite[i]);
		i++;
	}
	free(sprite);
}

void	free_image(t_map *map, t_game *game)
{
	int	i;

	i = -1;
	mlx_destroy_image(game->mlx, game->img1->img);
	while (map->textures[++i])
	{
		mlx_destroy_image(game->mlx, map->textures[i]->img);
		free(map->textures[i]);
		free(map->img[i]);
	}
	free(map->textures);
	free(map->img);
}