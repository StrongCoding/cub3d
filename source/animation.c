/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:49:09 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 20:44:40 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// change frame for animation if animation is 1
void	change_frame(t_game *game)
{
	int	time_diff;

	if (game->animation == 1)
	{
		// printf("animation going!\n");
	// add check for which animated sprite should be changed
	// if (game->ray->direction == 0) for north for example
		time_diff = get_time() - game->time_frame;
		printf("time diff: %d\n", time_diff);
		game->ray->direction = 5;
		if (time_diff > FRAME_ANIMATION_TIME && time_diff < FRAME_ANIMATION_TIME * 2)
			game->ray->direction = 6;
		else if (time_diff > FRAME_ANIMATION_TIME * 2 && time_diff < FRAME_ANIMATION_TIME * 3)
			game->ray->direction = 7;
		else if (time_diff > FRAME_ANIMATION_TIME * 3 && time_diff < FRAME_ANIMATION_TIME * 4)
			game->ray->direction = 8;
		else if (time_diff > FRAME_ANIMATION_TIME * 4)
			game->time_frame = get_time();
		// else if (time_diff > FRAME_ANIMATION_TIME * 4 && time_diff < FRAME_ANIMATION_TIME * 5)
		// 	game->ray->direction = 8;
		// game->ray->direction = 7;
		// else if (time_diff > FRAME_ANIMATION_TIME * 6 && time_diff < FRAME_ANIMATION_TIME * 7)
		// 	game->ray->direction = 10;
		// else if (time_diff > FRAME_ANIMATION_TIME * 7 && time_diff < FRAME_ANIMATION_TIME * 8)
		// 	game->ray->direction = 11;
		// else if (time_diff > FRAME_ANIMATION_TIME * 8 && time_diff < FRAME_ANIMATION_TIME * 9)
		// 	game->ray->direction = 12;
		// else if (time_diff > FRAME_ANIMATION_TIME * 9 && time_diff < FRAME_ANIMATION_TIME * 10)
		// 	game->ray->direction = 13;
		// else if (time_diff > FRAME_ANIMATION_TIME * 10 && time_diff < FRAME_ANIMATION_TIME * 11)
		// 	game->ray->direction = 14;
		// else if (time_diff > FRAME_ANIMATION_TIME * 11 && time_diff < FRAME_ANIMATION_TIME * 12)
		// 	game->ray->direction = 15;
		// else if (time_diff > FRAME_ANIMATION_TIME * 12 && time_diff < FRAME_ANIMATION_TIME * 13)
		// 	game->ray->direction = 16;
		// else if (time_diff > FRAME_ANIMATION_TIME * 13 && time_diff < FRAME_ANIMATION_TIME * 14)
		// 	game->ray->direction = 17;
		// else if (time_diff > FRAME_ANIMATION_TIME * 14 && time_diff < FRAME_ANIMATION_TIME * 15)
		// 	game->ray->direction = 18;
		// else if (time_diff > FRAME_ANIMATION_TIME * 15 && time_diff < FRAME_ANIMATION_TIME * 16)
		// 	game->ray->direction = 19;
		// else if (time_diff > FRAME_ANIMATION_TIME * 16 && time_diff < FRAME_ANIMATION_TIME * 17)
		// 	game->ray->direction = 20;
	}
}
