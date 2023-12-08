/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:41:55 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/07 10:41:55 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int	ending_cub(char *name)
{
	size_t	len;

	len = ft_strlen(name) - 1;
	if (name[len] != 'b' || name[len - 1] != 'u' || \
		name[len - 2] != 'c' || name[len - 3] != '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (!ending_cub(argv[1]))
		return (ft_printf("Error\nInvalid map"));
	read_map(argv[1]);
	return (argc);
}
