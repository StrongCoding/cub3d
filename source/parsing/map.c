/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:37:45 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/19 16:17:27 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static void	get_input(t_input *input, char **map, int length)
{
	find_identifier(input, map, &length);
	if (input->exit == 0)
		return ;
	input->map = get_map(input, map, length);
	if (!input->map)
	{
		input->exit = 0;
		return (free_identifier(input));
	}
}

static void	fill_input(t_input *input, char **map, int length)
{
	int	i;
	int	j;
	int	s_bool;

	j = 0;
	s_bool = 0;
	get_input(input, map, length);
	if (input->exit == 0)
		return ;
	while (input->map[j])
	{
		i = 0;
		while (input->map[j][i] != '\0')
		{
			if (!check_map(input->map, j, i, &s_bool))
				input->exit = 0;
			i++;
		}
		j++;
	}
	if (s_bool == 0 || !input->exit)
	{
		input->exit = 0;
		return (free_identifier(input), free_array(map));
	}
}

static void	get_file(int fd, t_input *input, char *name)
{
	int		line;
	int		length;
	char	**map;

	line = 0;
	length = map_length(name);
	map = ft_calloc(length + 1, sizeof(char *));
	if (!map)
		return ;
	while (line < length)
	{
		map[line] = get_next_line(fd);
		if (!map[line])
			return (free_array(map));
		line++;
	}
	fill_input(input, map, length);
}

t_input	read_map(char *name)
{
	t_input	input;
	int		fd;

	input.exit = 1;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		input.exit = 0;
		return (input);
	}
	get_file(fd, &input, name);
	close(fd);
	return (input);
}
