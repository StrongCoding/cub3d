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


static int	get_textures(t_map *map, t_input *input, t_game *game)
{
	int fd;

	map->textures = ft_calloc(5, sizeof(t_sprite *));
	map->img = ft_calloc(5, sizeof(t_image *));
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
	map->textures[0]->img = mlx_xpm_file_to_image(game->mlx, map->textures[0]->relative_path, \
							&map->textures[0]->width, &map->textures[0]->height);
	map->img[0] = ft_calloc (1, sizeof(t_image));
	map->img[0]->addr = mlx_get_data_addr(map->textures[0]->img, &map->img[0]->bits_per_pixel,
								  &map->img[0]->line_length, &map->img[0]->endian);
	close (fd);
	fd = open(input->ea_texture, O_RDONLY);
	ft_printf("fd 2\n");
	if (!fd)
		return (free_identifier(input), 0);
	map->textures[1] = ft_newsprite(input->ea_texture);
	ft_printf("calloc 2\n");
	if (!map->textures[1])
		return (free_identifier(input), free_sprites(map->textures), 0);
	map->img[1] = ft_calloc (1, sizeof(t_image));
	map->textures[1]->img = mlx_xpm_file_to_image(game->mlx, map->textures[1]->relative_path, \
							&map->textures[1]->width, &map->textures[1]->height);
	map->img[1]->addr = mlx_get_data_addr(map->textures[1]->img, &map->img[1]->bits_per_pixel,
										  &map->img[1]->line_length, &map->img[1]->endian);
	close (fd);
	fd = open(input->no_texture, O_RDONLY);
	ft_printf("fd 3\n");
	if (!fd)
		return (free_identifier(input), 0);
	map->textures[2] = ft_newsprite(input->no_texture);
	ft_printf("calloc 3\n");
	if (!map->textures[2])
		return (free_identifier(input), 0);
	map->img[2] = ft_calloc (1, sizeof(t_image));
	map->textures[2]->img = mlx_xpm_file_to_image(game->mlx, map->textures[2]->relative_path, \
							&map->textures[2]->width, &map->textures[2]->height);
	map->img[2]->addr = mlx_get_data_addr(map->textures[2]->img, &map->img[2]->bits_per_pixel,
										  &map->img[2]->line_length, &map->img[2]->endian);
	close (fd);
	fd = open(input->so_texture, O_RDONLY);
	ft_printf("fd 4\n");
	if (!fd)
		return (free_identifier(input), 0);
	map->textures[3] = ft_newsprite(input->so_texture);
	ft_printf("calloc 4\n");
	if (!map->textures[3])
		return (free_identifier(input), 0);
	map->img[3] = ft_calloc (1, sizeof(t_image));
	map->textures[3]->img = mlx_xpm_file_to_image(game->mlx, map->textures[3]->relative_path, \
							&map->textures[3]->width, &map->textures[3]->height);
	map->img[3]->addr = mlx_get_data_addr(map->textures[3]->img, &map->img[3]->bits_per_pixel,
										  &map->img[3]->line_length, &map->img[3]->endian);
	close (fd);
	return (1);
}

int convert_struct(t_input *input, t_map *map, t_game *game)
{
	if (!get_textures(map, input, game))
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
