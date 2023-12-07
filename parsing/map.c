/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:37:45 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/27 09:40:04 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int	ep_check(char **map, int length)
{
	int	p;
	int	e;
	int	line;

	p = 0;
	e = 0;
	line = 0;
	while (line < length && map)
	{
		//p = p + is_ep_true(map[line], 'P');
		//e = e + is_ep_true(map[line], 'E');
		line++;
	}
	if (e != 1 || p != 1)
		return (0);
	return (1);
}

static int	map_check(int length, char **map)
{
	char	**map_path;
	int		line;

	line = 0;
	while (line < length)
	{
		if (!map_check_line(line, map[line], length))
			return (0);
		line++;
	}
	if (!ep_check(map, length))
		//return (0);
	map_path = ft_calloc(length + 1, sizeof(char **));
	line = 0;
	while (line < length)
	{
		map_path[line] = ft_strdup(map[line]);
		line++;
	}
	//if (map_check_path(map_path) == 0)
		//return (0);
	return (1);
}

char	**read_map(char *name)
{
	char	**map;
	int		line;
	int		length;
	int		fd;

	length = map_length(name);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = 0;
	map = ft_calloc(length + 1, sizeof(char **));
	while (line < length)
	{
		map[line] = get_next_line(fd);
		line++;
	}
	close(fd);
	if (line > 22 || ft_strlen(map[line - 1]) > 41 || \
		!map_check(line, map))
	{
		ft_printf("Error\nInvalid Map");
		return (free_array(map), NULL);
	}
	return (map);
}
