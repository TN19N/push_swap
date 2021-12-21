/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:21:34 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 09:01:43 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_if_sorted2(t_data *data)
{
	int  i;

	i = -1;
	while (++i < data->len_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			break ;
	}
	if (i == data->len - 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_oper_and_error(data, data->oper, 1);
}

void	more_check(t_data *data, int i)
{
	if (!ft_strcmp(data->oper[i], "rra"))
		rr(data, 'a');
	else if (!ft_strcmp(data->oper[i], "rrb"))
		rr(data, 'b');
	else if (!ft_strcmp(data->oper[i], "rrr"))
		rr(data, 'r');
	else
		free_oper_and_error(data, data->oper, 0);
}

void	start_check(t_data *data)
{
	int	i;

	i = -1;
	while (data->oper[++i])
	{
		if (!ft_strcmp(data->oper[i], "sa"))
			s(data, 'a');
		else if (!ft_strcmp(data->oper[i], "sb"))
			s(data, 'b');
		else if (!ft_strcmp(data->oper[i], "ss"))
			s(data, 's');
		else if (!ft_strcmp(data->oper[i], "pa"))
			p(data, 'a');
		else if (!ft_strcmp(data->oper[i], "pb"))
			p(data, 'b');
		else if (!ft_strcmp(data->oper[i], "ra"))
			r(data, 'a');
		else if (!ft_strcmp(data->oper[i], "rb"))
			r(data, 'b');
		else if (!ft_strcmp(data->oper[i], "rr"))
			r(data, 'r');
		else
			more_check(data, i);
	}
	check_if_sorted2(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*tmp1;
	char 	*tmp2;

	if (ac < 2)
		exit(1);
	data.a = malloc(sizeof(int) * (ac - 1));
	if (!data.a)
		print_error();
	data.b = malloc(sizeof(int) * (ac - 1));
	if (!data.b)
		free_and_error(&data, 0);
	set_all(&data, av, ac);
	check_if_sorted(&data);
	tmp2 = NULL;
	while (1)
	{
		tmp1 = get_next_line(0);
		if (!tmp1)
			break ;
		tmp2 = ft_strjoin(tmp2, tmp1);
		free(tmp1);
		if (!tmp2)
			free_and_error(&data, 0);
	}
	data.oper = ft_split(tmp2, '\n');
	free(tmp2);
	if (!data.oper)
		free_and_error(&data, 0);
	start_check(&data);
	return (0);
}