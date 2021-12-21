/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:46:54 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/20 15:07:02 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	more_operations2(t_data *data, int *ptr)
{
	if (ptr[0] <= ptr[1])
	{
		ptr[0]++;
		while (--ptr[0])
		{
			--ptr[1];
			r(data, 'r', 1);
		}
		ptr[1]++;
		while (--ptr[1])
			r(data, 'a', 1);
	}
	else
	{
		ptr[1]++;
		while (--ptr[1])
		{
			--ptr[0];
			r(data, 'r', 1);
		}
		ptr[0]++;
		while (--ptr[0])
			r(data, 'b', 1);
	}
}

void	more_operations(t_data *data, int *ptr)
{
	ptr[1]++;
	while (--ptr[1])
	{
		--ptr[0];
		rr(data, 'r', 1);
	}
	ptr[0]++;
	while (--ptr[0])
		rr(data, 'b', 1);
}

void	do_operations(t_data *data, int *ptr)
{
	if (ptr[0] < 0 && ptr[1] < 0)
	{
		ptr[0] = abc(ptr[0]);
		ptr[1] = abc(ptr[1]);
		if (ptr[0] <= ptr[1])
		{
			ptr[0]++;
			while (--ptr[0])
			{
				--ptr[1];
				rr(data, 'r', 1);
			}
			ptr[1]++;
			while (--ptr[1])
				rr(data, 'a', 1);
		}
		else
			more_operations(data, ptr);
	}
	else
		more_operations2(data, ptr);
}

void	operations2_more(t_data *data, int *ptr)
{
	if (ptr[1] < 0)
	{
		ptr[1] = abc(ptr[1]);
		ptr[1]++;
		while (--ptr[1])
			rr(data, 'a', 1);
	}
	else
	{
		ptr[1]++;
		while (--ptr[1])
			r(data, 'a', 1);
	}
}

void	do_operations2(t_data *data, int *ptr)
{
	if (ptr[0] < 0)
	{
		ptr[0] = abc(ptr[0]);
		ptr[0]++;
		while (--ptr[0])
			rr(data, 'b', 1);
	}
	else
	{
		ptr[0]++;
		while (--ptr[0])
			r(data, 'b', 1);
	}
	operations2_more(data, ptr);
}
