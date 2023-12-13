/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/12 20:12:13 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../parsing/cub2d.h"
# include "structs.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define WALL		49
# define GROUND		48
# define COIN		67
# define GHOST		80
# define GHOSTR		82
# define EXIT		69
# define EXITU		85
# define TRAP		84

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define KEY_Q		113
# define KEY_ESC	65307


int			key_hook(int keycode, t_game *game);
int			key_hook_destroy(t_game *game);
int			expose_hook(t_game *game);
void		init_struct(t_game *game);
int			ft_move_right(t_game *game);
int			ft_move_left(t_game *game);
int			ft_move_up(t_game *game);
int			ft_move_down(t_game *game);
t_sprite	*ft_newsprite(char *content);
void		init_win(t_game *game);
void		put_square(t_image *img);
int			get_trgb(int t, int r, int g, int b);
void		bresenham(t_image *img, int x_start, int y_start, int x_dest, int y_dest);
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
void		draw_vertical_line(int x, int y_start, int y_end, int color, t_image *img);
void		dda(t_game *game);
int			render(t_game *game);
void		draw_ground_ceiling(t_image *img, t_game *game);
void		init_image(t_game *game, t_image *img);
void		calc_distance_and_height(t_game *game);
void		calc_stripe(t_game *game);

#endif