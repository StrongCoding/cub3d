/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:53:28 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/07 10:53:28 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_identifier(t_input *input)
{
	if (input->no_texture)
		free(input->no_texture);
	else if (input->so_texture)
		free(input->so_texture);
	else if (input->we_texture)
		free(input->we_texture);
	else if (input->ea_texture)
		free(input->ea_texture);
	else if (input->fl_color)
		free(input->fl_color);
	else if (input->ce_color)
		free(input->ce_color);
}

void	free_sprites(t_sprite **sprite)
{
	int i;

	i = 0;
	while(sprite[i])
	{
		free(sprite[i]);
		i++;
	}
	free(sprite);
}
