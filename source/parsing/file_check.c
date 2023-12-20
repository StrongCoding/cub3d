/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:50:14 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/20 09:50:14 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	file_check(int count, t_input *input)
{
	int	fd;

	if (count == 0)
		fd = open(input->we_texture, O_RDONLY);
	else if (count == 1)
		fd = open(input->ea_texture, O_RDONLY);
	else if (count == 2)
		fd = open(input->no_texture, O_RDONLY);
	else if (count == 3)
		fd = open(input->so_texture, O_RDONLY);
	else
		fd = open("sprites/door.xpm", O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd);
	return (1);
}
