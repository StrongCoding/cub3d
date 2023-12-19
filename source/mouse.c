/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:36:06 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 17:19:38 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_movement(t_game *game)
{
	mlx_mouse_get_pos(game->mlx, game->win, &game->mouse_x, &game->mouse_y);
	if (game->mouse_x < game->win_width / 2)
		view_left(game);
	else if (game->mouse_x > game->win_width / 2)
		view_right(game);
	mlx_mouse_move(game->mlx, game->win,
		game->win_width / 2, game->win_height / 2);
}
