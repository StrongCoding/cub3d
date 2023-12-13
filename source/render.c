/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:42:51 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/13 15:12:53 by dnebatz          ###   ########.fr       */
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
	int buffer[game->win_height][game->win_width];

	first = 1;
	// printf("starting loop\n");
	// if (first)
		draw_ground_ceiling(game->img1, game);
	// else
	// 	draw_ground_ceiling(game->img2, game);

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

		if(game->ray->side == 0)
			game->ray->wall_x = game->ray->pos_y + game->ray->perp_wall_dist * game->ray->ray_dir_y;
		else
			game->ray->wall_x = game->ray->pos_x + game->ray->perp_wall_dist * game->ray->ray_dir_x;
		game->ray->wall_x -= floor((game->ray->wall_x));

		//x coordinate on the texture
		game->ray->tex_x = (int)game->ray->wall_x * (double)game->ray->tex[game->ray->direction]->width;
		if(game->ray->side == 0 && game->ray->ray_dir_x > 0)
			game->ray->tex_x = game->ray->tex[game->ray->direction]->width - game->ray->tex_x - 1;
		if(game->ray->side == 1 && game->ray->ray_dir_y < 0)
			game->ray->tex_x = game->ray->tex[game->ray->direction]->width - game->ray->tex_x - 1;

		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * game->ray->tex[game->ray->direction]->height / game->ray->line_height;
		int	pitch = 0;
		// Starting texture coordinate
		double tex_pos = (game->ray->draw_start - pitch - game->win_height / 2 + game->ray->line_height / 2) * step;
		int color;
		for(int y = game->ray->draw_start; y < game->ray->draw_end; y++)
		{
		// Cast the texture coordinate to integer, and mask with (tex_height - 1) in case of overflow
		int tex_y = (int)tex_pos & (game->ray->tex[game->ray->direction]->height - 1);
		tex_pos += step;
		color = my_mlx_pixel_get(game->ray->tex[game->ray->direction]->img, game->ray->tex_x, game->ray->tex_y);
		// color = texture[game->ray->direction][tex_height * tex_y + tex_x];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(game->ray->side == 1)
			color = (color >> 1) & 8355711;
		buffer[y][x] = color;
		}

			
			// int color = 0xFF8000; // 0 west
			// if (game->ray->direction == 1) // east
			// 	color = color / 2;
			// if (game->ray->direction == 2)	//north
			// 	color = get_trgb(0, 255, 0, 0);
			// if (game->ray->direction == 3)
			// 	color = get_trgb(0, 255, 0, 255); // south
			// if (first)
				draw_vertical_line(x, game->ray->draw_start, game->ray->draw_end, color, game->img1);
			// else
			// 	draw_vertical_line(x, game->ray->draw_start, game->ray->draw_end, color, game->img2);
			x++;

		// printf("side: %d dir_y: %f dir_x: %f\n", game->ray->side, game->ray->dir_y, game->ray->dir_x);	
		}
		// if (first)
		// {
		// 	first = 0;
			mlx_put_image_to_window(game->mlx, game->win,
				game->img1->img, 0, 0);
		// }
		// else
		// {
		// 	first = 1;
		// 	mlx_put_image_to_window(game->mlx, game->win,
		// 		game->img2->img, 0, 0);
		// }
	// printf("loop\n");
	usleep(1000);
	return (0);
	}
