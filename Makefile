# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhoumman <mhoumman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 15:53:31 by mhoumman          #+#    #+#              #
#    Updated: 2025/11/25 11:15:42 by mhoumman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putadd.c ft_putchar.c ft_puthex.c ft_putnbr.c\
       ft_putstr.c ft_putunbr.c  ft_printf.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC  = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o  $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: clean
