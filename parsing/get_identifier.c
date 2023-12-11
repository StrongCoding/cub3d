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

static int	pos_end(char *s)
{
	int	i;

	i = 0;
	while (s[i] != ('\t' & ' ' & '\n'))
		i++;
	return (i - 1);
}

static void	start_input(t_input *input)
{
	input->no_texture = NULL;
	input->so_texture = NULL;
	input->we_texture = NULL;
	input->ea_texture = NULL;
	input->fl_color = ft_calloc(sizeof(int), 3);
	input->fl = 0;
	input->ce_color = ft_calloc(sizeof(int), 3);
	input->ce = 0;
	input->rows = 0;
	input->cols = 0;
}

static void	get_identifier(t_input *input, char **map, int *i)
{
	if (!ft_strncmp("NO ", &map[*i][0], 3) && !input->no_texture)
		input->no_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("SO ", &map[*i][0], 3) && !input->so_texture)
		input->so_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("WE ", &map[*i][0], 3) && !input->we_texture)
		input->we_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("EA ", &map[*i][0], 3) && !input->ea_texture)
		input->ea_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("F ", &map[*i][0], 2) && !input->fl)
		input->exit = fl_colors(input, map[*i]);
	else if (!ft_strncmp("C ", &map[*i][0], 2) && !input->ce)
		input->exit = ce_colors(input, map[*i]);
	(*i)++;
	if (input->exit == 0)
		return ;
	if ((!input->no_texture || !input->so_texture || !input->we_texture || \
		!input->ea_texture || !input->fl || !input->ce) && map[*i])
		get_identifier(input, map, i);
}

void	find_identifier(t_input *input, char **map, int *line)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ('\t' | '\v' | '\f' | '\r' | ' '))
			j++;
		if (map[i][j] == '\n')
			i++;
		else
		{
			start_input(input);
			get_identifier(input, map, &i);
			break ;
		}
	}
	if (input->exit == 0 || !map[i])
		free_identifier(input);
	*line = i;
	while (!ft_strncmp(map[*line], "\n", 1))
		(*line)++;
}
