/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:41:56 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/18 09:41:56 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	map_length(char *name)
{
	int		length;
	int		fd;
	char	*line;

	length = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror(name);
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		length++;
	}
	close(fd);
	return (length);
}

/*int	map_first_line(char **map)
{
	int	line;

	line = 0;
	while (map[line] && map[line][0] == '\n')
		line++;
	return (line);
}*/

/*int	map_last_line(char **map, int length)
{
	while (map[length] && map[length][0] == '\n')
		length--;
	return (length);
}*/
