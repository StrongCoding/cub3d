/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:17:33 by nschutz           #+#    #+#             */
/*   Updated: 2023/12/20 12:17:33 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

static int		ft_recursive_str_to_int(const char *str, int *number);

int	mod_atoi(const char *str)
{
	int		i;
	int		count_minus;
	int		number;

	i = 0;
	count_minus = 0;
	number = 0;
	if (!str[0])
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str [i] == '+')
		if (str[i++] == '-')
			count_minus++;
	if (!(str[i] >= '0' && str [i] <= '9'))
		return (0);
	ft_recursive_str_to_int(&str[i], &number);
	if (((!(count_minus % 2)) || number == -2147483648))
		return (number);
	else if ((i) && (count_minus % 2))
		return (number * -1);
	else
		return (-1);
}

static int	ft_recursive_str_to_int(const char *str, int *number)
{
	if (!str[0])
		return (0);
	if (!(str[0] >= '0' && str[0] <= '9'))
		return (0);
	if (str[0] >= '0' && str[0] <= '9')
		*number = *number * 10 + str[0] - '0';
	ft_recursive_str_to_int(&str[1], number);
	return (0);
}