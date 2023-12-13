/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:40:22 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/13 15:09:23 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../parsing/cub2d.h"
# include "cub3d.h"

typedef struct s_sprite
{
	void	*img;
	int		width;
	int		height;
	char	*relative_path;
}				t_sprite;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_raycasting
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		camera_x;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int			side;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			direction;
	double		wall_x;
	t_sprite	**tex;
	int			tex_x;
	int			tex_y;

}				t_raycasting;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_image		*img1;
	t_image		*img2;
	int			win_height;
	int			win_width;
	int			x;
	int			y;
	int			exit_x;
	int			exit_y;
	int			ceiling_color;
	int			floor_color;
	t_sprite	*wall;
	char		**map;
	char		**map_copy;
	int			error;
	int			movements;
	int			frame;
	int			end;
	t_raycasting	*ray;
}				t_game;

typedef struct s_start
{
	int		count_rows;
	int 	count_cols;
	char	start_dir;
	int 	start_row;
	int 	start_col;
}				t_start;


typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef	struct s_map
{
	t_sprite	**textures;
	t_image		**img;
	t_color		fl_color;
	t_color		ce_color;
	char 		**map;
	t_start		start_pos;
}				t_map;


typedef struct s_input
{
	char	*no_texture;
	char 	*so_texture;
	char 	*we_texture;
	char 	*ea_texture;
	int 	*fl_color;
	int 	fl;
	int 	*ce_color;
	int 	ce;
	char 	**map;
	t_start	info;
	int 	exit;
}				t_input;

#endif