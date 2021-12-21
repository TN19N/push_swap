/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:15:12 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/19 18:33:57 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_b(int *arr, int to_check, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] > to_check)
			return (0);
		i++;
	}
	return (1);
}
