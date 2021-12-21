/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:32:41 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/20 20:00:52 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_lis(t_data *data)
{
	int	i;
	int	tmp2;
	int	j;
	int	**tmp;

	data->t2 = 0;
	tmp = ft_malloc(data);
	i = -1;
	while (++i < data->len)
	{
		data->t = 0;
		j = -1;
		while (++j <= i)
		{
			if (data->a[i] >= data->a[j] && chek_b(tmp[i], data->a[j], data->t))
			{
				tmp[i][data->t] = data->a[j];
				data->t++;
			}
		}
		save_the_longest(data, &tmp2, i);
	}
	data->tmp = alloci_and_free(data, tmp, tmp2);
}

void	first_step(t_data *data)
{
	if (data->min > data->len / 2)
	{
		while (data->a[0] != 0)
			rr(data, 'a', 1);
	}
	else
	{
		while (data->a[0] != 0)
			r(data, 'a', 1);
	}
}

void	secend_step(t_data *data)
{
	int	i;
	int	t[2];

	find_lis(data);
	i = 0;
	t[0] = data->t2;
	while (i < data->len_a)
	{
		if (!ft_intsrch(data, data->a[i], t[0]) && i == 0)
			p(data, 'b');
		else if (!ft_intsrch(data, data->a[i], t[0]) && i != 0)
		{
			t[1] = data->a[i];
			if (i <= data->len_a / 2)
				while (data->a[0] != t[1])
					r(data, 'a', 1);
			else
				while (data->a[0] != t[1])
					rr(data, 'a', 1);
			i = 0;
		}
		else
			i++;
	}
	free(data->tmp);
}

void	third_step(t_data *data)
{
	int	*ptr;

	while (data->len_b > 0)
	{
		ptr = best_next_move(data);
		if (ptr[0] * ptr[1] > 0)
			do_operations(data, ptr);
		else
			do_operations2(data, ptr);
		p(data, 'a');
		free(ptr);
	}
}

void	just_five(t_data *data)
{
	p(data, 'b');
	p(data, 'b');
	just_three(data);
	if (data->b[0] == 0)
		p(data, 'a');
	else if (data->b[1] == 0)
	{
		s(data, 'b', 1);
		p(data, 'a');
	}
	third_step(data);
	last_step(data);
}