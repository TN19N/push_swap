/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:48:23 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 15:42:17 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_and_error(t_data *data, int i)
{
	if (data->a)
		free(data->a);
	if (data->b)
		free(data->b);
	if (i == 0)
		print_error();
	else if (i == 1)
		exit(0);
}

void	free_for_tmps(char *tmp1, char *tmp2, t_data *data)
{
	if (tmp1)
		free(tmp1);
	if (tmp2)
		free(tmp2);
	free_and_error(data, 0);
}

void	free_oper_and_error(t_data *data, char **oper, int j)
{
	int	i;

	i = 0;
	while (oper[i])
	{
		free(oper[i]);
		i++;
	}
	free(oper);
	free_and_error(data, j);
}

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
