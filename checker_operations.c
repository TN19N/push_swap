/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:39:33 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 08:55:13 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int	*a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	s(t_data *data, char c)
{
	if (c == 'a' && data->len_a >= 2)
		ft_swap(&data->a[0], &data->a[1]);
	else if (c == 'b' && data->len_b >= 2)
		ft_swap(&data->b[0], &data->b[1]);
	else if (c == 's' && data->len_b >= 2 && data->len_a >= 2)
	{
		s(data, 'a');
		s(data, 'b');
	}
}

void	p(t_data *data, char c)
{
	if (c == 'a' && data->len_b > 0)
	{
		increment_a2(data);
		data->a[0] = data->b[0];
		increment_b(data);
		data->len_a++;
		data->len_b--;
	}
	else if (c == 'b' && data->len_a > 0)
	{
		increment_b2(data);
		data->b[0] = data->a[0];
		increment_a(data);
		data->len_a--;
		data->len_b++;
	}
}

void	r(t_data *data, char c)
{
	data->t2 = 0;
	if (c == 'a')
	{
		data->t = data->a[0];
		while (++data->t2 < data->len_a)
			data->a[data->t2 - 1] = data->a[data->t2];
		data->a[data->t2 - 1] = data->t;
	}
	else if (c == 'b')
	{
		data->t = data->b[0];
		while (++data->t2 < data->len_b)
			data->b[data->t2 - 1] = data->b[data->t2];
		data->b[data->t2 - 1] = data->t;
	}
	else if (c == 'r')
	{
		r(data, 'a');
		r(data, 'b');
	}
}

void	rr(t_data *data, char c)
{
	if (c == 'a')
	{
		data->t2 = data->len_a;
		data->t = data->a[data->len_a - 1];
		while (--data->t2 > 0)
			data->a[data->t2] = data->a[data->t2 - 1];
		data->a[data->t2] = data->t;
	}
	else if (c == 'b')
	{
		data->t2 = data->len_b;
		data->t = data->b[data->len_b - 1];
		while (--data->t2 > 0)
			data->b[data->t2] = data->b[data->t2 - 1];
		data->b[data->t2] = data->t;
	}
	else if (c == 'r')
	{
		rr(data, 'a');
		rr(data, 'b');
	}
}