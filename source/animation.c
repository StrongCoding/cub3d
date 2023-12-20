/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:49:09 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/20 10:49:14 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_noah(t_game *game, int time_diff)
{
	game->ray->direction = 9;
	if (time_diff > FRAME_ANIMATION_TIME && time_diff
		< FRAME_ANIMATION_TIME + (FRAME_ANIMATION_TIME / 4))
		game->ray->direction = 10;
}

void	change_christmas(t_game *game, int time_diff)
{
	game->ray->direction = 5;
	if (time_diff > FRAME_ANIMATION_TIME && time_diff
		< FRAME_ANIMATION_TIME * 2)
		game->ray->direction = 6;
	else if (time_diff > FRAME_ANIMATION_TIME * 2 && time_diff
		< FRAME_ANIMATION_TIME * 3)
		game->ray->direction = 7;
	else if (time_diff > FRAME_ANIMATION_TIME * 3 && time_diff
		< FRAME_ANIMATION_TIME * 4)
		game->ray->direction = 8;
}

// change frame for animation if animation is 1
void	change_frame(t_game *game)
{
	int	time_diff;

	if (game->animation == 1)
	{
		time_diff = get_time() - game->time_frame;
		if (game->ray->direction == 0)
			change_christmas(game, time_diff);
		else if (game->ray->direction == 3)
			change_noah(game, time_diff);
		if (time_diff > FRAME_ANIMATION_TIME * 4)
			game->time_frame = get_time();
	}
}
