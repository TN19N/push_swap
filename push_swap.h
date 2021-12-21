/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:58:55 by mannouao          #+#    #+#             */
/*   Updated: 2021/12/20 18:57:49 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct v_data
{
	int	*a;
	int	*b;
	int	len;
	int	min;
	int	*tmp;
	int	t;
	int	len_a;
	int	len_b;
	int	t2;
	int	*lis;
	int	tmp2[2];
}				t_data;	

void	print_error(void);
void	check_and_convert(t_data *data);
int		ft_atoi(const char *str, t_data *data);
void	free_and_error(t_data *data, int i);
void	mini_set(int len, int *end, int *tmp, int i);
void	ft_swap(int	*a, int *b);
void	check_if_sorted(t_data *data);
void	s(t_data *data, char c, int i);
void	p(t_data *data, char c);
void	r(t_data *data, char c, int j);
void	rr(t_data *data, char c, int j);
void	first_step(t_data *data);
void	secend_step(t_data *data);
int		chek_b(int *arr, int to_check, int len);
void	copy_arr(int *arr1, int *arr2, int len);
void	free_tab_and_err(t_data *data, int **tmp, int i, int j);
int		**ft_malloc(t_data *data);
int		*alloci_and_free(t_data *data, int **tmp, int tmp2);
void	save_the_longest(t_data *data, int *tmp2, int i);
int		ft_intsrch(t_data *data, int num, int t1);
int		*find_best_move(t_data *data);
void	third_step(t_data *data);
int		abc(int num);
int		*best_next_move(t_data *data);
void	do_operations(t_data *data, int *ptr);
void	do_operations2(t_data *data, int *ptr);
void	increment_b(t_data *data);
void	increment_b2(t_data *data);
void	increment_a(t_data *data);
void	increment_a2(t_data *data);
void	just_three(t_data *data);
void	just_five(t_data *data);
void	last_step(t_data *data);

#endif