/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:34:39 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/19 15:51:05 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB2D_H
# define CUB2D_H

# include "../ft_printf/ft_printf.h"
# include "cub3d.h"
# include "structs.h"
# include <stdlib.h>

t_input		read_map(char *name);
int			ending_cub(char *name);
int			map_length(char *name);
void		find_identifier(t_input *input, char **map, int *line);
void		get_identifier_two(t_input *input, char **map, int *i, int bool);
int			fl_colors(t_input *input, char *map);
int			ce_colors(t_input *input, char *map);
int			mod_atoi(const char *str);
char		**get_map(t_input *input, char **file, int line);
int			check_map(char **file, int row, int col, int *s_bool);
int			valid_char(char c);
int			convert_struct(t_input *input, t_map *map, t_game *game);
int			file_check(t_input *input);
void		fill_image(t_map *map, t_game *game, int count);
void		free_array(char **array);
void		free_identifier(t_input *input);
void		free_sprites(t_sprite **sprite);
void		free_image(t_map *map, t_game *game, int count);

#endif