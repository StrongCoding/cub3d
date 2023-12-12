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

	fd = open(input->no_texture, O_RDONLY);
	if (!fd)
		return (free_identifier(input), 0);
	close (fd);
	fd = open(input->so_texture, O_RDONLY);
	if (!fd)
		return (free_identifier(input), 0);
	close (fd);
	fd = open(input->we_texture, O_RDONLY);
	if (!fd)
		return (free_identifier(input), 0);
	close (fd);
	fd = open(input->ea_texture, O_RDONLY);
	if (!fd)
		return (free_identifier(input), 0);
	close (fd);
	return (1);
}

int convert_struct(t_input *input)
{
	t_map	map;

	if (!get_textures(&map, input))
		return (0);
	/*map.no_text;
	map.so_tex;
	map.we_tex; get_mlx_pointer;
	map.ea_tex; */
	map.fl_color.r = input->fl_color[0];
	map.fl_color.g = input->fl_color[1];
	map.fl_color.b = input->fl_color[2];
	map.ce_color.r = input->ce_color[0];
	map.ce_color.g = input->ce_color[1];
	map.ce_color.b = input->ce_color[2];
	map.map = input->map;
	map.info = input->info;
	return (1);
}
