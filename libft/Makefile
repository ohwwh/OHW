# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2021/11/23 16:36:27 by ohw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=libft.a
SRCSDIR=srcs
INCS=./
SRCS=ft_isalpha.c ft_isdigit.c ft_isalnum.c\
	 ft_isascii.c ft_isprint.c ft_strlen.c\
	 ft_memset.c ft_bzero.c ft_memcpy.c\
	 ft_memmove.c ft_strlcpy.c ft_strlcat.c\
	 ft_toupper.c ft_tolower.c ft_strchr.c\
	 ft_strrchr.c ft_strncmp.c ft_memchr.c\
	 ft_memcmp.c ft_strnstr.c ft_atoi.c
OBJS=${SRCS:.c=.o}

.PHONY: all clean fclean re

all : $(NAME)

libft.a : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
