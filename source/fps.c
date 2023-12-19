/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:18:40 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/14 17:53:52 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// return current time in milliseconds
unsigned long long	get_time(void)
{
	struct timeval			time;
	unsigned long long		milliseconds;

	if (gettimeofday(&time, NULL))
		return (perror("Time error"), 0);
	milliseconds = time.tv_usec / 1000 + time.tv_sec * 1000;
	return (milliseconds);
}

// print fps on screen if print_fps is 1
void	print_fps(t_game *game)
{
	char	*fps_string;
	char	*tmp;
	
	if (game->print_fps == 1)
	{
		tmp = ft_itoa(game->fps);
		fps_string = ft_strjoin("fps: ", tmp);
		free(tmp);
		mlx_string_put(game->mlx, game->win, WIN_WIDTH - 80, 20, get_trgb(0, 0, 0, 0), fps_string);
		free(fps_string);
	}
	game->fps = 10000 / (int)(get_time() - game->time);
	game->time = get_time();
}
