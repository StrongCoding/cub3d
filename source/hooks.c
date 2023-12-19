/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:12:27 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 14:25:38 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	printf("key_code: %i\n", keycode);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_up(game);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(game);
	else if (keycode == KEY_SPACE)
		toggle(&game->door);
	else if (keycode == KEY_F)
		toggle(&game->print_fps);
	else if (keycode == KEY_I)
		toggle(&game->animation);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT)
		view_left(game);
	else if (keycode == KEY_RIGHT)
		view_right(game);
	else if (keycode == KEY_ESC)
		end_program(game);
	return (0);
}

int	key_hook_destroy(t_game *game)
{
	end_program(game);
	return (1);
}

//triggering after minimizing, so screen is not black
// int	expose_hook(t_game *game)
// {
// 	printf("exposing!\n");
// 	// ft_render_map(init->map, init);
// 	return (1);
// }
