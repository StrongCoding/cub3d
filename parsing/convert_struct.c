/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:27 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/11 15:39:27 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"


static int	get_textures(t_map *map, t_input *input)
{
	int fd;

	map->textures = ft_calloc(5, sizeof(t_sprite *));
	ft_printf("calloc double pointer\n");
	if (!map->textures)
		return (free_identifier(input), 0);
	fd = open(input->we_texture, O_RDONLY);
	ft_printf("fd 1\n");
	if (!fd)
		return (free_identifier(input), 0);
	map->textures[0] = ft_newsprite(input->we_texture);
	ft_printf("calloc 1\n");
	if (!map->textures[0])
		return (free_identifier(input), 0);
	close (fd);
	fd = open(input->ea_texture, O_RDONLY);
	ft_printf("fd 2\n");
	if (!fd)
		return (free_identifier(input), 0);
	map->textures[1] = ft_newsprite(input->ea_texture);
	ft_printf("calloc 2\n");
	if (!map->textures[1])
		return (free_identifier(input), free_sprites(map->textures), 0);
	close (fd);
	fd = open(input->no_texture, O_RDONLY);
	ft_printf("fd 3\n");
	if (!fd)
		return (free_identifier(input), 0);
	map->textures[2] = ft_newsprite(input->no_texture);
	ft_printf("calloc 3\n");
	if (!map->textures[2])
		return (free_identifier(input), 0);
	close (fd);
	fd = open(input->so_texture, O_RDONLY);
	ft_printf("fd 4\n");
	if (!fd)
		return (free_identifier(input), 0);
	map->textures[3] = ft_newsprite(input->so_texture);
	ft_printf("calloc 4\n");
	if (!map->textures[3])
		return (free_identifier(input), 0);
	close (fd);
	return (1);
}

int convert_struct(t_input *input, t_map *map)
{
	if (!get_textures(map, input))
		return (0);
	map->fl_color.r = input->fl_color[0];
	map->fl_color.g = input->fl_color[1];
	map->fl_color.b = input->fl_color[2];
	free(input->fl_color);
	map->ce_color.r = input->ce_color[0];
	map->ce_color.g = input->ce_color[1];
	map->ce_color.b = input->ce_color[2];
	free(input->ce_color);
	map->map = input->map;
	map->start_pos = input->info;
	return (1);
}
