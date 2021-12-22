/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:25:50 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 13:42:25 by mannouao         ###   ########.fr       */
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
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		data->a[i] = ft_atoi(av[i + 1], data);
		j = i;
		while (j >= 0)
		{
			if (data->a[i] == data->a[j] && j != i)
				free_and_error(data, 0);
			j--;
		}
		i++;
	}
	data->len = ac - 1;
	data->len_a = data->len;
	data->len_b = 0;
	data->tmp = NULL;
}

void	check_if_sorted(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->len_a - 1)
	{
		if (data->a[i] > data->a[i + 1])
			break ;
	}
	if (i == data->len - 1)
	{
		write(1, "OK\n", 3);
		free_and_error(data, 1);
	}
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
		str1 = ft_strdup("");
	str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!str)
	{
		free(str1);
		return (NULL);
	}
	i = -1;
	while (str1[++i])
		str[i] = str1[i];
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
