/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:05:53 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 11:28:36 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int	*a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	**ft_malloc(t_data *data)
{
	int	**tmp;
	int	i;

	i = -1;
	tmp = malloc(sizeof(int *) * data->len);
	if (!tmp)
		free_and_error(data, 0);
	while (++i < data->len)
	{
		tmp[i] = malloc(sizeof(int) * data->len);
		if (!tmp[i])
			free_tab_and_err(data, tmp, i, 0);
	}
	return (tmp);
}

int	*alloci_and_free(t_data *data, int **tmp, int tmp2)
{
	int	*tmp_a;

	tmp_a = malloc(sizeof(int) * data->t2);
	if (!tmp_a)
		free_tab_and_err(data, tmp, data->len, 0);
	copy_arr(tmp_a, tmp[tmp2], data->t2);
	free_tab_and_err(data, tmp, data->len, 1);
	return (tmp_a);
}

void	save_the_longest(t_data *data, int *tmp2, int i)
{
	if (data->t > data->t2)
	{
		data->t2 = data->t;
		*tmp2 = i;
	}
}
