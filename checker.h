/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:22:02 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/21 07:42:42 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H
# define BUFFER_SIZE 800000

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct v_data
{
	int	*a;
	int	*b;
	int	len;
	int	len_a;
	int	len_b;
	int	t;
	int	t2;
	char **oper;
}				t_data;	

void	free_and_error(t_data *data, int i);
void	set_all(t_data *data, char **av, int ac);
char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
void	print_error(void);
void	check_if_sorted(t_data *data);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str, t_data *data);
void	free_for_tmps(char *tmp1, char *tmp2);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	s(t_data *data, char c);
void	p(t_data *data, char c);
void	r(t_data *data, char c);
void	rr(t_data *data, char c);
void	increment_a2(t_data *data);
void	increment_a(t_data *data);
void	increment_b2(t_data *data);
void	increment_b(t_data *data);
void	free_oper_and_error(t_data *data, char **oper, int i);

#endif