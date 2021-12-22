/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 06:56:56 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 11:28:26 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_data *data)
{
	unsigned long	num;
	int				o;
	int				i;

	o = 1;
	num = 0;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			o *= -1;
	while (*str >= '0' && *str <= '9')
	{
		i = 1;
		num = (num * 10) + (*str - '0');
		if (num > 2147483647 && o > 0)
			free_and_error(data, 0);
		if (num > 2147483648 && o < 0)
			free_and_error(data, 0);
		str++;
	}
	if (i == 0)
		free_and_error(data, 0);
	return ((int)num * o);
}
