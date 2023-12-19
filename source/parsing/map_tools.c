/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:38:25 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/10 15:38:25 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	number_of_collectibles(char	**map)
{
	int	row;
	int	col;
	int	num;

	row = 0;
	num = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'C')
				num++;
			col++;
		}
		row++;
	}
	return (num);
}

int	startposition_row(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
				return (row);
			col++;
		}
		row++;
	}
	return (row);
}

int	startposition_col(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
				return (col);
			col++;
		}
		row++;
	}
	return (row);
}

char	**dup_map(char **map)
{
	char	**map_path;
	int		line;
	int		length;

	length = 0;
	while (map[length])
		length++;
	map_path = ft_calloc(length + 1, sizeof(char **));
	line = 0;
	while (line < length)
	{
		map_path[line] = ft_strdup(map[line]);
		line++;
	}
	return (map_path);
}
