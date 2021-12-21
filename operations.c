/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:56:26 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/20 16:48:56 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_data *data, char c, int i)
{
	if (c == 'a' && data->len_a >= 2)
	{
		ft_swap(&data->a[0], &data->a[1]);
		if (i == 1)
			write(1, "sa\n", 3);
	}
	else if (c == 'b' && data->len_b >= 2)
	{
		ft_swap(&data->b[0], &data->b[1]);
		if (i == 1)
			write(1, "sb\n", 3);
	}
	else if (c == 's' && data->len_b >= 2 && data->len_a >= 2)
	{
		s(data, 'a', 0);
		s(data, 'b', 0);
		write(1, "ss\n", 3);
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
		write(1, "pa\n", 3);
	}
	else if (c == 'b' && data->len_a > 0)
	{
		increment_b2(data);
		data->b[0] = data->a[0];
		increment_a(data);
		data->len_a--;
		data->len_b++;
		write(1, "pb\n", 3);
	}
}

void	r(t_data *data, char c, int j)
{
	data->t2 = 0;
	if (c == 'a')
	{
		data->t = data->a[0];
		while (++data->t2 < data->len_a)
			data->a[data->t2 - 1] = data->a[data->t2];
		data->a[data->t2 - 1] = data->t;
		if (j == 1)
			write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		data->t = data->b[0];
		while (++data->t2 < data->len_b)
			data->b[data->t2 - 1] = data->b[data->t2];
		data->b[data->t2 - 1] = data->t;
		if (j == 1)
			write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		r(data, 'a', 0);
		r(data, 'b', 0);
		write(1, "rr\n", 3);
	}
}

void	mini_function(t_data *data)
{
	rr(data, 'a', 0);
	rr(data, 'b', 0);
	write(1, "rrr\n", 4);
}

void	rr(t_data *data, char c, int j)
{
	if (c == 'a')
	{
		data->t2 = data->len_a;
		data->t = data->a[data->len_a - 1];
		while (--data->t2 > 0)
			data->a[data->t2] = data->a[data->t2 - 1];
		data->a[data->t2] = data->t;
		if (j == 1)
			write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		data->t2 = data->len_b;
		data->t = data->b[data->len_b - 1];
		while (--data->t2 > 0)
			data->b[data->t2] = data->b[data->t2 - 1];
		data->b[data->t2] = data->t;
		if (j == 1)
			write(1, "rrb\n", 4);
	}
	else if (c == 'r')
		mini_function(data);
}
