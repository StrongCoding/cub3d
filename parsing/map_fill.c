/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:46:51 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/10 11:46:51 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static void	fill_collectible(t_vars *vars, int col, int row)
{
	static int	index;

	if (index % 5 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->cd, col, row);
	else if (index % 4 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->csa, col, row);
	else if (index % 3 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->csc, col, row);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->ch, col, row);
	index++;
}

static void	fill_map_position(t_vars *vars, int i, int y)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	while (vars->map[i][j])
	{
		if (vars->map[i][j] == '1')
			mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->w, x, y);
		else if (vars->map[i][j] == '0' || vars->map[i][j] == 'P')
			mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->s, x, y);
		else if (vars->map[i][j] == 'C')
			fill_collectible(vars, x, y);
		else if (vars->map[i][j] == 'E')
			mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->e, x, y);
		x = x + 64;
		j++;
	}
}

int	fill_map(t_vars *vars)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (vars->map[i] != NULL)
	{
		fill_map_position(vars, i, y);
		y = y + 64;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->p, vars->pos.x, vars->pos.y);
	return (0);
}

void	fill_last_position(t_vars *vars, int col, int row)
{
	if (vars->map[row / 64][col / 64] == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->w, col, row);
	}
	else if (vars->map[row / 64][col / 64] == '0' || \
			vars->map[row / 64][col / 64] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->s, col, row);
	}
	else if (vars->map[row / 64][col / 64] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, \
				vars->textures->e, col, row);
	}
}
