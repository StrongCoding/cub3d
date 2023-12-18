/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:11:38 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/14 12:36:33 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// rotation camera plane and and direction
int	ft_move_right(t_game *game)
{
	double old_dir_x;
	double old_plane_x;
	double rot_speed;

	//maybe with key press and key release hook smoth movement can be achieved
	rot_speed = 0.2;
	old_dir_x = game->ray->dir_x;
	game->ray->dir_x = game->ray->dir_x * cos(-rot_speed) - game->ray->dir_y * sin(-rot_speed);
	game->ray->dir_y = old_dir_x * sin(-rot_speed) + game->ray->dir_y * cos(-rot_speed);
	old_plane_x = game->ray->plane_x;
	game->ray->plane_x = game->ray->plane_x * cos(-rot_speed) - game->ray->plane_y * sin(-rot_speed);
	game->ray->plane_y = old_plane_x * sin(-rot_speed) + game->ray->plane_y * cos(-rot_speed);
	printf("move right\n");
	return (0);
}

// rotation camera plane and and direction
int	ft_move_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = 0.2;
	old_dir_x = game->ray->dir_x;
	game->ray->dir_x = game->ray->dir_x * cos(rot_speed) - game->ray->dir_y * sin(rot_speed);
	game->ray->dir_y = old_dir_x * sin(rot_speed) + game->ray->dir_y * cos(rot_speed);
	old_plane_x = game->ray->plane_x;
	game->ray->plane_x = game->ray->plane_x * cos(rot_speed) - game->ray->plane_y * sin(rot_speed);
	game->ray->plane_y = old_plane_x * sin(rot_speed) + game->ray->plane_y * cos(rot_speed);
	printf("move left\n");
	return (0);
}

int	ft_move_up(t_game *game)
{
	double	move_speed;

	move_speed = 0.3;
	if (game->map[(int)(game->ray->pos_x + game->ray->dir_x * move_speed)][(int)game->ray->pos_y] == '0')
		game->ray->pos_x += game->ray->dir_x * move_speed;
	if (game->map[(int)game->ray->pos_x][(int)(game->ray->pos_y + game->ray->dir_y * move_speed)] == '0')
		game->ray->pos_y += game->ray->dir_y * move_speed;
	printf("move up\n");
	return (0);
}

int	ft_move_down(t_game *game)
{
	double	move_speed;

	move_speed = 0.3;
	if (game->map[(int)(game->ray->pos_x - game->ray->dir_x * move_speed)][(int)game->ray->pos_y] == '0')
		game->ray->pos_x -= game->ray->dir_x * move_speed;
	if (game->map[(int)game->ray->pos_x][(int)(game->ray->pos_y - game->ray->dir_y * move_speed)] == '0')
		game->ray->pos_y -= game->ray->dir_y * move_speed;
	printf("move down\n");
	return (0);
}
