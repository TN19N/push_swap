# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 13:04:38 by mannouao          #+#    #+#              #
#    Updated: 2021/12/21 15:36:37 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
SRCS = push_swap.c\
		error.c\
		check.c\
		ft_tools.c\
		steps.c\
		operations.c\
		more_check.c\
		ft_tools2.c\
		ft_tools3.c\
		ft_tools4.c\
		ft_atoi.c
SRCS_BONUS = checker.c\
			get_next_line.c\
			checker_error.c\
			checker_tools.c\
			checker_tools2.c\
			checker_operations.c\
			ft_split.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS_BONUS)
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME_BONUS)
	@rm -f $(NAME)

re : fclean all