/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:40:09 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 13:24:11 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	closer_to_x(t_game *game)
{
	game->ray->side_dist_x += game->ray->delta_dist_x;
	game->ray->map_x += game->ray->step_x;
	game->ray->side = 0;
	if (game->ray->ray_dir_x < 0)
		game->ray->direction = 2;
	else
		game->ray->direction = 3;
}

void	closer_to_y(t_game *game)
{
	game->ray->side_dist_y += game->ray->delta_dist_y;
	game->ray->map_y += game->ray->step_y;
	game->ray->side = 1;
	if (game->ray->ray_dir_y < 0)
		game->ray->direction = 0;
	else
		game->ray->direction = 1;
}

// calculates lowest and highest pixel to fill in current stripe
void	calc_stripe(t_game *game)
{
	game->ray->draw_start = -game->ray->line_height / 2 + game->win_height / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = game->ray->line_height / 2 + game->win_height / 2;
	if (game->ray->draw_end >= game->win_height)
		game->ray->draw_end = game->win_height - 1;
}

// calculates height of line to draw on screen
void	calc_distance_and_height(t_game *game)
{
	if (game->ray->side == 0)
		game->ray->perp_wall_dist
			= (game->ray->side_dist_x - game->ray->delta_dist_x);
	else
		game->ray->perp_wall_dist
			= (game->ray->side_dist_y - game->ray->delta_dist_y);
	game->ray->line_height
		= (int)(game->win_height / game->ray->perp_wall_dist);
}

//jump to next map square, either in x-direction, or in y-direction
void	dda(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray->side_dist_x < game->ray->side_dist_y)
			closer_to_x(game);
		else
			closer_to_y(game);
		if (game->map[game->ray->map_x][game->ray->map_y] == '1')
			hit = 1;
		if (game->map[game->ray->map_x][game->ray->map_y] > '1' && game->door)
		{
			game->ray->direction = 4;
			hit = 1;
		}
	}
}
