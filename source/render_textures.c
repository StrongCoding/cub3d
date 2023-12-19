/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:42:59 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 13:27:55 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_wall_hit(t_game *game)
{
	if (game->ray->side == 0)
		game->ray->wall_x = game->ray->pos_y
			+ game->ray->perp_wall_dist * game->ray->ray_dir_y;
	else
		game->ray->wall_x = game->ray->pos_x
			+ game->ray->perp_wall_dist * game->ray->ray_dir_x;
	game->ray->wall_x -= floor((game->ray->wall_x));
}

// calculate x coordinate on the texture
void	get_x_tex(t_game *game)
{
	game->ray->tex_x = (int)(game->ray->wall_x
			* (double)game->ray->tex[game->ray->direction]->width);
	if (game->ray->side == 0 && game->ray->ray_dir_x > 0)
		game->ray->tex_x = game->ray->tex[game->ray->direction]->width
			- game->ray->tex_x - 1;
	if (game->ray->side == 1 && game->ray->ray_dir_y < 0)
		game->ray->tex_x = game->ray->tex[game->ray->direction]->width
			- game->ray->tex_x - 1;
}

void	draw_textures(t_game *game, int x)
{
	int		color;
	int		y;
	double	step;
	double	tex_pos;

	step = 1.0 * game->ray->tex[game->ray->direction]->height
		/ game->ray->line_height;
	tex_pos = (game->ray->draw_start - game->win_height
			/ 2 + game->ray->line_height / 2) * step;
	y = game->ray->draw_start;
	while (y < game->ray->draw_end)
	{
		game->ray->tex_y = (int)tex_pos
			& (game->ray->tex[game->ray->direction]->height - 1);
		tex_pos += step;
		color = my_mlx_pixel_get(game->ray->img[game->ray->direction],
				game->ray->tex_x, game->ray->tex_y);
		if (game->ray->side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(game->img1, x, y, color);
		y++;
	}
}
