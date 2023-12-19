/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:06:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/12/19 13:14:27 by dnebatz          ###   ########.fr       */
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
# include <sys/time.h>

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
# define KEY_M		109
# define KEY_I		105
# define KEY_F		102
# define KEY_ESC	65307
# define KEY_SPACE  32

# define FOV		0.66
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# define MAP_PLAYER	10
# define MAP_WALL	10

# define FRAME_ANIMATION_TIME	100

# define ROT_SPEED 0.2
# define MOVE_SPEED 0.3



int					key_hook(int keycode, t_game *game);
int					key_hook_destroy(t_game *game);
int					expose_hook(t_game *game);
void				init_struct(t_game *game);
int					move_right(t_game *game);
int					move_left(t_game *game);
int					move_up(t_game *game);
int					move_down(t_game *game);
t_sprite			*ft_newsprite(char *content);
void				init_win(t_game *game);
void				put_square(t_image *img);
int					get_trgb(int t, int r, int g, int b);
void				my_mlx_pixel_put(t_image *img, int x, int y, int color);
void				dda(t_game *game);
int					render(t_game *game);
void				draw_ground_ceiling(t_image *img, t_game *game);
void				init_image(t_game *game, t_image *img);
void				calc_distance_and_height(t_game *game);
void				calc_stripe(t_game *game);
int					my_mlx_pixel_get(t_image *img, int x, int y);
void				minimap(t_game *game);
void				draw_mm_player(t_game *game, t_minimap *mm);
void				draw_mm_wall(t_game *game, t_minimap *mm, int k);
void				draw_mm_space(t_game *game, t_minimap *mm, int k);
void				draw_mm_door(t_game *game, t_minimap *mm, int k);
void				draw_textures(t_game *game, int x);
void				set_wall_hit(t_game *game);
void				get_x_tex(t_game *game);
int					mouse_hook(t_game *game);
void				mouse_movement(t_game *game);
unsigned long long	get_time(void);
void				print_fps(t_game *game);
void				toggle(int *var);
int					view_left(t_game *game);
int					view_right(t_game *game);

#endif