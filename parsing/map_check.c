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

int	ending_cub(char *name)
{
	size_t	len;

	len = ft_strlen(name) - 1;
	if (name[len] != 'b' || name[len - 1] != 'u' || \
		name[len - 2] != 'c' || name[len - 3] != '.')
		return (0);
	return (1);
}

int	valid_char(char c)
{
	if (c == '1' || c == '0')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (2);
	if (c == ' ')
		return (3);
	return (0);
}

static int	check_zero(char **file, int row, int col)
{
	if (col == 0 || valid_char(file[row][col - 1]) == 3 || \
	!valid_char(file[row][col + 1]) || valid_char(file[row][col + 1]) == 3 \
	|| row == 0 || !file[row + 1] || valid_char(file[row - 1][col]) == 3 || \
	valid_char(file[row + 1][col]) == 3)
		return (0);
	return (1);
}

int	check_map(char **file, int row, int col, int *s_bool)
{
	if (!valid_char(file[row][col]))
		return (0);
	if (*s_bool == 1 && valid_char(file[row][col]) == 2)
		return (0);
	else if (valid_char(file[row][col]) == 2)
	{
		file[row][col] = '0';
		*s_bool = 1;
	}
	if (file[row][col] == '0')
	{
		if (!check_zero(file, row, col))
			return (0);
	}
	return (1);
}
