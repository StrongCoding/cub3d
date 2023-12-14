/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:12:27 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/14 14:04:58 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	printf("key_code: %i", keycode);
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_move_up(game);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_move_down(game);
	else if (keycode == KEY_SPACE)
		if (game->door)
			game->door = 0;
		else
			game->door = 1;
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_move_left(game);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_move_right(game);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		// ft_close_programm(init);
		exit(0);
	}
	return (0);
}

int	key_hook_destroy(t_game *game)
{
	// ft_close_programm(init);
	printf("exiting!\n");
	exit(0);
	return (1);
}

//triggering after minimizing, so screen is not black
int	expose_hook(t_game *game)
{
	printf("exposing!\n");
	// ft_render_map(init->map, init);
	return (1);
}