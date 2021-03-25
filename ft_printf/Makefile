# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wspectra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 18:33:36 by wspectra          #+#    #+#              #
#    Updated: 2020/12/02 18:33:39 by wspectra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_if_procent.c ft_printf_utils.c ft_if_int.c ft_parsing.c ft_printf.c ft_if_char.c\
        ft_if_uns_int.c ft_if_hex.c ft_if_pointer.c ft_if_string.c ft_printf_utils_put.c\
        main.c


OBJS	= $(SRCS:.c=.o)

INCL	= ft_printf.h

CC		= gcc

RM		= rm -f

FLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c $(INCL)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:
		all, clean, fclean, re, bonus
