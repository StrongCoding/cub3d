/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:46:06 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/03 12:40:33 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int	dfs(int row, int col, char	**map)
{
	char	*current;

	current = &map[row][col];
	if (current[0] == '0' || current[0] == 'C' || \
		current[0] == 'P' || current[0] == 'E')
	{
		current[0] = 'Z';
		if (dfs(row, col - 1, map))
			return (1);
		if (dfs(row + 1, col, map))
			return (1);
		if (dfs(row, col + 1, map))
			return (1);
		if (dfs(row - 1, col, map))
			return (1);
	}
	return (0);
}

static int	checker_map(char **new, char **original)
{
	int	row;
	int	col;

	row = 1;
	while (original[row])
	{
		col = 1;
		while (original[row][col])
		{
			if (original[row][col] == 'C' && new[row][col] != 'Z')
				return (0);
			else if (original[row][col] == 'E' && new[row][col] != 'Z')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	map_check_path(char **map)
{
	static int	row;
	static int	col;
	char		**new_map;

	row = startposition_row(map);
	col = startposition_col(map);
	new_map = dup_map(map);
	dfs(row, col, map);
	if (!checker_map(map, new_map))
	{
		ft_printf("Error\nMap-Path is impossible\n");
		free_array(map);
		free_array(new_map);
		return (0);
	}
	free_array(map);
	free_array(new_map);
	return (1);
}
