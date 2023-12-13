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
# include "../includes/cub3d.h"
# include "../includes/structs.h"
# include <stdlib.h>

t_input 		read_map(char *name);
int				ending_cub(char *name);
int				map_length(char *name);
void			find_identifier(t_input *input, char **map, int *line);
int				fl_colors(t_input *input, char *map);
int				ce_colors(t_input *input, char *map);
char			**get_map(t_input *input, char **file, int line);
int				check_map(char **file, int row, int col, int *s_bool);
int				valid_char(char c);
int 			convert_struct(t_input *input, t_map *map, t_game *game);
void			free_array(char **array);
void			free_identifier(t_input *input);
void			free_sprites(t_sprite **sprite);


#endif