/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:54:24 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/12 11:42:47 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_direction(int *x_start, int *y_start, int *x_dest, int *y_dest)
{
	int	temp;

	if (*x_start > *x_dest)
	{
		temp = *x_start;
		*x_start = *x_dest;
		*x_dest = temp;
	}
	if (*y_start > *y_dest)
	{
		temp = *y_start;
		*y_start = *y_dest;
		*y_dest = temp;
	}
}

void	bresenham(t_image *img, int x_start, int y_start, int x_dest, int y_dest)
{
	int	delta_x;
	int	delta_y;
	int	error;
	int x;
	int y;

	check_direction(&x_start, &y_start, &x_dest, &y_dest);

	delta_x = x_dest - x_start;
	delta_y = y_dest - y_start;

	if (delta_x < 0)
		delta_x = -delta_x;
	if (delta_y < 0)
		delta_y = -delta_y;
	x = x_start;
	y = y_start;
	if (delta_x < delta_y)
	{
		error = delta_x / 2;
		while (x <= x_dest)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			error = error - delta_y;
			if (error <= 0)
				y = y + 1;
			error = error + delta_x;
			x++;
		}
	}
	else
	{
		error = delta_y / 2;
		while (y <= y_dest)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			error = error - delta_x;
			if (error <= 0)
				x = x + 1;
			error = error + delta_y;
			y++;
		}
	}
}
