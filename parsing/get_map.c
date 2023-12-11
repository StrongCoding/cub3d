/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:15:51 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/11 12:15:51 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int	valid_char(char c)
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
	if (file[row][col - 1] == 3 || file[row][col + 1] == 3 || \
		file[row - 1][col] == 3 || file[row + 1][col] == 3)
		return (0);
	return (1);
}

static int	check_map(char **file, int row, int col, int *s_bool)
{
	if (!valid_char(file[row][col]))
		return (0);
	if (*s_bool == 1 && valid_char(file[row][col]) == 2)
		return (0);
	else if (valid_char(file[row][col]) == 2)
		*s_bool = 1;
	if (file[row][col] == '0')
	{
		if (!check_zero(file, row, col))
			return (0);
	}
	return (1);
}

char	***get_map(t_input *input, char **file, int line)
{
	int	i;
	int s_bool;

	s_bool = 0;
	while (file[line])
	{
		i = 0;
		while(file[line][i] != '\n')
		{
			i++;
			if (!check_map(file, line, i, &s_bool))
				input->exit = 0;
		}
		if (i > input->cols)
			input->cols = i;
		line++;
		(input->rows)++;
	}
	if (input->exit = 0)
		return (printf("Invalid Map"), NULL);
	return (NULL);
}
