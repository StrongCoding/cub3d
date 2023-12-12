/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:37:33 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/27 09:37:33 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int	first_line(char *map)
{
	int	width;

	width = (int)ft_strlen(map) - 2;
	while (width >= 0)
	{
		if (map[width] != '1')
			return (0);
		width--;
	}
	return (1);
}

static int	last_line(char *map, int width)
{
	width = width -2;
	while (width >= 0)
	{
		if (map[width] != '1')
			return (0);
		width--;
	}
	return (1);
}

static int	correct_line(char *map)
{
	int	width;
	int	i;

	width = (int)ft_strlen(map) - 2;
	i = 1;
	if (map[0] != '1' || map[width] != '1')
		return (0);
	while (i < width)
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' && \
			map[i] != 'E' && map[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}

int	map_check_line(int line, char *map, int length)
{
	static int	width;
	int			correct_map;

	if (width == 0)
		width = (int)ft_strlen(map);
	if (line == 0)
		correct_map = first_line(map);
	else if (line == length - 1)
		correct_map = last_line(map, width);
	else
	{
		if (width != (int)ft_strlen(map))
			return (0);
		else
		{
			correct_map = correct_line(map);
		}
		return (correct_map);
	}
	return (correct_map);
}

int	is_ep_true(char *map, char c)
{
	int	true;
	int	width;

	true = 0;
	width = (int)ft_strlen(map) - 1;
	while (width > -1)
	{
		if (map[width] == c)
		{
			true++;
		}
		width--;
	}
	return (true);
}
