/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:27 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/14 15:24:50 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int fill_struct(t_map *map, t_input *input, t_game *game, int count)
{
	int	fd;

	fd = open(input->we_texture, O_RDONLY);
	ft_printf("fd 1\n");
	if (fd == -1)
		return (free_identifier(input), 0);
	if (count == 0)
		map->textures[count] = ft_newsprite(input->we_texture);
	else if (count == 1)
		map->textures[count] = ft_newsprite(input->ea_texture);
	else if (count == 2)
		map->textures[count] = ft_newsprite(input->no_texture);
	else if (count == 3)
		map->textures[count] = ft_newsprite(input->so_texture);
	else if (count == 4)
		map->textures[count] = ft_newsprite("sprites/door.xpm");
	ft_printf("calloc tex %i\n", count);
	if (!map->textures[0])
		return (free_identifier(input), 0);
	map->img[count] = ft_calloc (1, sizeof(t_image));
	ft_printf("calloc img %i\n", count);
	if (!map->img[count])
		return (free_identifier(input), 0);
	map->textures[count]->img = mlx_xpm_file_to_image(game->mlx, map->textures[count]->relative_path, \
							&map->textures[count]->width, &map->textures[count]->height);
	map->img[count]->addr = mlx_get_data_addr(map->textures[count]->img, &map->img[count]->bits_per_pixel,
										  &map->img[count]->line_length, &map->img[count]->endian);
	close (fd);
	return (1);
}

static void	fill_dir(t_input *input, t_game *game)
{
	if (input->info.start_dir == 'N')
	{
		game->ray->dir_x = -1;
		game->ray->plane_y = FOV;
	}
	else if (input->info.start_dir == 'S')
	{
		game->ray->dir_x = 1;
		game->ray->plane_y = -FOV;
	}
	else if (input->info.start_dir == 'E')
	{
		game->ray->dir_y = 1;
		game->ray->plane_x = FOV;
	}
	else if (input->info.start_dir == 'W')
	{
		game->ray->dir_y = -1;
		game->ray->plane_x = -FOV;
	}
}

static int	get_textures(t_map *map, t_input *input, t_game *game)
{
	int i;

	i = 0;
	map->textures = ft_calloc(6, sizeof(t_sprite *));
	map->img = ft_calloc(6, sizeof(t_image *));
	ft_printf("calloc double pointer\n");
	if (!map->textures)
		return (free_identifier(input), 0);
	while (i < 5)
	{
		if (!fill_struct(map, input, game, i))
			return (0);
		i++;
	}
	fill_dir(input, game);
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
