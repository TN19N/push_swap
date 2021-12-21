/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:15:11 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 08:56:10 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len_a - 1 && data->len_a == data->len)
	{
		j = i + 1;
		if (data->a[i] > data->a[j])
			break ;
		i++;
	}
	if (i == data->len_a - 1)
		free_and_error(data, 1);
}

void	mini_set(int len, int *end, int *tmp, int i)
{
	if (i == -1)
	{
		*tmp = len - 1;
		*end = 0;
	}
	else if (i == 1)
	{
		*tmp = 0;
		*end = len - 1;
	}
}

void	copy_arr(int *arr1, int *arr2, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr1[i] = arr2[i];
		i++;
	}
}

void	convert(t_data *data)
{
	int	*tmp2;
	int	i;
	int	j;

	i = -1;
	tmp2 = malloc(sizeof(int) * data->len);
	if (!tmp2)
	{
		free(data->tmp);
		free_and_error(data, 0);
	}
	while (++i < data->len)
	{
		j = -1;
		while (++j < data->len)
		{
			if (data->a[i] == data->tmp[j])
				tmp2[i] = j;
		}
		if (data->a[i] < data->a[data->min])
			data->min = i;
	}
	free(data->tmp);
	copy_arr(data->a, tmp2, data->len);
	free(tmp2);
}

void	check_and_convert(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->tmp = malloc(sizeof(int) * data->len);
	if (!data->tmp)
		free_and_error(data, 0);
	copy_arr(data->tmp, data->a, data->len);
	while (++i < data->len)
	{
		j = i;
		while (++j < data->len)
		{
			if (data->tmp[i] == data->tmp[j])
			{
				free(data->tmp);
				free_and_error(data, 0);
			}
			if (data->tmp[i] > data->tmp[j])
				ft_swap(&data->tmp[i], &data->tmp[j]);
		}
	}
	convert(data);
}
