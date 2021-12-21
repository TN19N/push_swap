/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:32:06 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 06:58:01 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abc(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	ft_intsrch(t_data *data, int num, int t1)
{
	int	i;

	i = 0;
	while (i < t1)
	{
		if (num == data->tmp[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_pos_in_a(t_data *data, int index)
{
	int	i;

	i = -1;
	while (++i < data->len_a - 1)
	{
		if (data->b[index] > data->a[i] && \
			data->b[index] < data->a[i + 1])
			return (i + 1);
	}
	if (data->b[index] > data->a[data->len_a - 1] \
		&& data->b[index] < data->a[0])
		return (0);
	i = -1;
	data->t = 0;
	while (++i < data->len_a - 1)
	{
		if (data->a[data->t] < data->a[i + 1])
			data->t = i + 1;
	}
	return (data->t + 1);
}

int	*get_pos(t_data *data, int index)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * 2);
	if (!tmp)
		free_and_error(data, 0);
	if (index > data->len_b / 2)
		tmp[0] = index - data->len_b;
	else
		tmp[0] = index;
	tmp[1] = get_pos_in_a(data, index);
	if (tmp[1] > data->len_a / 2)
		tmp[1] = tmp[1] - data->len_a;
	return (tmp);
}

int	*best_next_move(t_data *data)
{
	int	*saver;
	int	*tmp;
	int	i;

	i = 0;
	saver = get_pos(data, 0);
	while (i < data->len_b)
	{
		tmp = get_pos(data, i);
		if (abc(saver[0]) + abc(saver[1]) > \
			abc(tmp[0]) + abc(tmp[1]))
		{
			saver[0] = tmp[0];
			saver[1] = tmp[1];
		}
		free(tmp);
		i++;
	}
	return (saver);
}
