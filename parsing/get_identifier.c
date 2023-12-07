/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:06:42 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/07 14:06:42 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int pos_num(char *s, int *j)
{
	int	i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	(*j)++;
	return (i);
}

static int	pos_end(char *s)
{
	int i;

	i = 0;
	while (s[i] != ('\t' | ' ' | '\n'))
		i++;
	return (i);
}

static void	start_input(t_input *input)
{
	input->no_texture = NULL;
	input->so_texture = NULL;
	input->we_texture = NULL;
	input->ea_texture = NULL;
	input->fl_color = ft_calloc(sizeof(int), 3);
	input->ce_color = ft_calloc(sizeof(int), 3);
}

static void	get_identifier(t_input *input, char **map, int *i, int j)
{
	if (!ft_strncmp("NO ", &map[*i][j], 3))
		input->no_texture = ft_substr(&map[*i][j + 3], 0, pos_end(&map[*i][j + 3]));
	else if (!ft_strncmp("SO ", &map[*i][j], 3))
		input->so_texture = ft_substr(&map[*i][j + 3], 0, pos_end(&map[*i][j + 3]));
	else if (!ft_strncmp("WE ", &map[*i][j], 3))
		input->we_texture = ft_substr(&map[*i][j + 3], 0, pos_end(&map[*i][j + 3]));
	else if (!ft_strncmp("EA ", &map[*i][j], 3))
		input->ea_texture = ft_substr(&map[*i][j + 3], 0, pos_end(&map[*i][j + 3]));
	else if (!ft_strncmp("F ", &map[*i][j], 2))
	{
		input->fl_color[0] = ft_atoi(ft_substr(&map[*i][j + 3], 0, pos_num(&map[*i][j + 3], &j)));
		input->fl_color[1] = ft_atoi(ft_substr(&map[*i][j + 3], 0, pos_num(&map[*i][j + 3], &j)));
		input->fl_color[2] = ft_atoi(ft_substr(&map[*i][j + 3], 0, pos_num(&map[*i][j + 3], &j)));
	}
	else if (!ft_strncmp("C ", &map[*i][j], 2))
	{
		input->ce_color[0] = ft_atoi(ft_substr(&map[*i][j + 3], 0, pos_num(&map[*i][j + 3], &j)));
		input->ce_color[1] = ft_atoi(ft_substr(&map[*i][j + 3], 0, pos_num(&map[*i][j + 3], &j)));
		input->ce_color[2] = ft_atoi(ft_substr(&map[*i][j + 3], 0, pos_num(&map[*i][j + 3], &j)));
	}
	(*i)++;
	if (!input->no_texture || !input->so_texture || !input->we_texture || !input->ea_texture || !input->fl_color || !input->ce_color)
		get_identifier(input, map, i , j);
}

void	find_identifier(t_input *input, char **map, int *line)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j] == ('\t' | '\v' | '\f' | '\r' | ' '))
			j++;
		if (map[i][j] == '\n')
			i++;
		else
		{
			start_input(input);
			get_identifier(input, map, &i, j);
			break;
		}
	}
	map = NULL;
	line = 0;
}