/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:11:38 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 12:52:01 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// rotation camera plane and and direction
int	move_right(t_game *game)
{
	if (game->map[(int)(game->ray->pos_x + game->ray->dir_y * MOVE_SPEED)][(int)(game->ray->pos_y)] == '0')
		game->ray->pos_x += game->ray->dir_y * MOVE_SPEED;
	if (game->map[(int)(game->ray->pos_x)][(int)(game->ray->pos_y - game->ray->dir_x * MOVE_SPEED)] == '0')
		game->ray->pos_y -= game->ray->dir_x * MOVE_SPEED;
	return (0);
}

// rotation camera plane and and direction
int	move_left(t_game *game)
{
	if (game->map[(int)(game->ray->pos_x - game->ray->dir_y * MOVE_SPEED)][(int)(game->ray->pos_y)] == '0')
		game->ray->pos_x -= game->ray->dir_y * MOVE_SPEED;
	if (game->map[(int)(game->ray->pos_x)][(int)(game->ray->pos_y + game->ray->dir_x * MOVE_SPEED)] == '0')
		game->ray->pos_y += game->ray->dir_x * MOVE_SPEED;
	return (0);
}

int	move_up(t_game *game)
{
	if (game->map[(int)(game->ray->pos_x + game->ray->dir_x * MOVE_SPEED)][(int)game->ray->pos_y] == '0' )
		game->ray->pos_x += game->ray->dir_x * MOVE_SPEED;
	else if (game->map[(int)(game->ray->pos_x + game->ray->dir_x * MOVE_SPEED)][(int)game->ray->pos_y] == '2' && !game->door)
		game->ray->pos_x += game->ray->dir_x * MOVE_SPEED;
	if (game->map[(int)game->ray->pos_x][(int)(game->ray->pos_y + game->ray->dir_y * MOVE_SPEED)] == '0')
		game->ray->pos_y += game->ray->dir_y * MOVE_SPEED;
	else if (game->map[(int)game->ray->pos_x][(int)(game->ray->pos_y + game->ray->dir_y * MOVE_SPEED)] == '2' && !game->door)
		game->ray->pos_y += game->ray->dir_y * MOVE_SPEED;
	return (0);
}

int	move_down(t_game *game)
{
	if (game->map[(int)(game->ray->pos_x - game->ray->dir_x * MOVE_SPEED)][(int)game->ray->pos_y] == '0')
		game->ray->pos_x -= game->ray->dir_x * MOVE_SPEED;
	else if (game->map[(int)(game->ray->pos_x - game->ray->dir_x * MOVE_SPEED)][(int)game->ray->pos_y] == '2' && !game->door)
		game->ray->pos_x -= game->ray->dir_x * MOVE_SPEED;
	if (game->map[(int)game->ray->pos_x][(int)(game->ray->pos_y - game->ray->dir_y * MOVE_SPEED)] == '0')
		game->ray->pos_y -= game->ray->dir_y * MOVE_SPEED;
	else if (game->map[(int)game->ray->pos_x][(int)(game->ray->pos_y - game->ray->dir_y * MOVE_SPEED)] == '2' && !game->door)
		game->ray->pos_y -= game->ray->dir_y * MOVE_SPEED;
	return (0);
}
