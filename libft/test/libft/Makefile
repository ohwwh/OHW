# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2021/11/24 16:59:34 by hoh              ###   ########.fr        #
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
	 ft_memcmp.c ft_strnstr.c ft_atoi.c\
	 ft_calloc.c ft_strdup.c\
	 ft_substr.c ft_strjoin.c ft_strtrim.c\
	 ft_split.c ft_itoa.c ft_strmapi.c\
	 ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	 ft_putendl_fd.c ft_putnbr_fd.c
BONUS=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
	  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
	  ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS=${SRCS:.c=.o}

OBJSBNS=${BONUS:.c=.o}

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

bonus : $(OBJS) $(OBJSBNS)
	ar rc $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

clean:
	rm -f $(OBJS)

bclean:
	rm -f $(OBJS) $(OBJSBNS)

fclean: clean
	rm -f $(NAME)

bfclean: bclean
	rm -f $(NAME)

re: fclean all
