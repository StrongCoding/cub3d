/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:26:12 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 12:50:17 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// rotation camera plane and and direction
int	view_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ray->dir_x;
	game->ray->dir_x = game->ray->dir_x
		* cos(ROT_SPEED) - game->ray->dir_y * sin(ROT_SPEED);
	game->ray->dir_y = old_dir_x
		* sin(ROT_SPEED) + game->ray->dir_y * cos(ROT_SPEED);
	old_plane_x = game->ray->plane_x;
	game->ray->plane_x = game->ray->plane_x
		* cos(ROT_SPEED) - game->ray->plane_y * sin(ROT_SPEED);
	game->ray->plane_y = old_plane_x
		* sin(ROT_SPEED) + game->ray->plane_y * cos(ROT_SPEED);
	return (0);
}

// rotation camera plane and and direction
int	view_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ray->dir_x;
	game->ray->dir_x = game->ray->dir_x
		* cos(-ROT_SPEED) - game->ray->dir_y * sin(-ROT_SPEED);
	game->ray->dir_y = old_dir_x
		* sin(-ROT_SPEED) + game->ray->dir_y * cos(-ROT_SPEED);
	old_plane_x = game->ray->plane_x;
	game->ray->plane_x = game->ray->plane_x
		* cos(-ROT_SPEED) - game->ray->plane_y * sin(-ROT_SPEED);
	game->ray->plane_y = old_plane_x
		* sin(-ROT_SPEED) + game->ray->plane_y * cos(-ROT_SPEED);
	return (0);
}
