/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:34:39 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/07 10:34:39 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB2D_H
# define CUB2D_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>

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
	void	*no_text;
	void 	*so_tex;
	void 	*we_tex;
	void 	*ea_tex;
	t_color	fl_color;
	t_color	ce_color;
	char 	**map;
	t_start	info;
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

t_input 		read_map(char *name);
int				main(int argc, char **argv);
int				map_length(char *name);
void			find_identifier(t_input *input, char **map, int *line);
int				fl_colors(t_input *input, char *map);
int				ce_colors(t_input *input, char *map);
char			**get_map(t_input *input, char **file, int line);
int				check_map(char **file, int row, int col, int *s_bool);
int				valid_char(char c);
int 			convert_struct(t_input *input);
void			free_array(char **array);
void			free_identifier(t_input *input);


#endif