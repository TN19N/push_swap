/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:25:50 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 07:34:06 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;

	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
		free_for_tmps(str1, str2);
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (*str2)
	{
		str[i] = *str2;
		str2++;
		i++;
	}
	str[i] = '\0';
	free(str1);
	return (str);
}
