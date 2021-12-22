/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:58:28 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 13:49:00 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	just_three(t_data *data)
{
	int	t1;
	int	t2;
	int	t3;

	t1 = data->a[0];
	t2 = data->a[1];
	t3 = data->a[2];
	if (t1 > t2 && t2 < t3 && t3 > t1)
		s(data, 'a', 1);
	else if (t1 > t2 && t2 < t3 && t3 < t1)
		r(data, 'a', 1);
	else if (t1 > t2 && t2 > t3 && t3 < t1)
	{
		s(data, 'a', 1);
		rr(data, 'a', 1);
	}
	else if (t1 < t2 && t2 > t3 && t3 < t1)
		rr(data, 'a', 1);
	else if (t1 < t2 && t2 > t3 && t3 > t1)
	{
		s(data, 'a', 1);
		r(data, 'a', 1);
	}
}

void	last_step(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_a)
	{
		if (data->a[i] == 0)
			break ;
		i++;
	}
	if (i > data->len_a / 2)
	{
		while (data->a[0] != 0)
			rr(data, 'a', 1);
	}
	else
		while (data->a[0] != 0)
			r(data, 'a', 1);
}

void	start_steps(t_data *data)
{
	first_step(data);
	secend_step(data);
	third_step(data);
	last_step(data);
}

void	set_all(t_data *data, char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		data->a[i - 1] = ft_atoi(av[i], data);
		i++;
	}
	data->len = ac - 1;
	data->len_a = data->len;
	data->len_b = 0;
	data->min = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		exit(1);
	data.a = malloc(sizeof(int) * (ac - 1));
	if (!data.a)
		print_error();
	data.b = malloc(sizeof(int) * (ac - 1));
	if (!data.b)
		free_and_error(&data, 0);
	set_all(&data, av, ac);
	check_and_convert(&data);
	check_if_sorted(&data);
	if (data.len_a == 3)
		just_three(&data);
	else if (data.len_a == 5)
		just_five(&data);
	else
		start_steps(&data);
	return (0);
}
