# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2022/02/15 22:34:27 by ohw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME=libftprintf.a
SRCSDIR=srcs
INCS=./
SRCS=ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_base_fd.c\
	ft_checkdigit.c ft_checkdigit_address.c\
	ft_putaddress_fd.c ft_strlen.c ft_itoa_base.c\
	ft_printf.c ft_printf_nbr.c ft_printf_non_nbr.c

OBJS=${SRCS:.c=.o}

OBJ_FILES = $(OBJS)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
