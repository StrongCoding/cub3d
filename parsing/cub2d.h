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

typedef struct s_input
{
	char	*no_texture;
	char 	*so_texture;
	char 	*we_texture;
	char 	*ea_texture;
	int 	*fl_color;
	int 	*ce_color;
	char 	***map;
	int 	exit;
}				t_input;

t_input 		read_map(char *name);
int				main(int argc, char **argv);
int				map_check_line(int line, char *map, int length);
int				map_length(char *name);
void			find_identifier(t_input *input, char **map, int *line);
void			free_array(char **array);

#endif