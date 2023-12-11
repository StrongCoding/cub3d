/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:27 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/11 15:39:27 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int convert_struct(t_input *input)
{
	t_map	map;

	/*map.no_text;
	map.so_tex;
	map.we_tex; get_mlx_pointer;
	map.ea_tex; */
	map.fl_color.r = input->fl_color[0];
	map.fl_color.g = input->fl_color[1];
	map.fl_color.b = input->fl_color[2];
	map.ce_color.r = input->ce_color[0];
	map.ce_color.g = input->ce_color[1];
	map.ce_color.b = input->ce_color[2];
	map.map = &input->map;
	map.info = input->info;
	return (1);
}
