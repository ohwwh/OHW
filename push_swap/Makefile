# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohw <ohw@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 02:36:10 by ohw               #+#    #+#              #
#    Updated: 2022/03/01 14:35:29 by ohw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME=push_swap.a
SRCSDIR=srcs
INCS=./
SRCS=main.c clist.c print.c ft_atoi.c quick_sort.c
BONUS=
OBJS=${SRCS:.c=.o}

OBJSBNS=${BONUS:.c=.o}

ifdef WITH_BONUS
    OBJ_FILES = $(OBJS) $(OBJSBNS)
else
    OBJ_FILES = $(OBJS)
endif

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

bonus : 
	make WITH_BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS)

clean:
	rm -f $(OBJS) $(OBJSBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all
