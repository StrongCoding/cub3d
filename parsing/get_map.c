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

static char	**alloc_map(t_input *input)
{
	int		i;
	char	**map;

	i = 0;
	map = ft_calloc(input->info.count_rows + 1, sizeof(char *));
	if (!map)
		return (NULL);
	while (i <= input->info.count_rows)
	{
		map[i] = ft_calloc(input->info.count_cols + 1, sizeof(char));
		if (!map[i])
		{
			while (i > 0)
			{
				i--;
				free(map[i]);
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

char	**fill_map(t_input *input, char **file, int line)
{
	char	**map;
	int 	col;
	int 	row;

	map = alloc_map(input);
	if (!map)
		return (NULL);
	row = 0;
	while (file[line])
	{
		col = 0;
		while (file[line][col] != '\n' && file[line][col] != '\0')
		{
			if (valid_char(file[line][col]) == 2)
			{
				input->info.start_dir = file[line][col];
				input->info.start_row = row;
				input->info.start_col = col;
			}
			map[row][col] = file[line][col];
			col++;
		}
		while (col < input->info.count_cols)
		{
			map[row][col] = ' ';
			col++;
		}
		line++;
		row++;
	}
	return (map);
}

char	**get_map(t_input *input, char **file, int line)
{
	int	i;
	int start;

	start = line;
	while (file[line])
	{
		i = 0;
		while(file[line][i] != '\n' && file[line][i] != '\0')
			i++;
		if (i > input->info.count_cols)
			input->info.count_cols = i;
		line++;
		(input->info.count_rows)++;
	}
	if (input->exit == 0)
		return (NULL);;
	return (fill_map)(input, file, start);
}
