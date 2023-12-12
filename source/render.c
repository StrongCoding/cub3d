/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:42:51 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/12 12:41:54 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//calculate ray position and direction
void	calc_ray_position_direction(t_game *game, int x)
{
	game->ray->camera_x = 2 * x
		/ (double)game->win_width - 1;
	game->ray->ray_dir_x = game->ray->dir_x
		+ game->ray->plane_x * game->ray->camera_x;
	game->ray->ray_dir_y = game->ray->dir_y
		+ game->ray->plane_y * game->ray->camera_x;
}

//length of ray from current position to next x or y-side
void	set_ray_length(t_game *game)
{
	if (game->ray->ray_dir_x == 0)
		game->ray->delta_dist_x = 1e30;
	else
		game->ray->delta_dist_x = fabs(1 / game->ray->ray_dir_x);
	if (game->ray->ray_dir_y == 0)
		game->ray->delta_dist_y = 1e30;
	else
		game->ray->delta_dist_y = fabs(1 / game->ray->ray_dir_y);
}

//calculate step and initial side Distance
//what direction to step in x or y-direction (either +1 or -1)
void	set_steps(t_game *game)
{
	if (game->ray->ray_dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_dist_x
			= (game->ray->pos_x - game->ray->map_x) * game->ray->delta_dist_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_dist_x = (game->ray->map_x
				+ 1.0 - game->ray->pos_x) * game->ray->delta_dist_x;
	}
	if (game->ray->ray_dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_dist_y
			= (game->ray->pos_y - game->ray->map_y) * game->ray->delta_dist_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_dist_y = (game->ray->map_y
				+ 1.0 - game->ray->pos_y) * game->ray->delta_dist_y;
	}
}

int	render(t_game *game)
{
	int	x;
	int	first;

	first = 1;
	// printf("starting loop\n");
	if (first)
		draw_ground_ceiling(game->img1, game);
	else
		draw_ground_ceiling(game->img2, game);

		x = 0;
		while (x < game->win_width)
		{
			calc_ray_position_direction(game, x);
			//which box of the map we're in
			game->ray->map_x = (int)game->ray->pos_x;
			game->ray->map_y = (int)game->ray->pos_y;
			set_ray_length(game);
			set_steps(game);
			dda(game);
			calc_distance_and_height(game);
			calc_stripe(game);
			int color = 0xFF8000;
			//give x and y sides different brightness
			if (game->ray->side == 1)
				color = color / 2;
			// if(game->ray->side == 2)
			// 	color = get_trgb(0, 255, 0, 0);
			// if(game->ray->side == 3)
			// 	color = get_trgb(0, 255, 0, 255);
			if (first)
				draw_vertical_line(x, game->ray->draw_start, game->ray->draw_end, color, game->img1);
			else
				draw_vertical_line(x, game->ray->draw_start, game->ray->draw_end, color, game->img2);
			x++;
		}
		if (first)
		{
			first = 0;
			mlx_put_image_to_window(game->mlx, game->win,
				game->img1->img, 0, 0);
		}
		else
		{
			first = 1;
			mlx_put_image_to_window(game->mlx, game->win,
				game->img2->img, 0, 0);
		}
	// printf("loop\n");
	usleep(1000);
	return (0);
	}
