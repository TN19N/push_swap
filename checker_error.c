/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 07:48:23 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 08:55:09 by mannouao         ###   ########.fr       */
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

void	free_for_tmps(char *tmp1, char *tmp2)
{
	if (tmp1)
		free(tmp1);
	if (tmp2)
		free(tmp2);
}

void	free_oper_and_error(t_data *data, char **oper, int j)
{
	int i;

	i = 0;
	while (oper[i])
	{
		free(oper[i]);
		i++;
	}
	free(oper);
	free_and_error(data, j);
}