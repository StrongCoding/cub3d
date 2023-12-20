/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:27 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/20 10:34:03 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int	fill_struct_two(t_map *map, t_input *input, t_game *game, int count)
{
	if (!map->textures[count])
		return (free_identifier(input), 0);
	map->img[count] = ft_calloc (1, sizeof(t_image));
	if (!map->img[count])
		return (free_identifier(input), 0);
	fill_image(map, game, count);
	return (1);
}

static int	fill_struct(t_map *map, t_input *input, t_game *game, int count)
{
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
	else if (count == 5)
		map->textures[count] = ft_newsprite("sprites/baum1.xpm");
	else if (count == 6)
		map->textures[count] = ft_newsprite("sprites/baum2.xpm");
	else if (count == 7)
		map->textures[count] = ft_newsprite("sprites/baum3.xpm");
	else if (count == 8)
		map->textures[count] = ft_newsprite("sprites/baum4.xpm");
	else if (count == 9)
		map->textures[count] = ft_newsprite("sprites/noah1.xpm");
	else if (count == 10)
		map->textures[count] = ft_newsprite("sprites/noah2.xpm");
	return (fill_struct_two(map, input, game, count));
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
	int	i;

	i = 0;
	map->textures = ft_calloc(12, sizeof(t_sprite *));
	if (!map->textures)
		return (free_identifier(input), 0);
	map->img = ft_calloc(12, sizeof(t_image *));
	if (!map->img)
		return (free_identifier(input), free(map->textures), 0);
	while (i < 11)
	{
		if (!fill_struct(map, input, game, i))
			return (free_image(map, game, i), 0);
		i++;
	}
	fill_dir(input, game);
	return (1);
}

int	convert_struct(t_input *input, t_map *map, t_game *game)
{
	if (!get_textures(map, input, game))
		return (0);
	map->fl_color.r = input->fl_color[0];
	map->fl_color.g = input->fl_color[1];
	map->fl_color.b = input->fl_color[2];
	map->ce_color.r = input->ce_color[0];
	map->ce_color.g = input->ce_color[1];
	map->ce_color.b = input->ce_color[2];
	map->map = input->map;
	map->start_pos = input->info;
	free_identifier(input);
	return (1);
}
