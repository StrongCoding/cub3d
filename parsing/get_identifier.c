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
	*j = *j + i + 1;
	return (i);
}

static int	pos_end(char *s)
{
	int i;

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
}

static int	fl_colors(t_input *input, char *map)
{
	char	*tmp;
	int		j;

	j = 2;
	tmp = ft_substr(map, j, pos_num(&map[2], &j));
	if (!tmp)
		return (0);
	input->fl_color[0] = ft_atoi(tmp);
	free(tmp);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->fl_color[1] = ft_atoi(tmp);
	free(tmp);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->fl_color[2] = ft_atoi(tmp);
	free(tmp);
	input->fl = 1;
	return (1);
}

static int	ce_colors(t_input *input, char *map)
{
	char	*tmp;
	int		j;

	j = 2;
	tmp = ft_substr(map, 2, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->ce_color[0] = ft_atoi(tmp);
	free(tmp);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->ce_color[1] = ft_atoi(tmp);
	free(tmp);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->ce_color[2] = ft_atoi(tmp);
	free(tmp);
	input->ce = 1;
	return (1);
}

static void	get_identifier(t_input *input, char **map, int *i)
{
	if (!ft_strncmp("NO ", &map[*i][0], 3))
		input->no_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("SO ", &map[*i][0], 3))
		input->so_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("WE ", &map[*i][0], 3))
		input->we_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("EA ", &map[*i][0], 3))
		input->ea_texture = ft_substr(&map[*i][3], 0, pos_end(&map[*i][3]));
	else if (!ft_strncmp("F ", &map[*i][0], 2))
		fl_colors(input, map[*i]);
	else if (!ft_strncmp("C ", &map[*i][0], 2))
		ce_colors(input, map[*i]);
	(*i)++;
	if ((!input->no_texture || !input->so_texture || !input->we_texture || !input->ea_texture || !input->fl \
		|| !input->ce) && map[*i])
		get_identifier(input, map, i);
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
			get_identifier(input, map, &i);
			break;
		}
	}
	map = NULL;
	*line = i;
}