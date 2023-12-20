/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:27:28 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/08 16:27:28 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int	pos_num(char *s, int *j)
{
	int	i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	*j = *j + i + 1;
	return (i);
}

int	ce_colors(t_input *input, char *map)
{
	char	*tmp;
	int		j;

	if (input->ce == 1)
		return (0);
	j = 1;
	while (++j < (int)ft_strlen(map))
	{
		if (!ft_isdigit(map[j]) && map[j] != ',')
			return (0);
		j++;
	}
	j = 2;
	tmp = ft_substr(map, 2, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->ce_color[0] = mod_atoi(tmp);
	free(tmp);
	if (input->ce_color[0] < 0 || input->ce_color[0] > 255)
		return (0);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->ce_color[1] = mod_atoi(tmp);
	free(tmp);
	if (input->ce_color[1] < 0 || input->ce_color[1] > 255)
		return (0);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->ce_color[2] = mod_atoi(tmp);
	free(tmp);
	if (input->ce_color[2] < 0 || input->ce_color[2] > 255)
		return (0);
	input->ce = 1;
	return (1);
}

int	fl_colors(t_input *input, char *map)
{
	char	*tmp;
	int		j;

	j = 1;
	while (++j < (int)ft_strlen(map))
	{
		if (!ft_isdigit(map[j]) && map[j] != ',' && map[j] != ' ')
			return (0);
		j++;
	}
	j = 2;
	tmp = ft_substr(map, j, pos_num(&map[2], &j));
	if (!tmp)
		return (0);
	input->fl_color[0] = mod_atoi(tmp);
	free(tmp);
	if (input->fl_color[0] < 0 || input->fl_color[0] > 255)
		return (0);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->fl_color[1] = mod_atoi(tmp);
	free(tmp);
	if (input->fl_color[1] < 0 || input->fl_color[1] > 255)
		return (0);
	tmp = ft_substr(&map[j], 0, pos_num(&map[j], &j));
	if (!tmp)
		return (0);
	input->fl_color[2] = mod_atoi(tmp);
	free(tmp);
	if (input->fl_color[2] < 0 || input->fl_color[2] > 255)
		return (0);
	input->fl = 1;
	return (1);
}
