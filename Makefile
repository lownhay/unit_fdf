#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abulakh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 13:37:25 by abulakh           #+#    #+#              #
#    Updated: 2018/06/14 13:37:26 by abulakh          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = abulakh.filler

SRCS = filler.c \
		filler2.c \

LIB = -L libft/ ./libft/libftprintf.a
OBJ = $(patsubst %.c,./%.o,$(SRCS))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

libft: 
	make -C ./libft

$(NAME): libft $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) -I ./

clean:
	/bin/rm -f *.o
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re libft

.NOTPARALLEL: all clean fclean re libft
