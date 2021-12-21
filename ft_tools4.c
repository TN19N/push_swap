/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:04:30 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 07:44:56 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	increment_a2(t_data *data)
{
	int	i;

	i = data->len_a - 1;
	while (i >= 0)
	{
		data->a[i + 1] = data->a[i];
		i--;
	}
}

void	increment_a(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->len_a)
	{
		data->a[i - 1] = data->a[i];
		i++;
	}
}

void	increment_b2(t_data *data)
{
	int	i;

	i = data->len_b - 1;
	while (i >= 0)
	{
		data->b[i + 1] = data->b[i];
		i--;
	}
}

void	increment_b(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->len_b)
	{
		data->b[i - 1] = data->b[i];
		i++;
	}
}
