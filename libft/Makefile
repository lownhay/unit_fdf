#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abulakh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 19:46:54 by abulakh           #+#    #+#              #
#    Updated: 2018/02/24 19:46:55 by abulakh          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HIDDIRS = -I . ft_printf.h

SRC = ft_printf_start.c ft_print_help.c \
		ft_di.c ft_s2.c \
		ft_dubl.c ft_obl.c \
		ft_ouxxbl.c ft_p.c \
		ft_s.c ft_cbl.c \
		ft_c.c ft_put_chtoto.c \
		ft_ouxxbl2.c get_next_line.c

RM = rm -f

OBJ = $(patsubst %.c,./%.o,$(SRC))

LIB =  ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_strlen.c \
		ft_strdup.c ft_strcpy.c \
		ft_strcpy.c ft_strncpy.c \
		ft_strcat.c ft_strncat.c \
		ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c \
		ft_strnstr.c ft_strcmp.c \
		ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c \
		ft_strsplit.c ft_striter.c \
		ft_striteri.c ft_strmap.c \
		ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c \
		ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c \
		ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_lstnew.c \
		ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_guz.c \
		ft_sobaka.c ft_free_split.c \
		ft_sqrt.c ft_pow.c \
		ft_listsize.c ft_strfind.c \
		ft_itoa_base.c


OBJLB = $(patsubst %.c,./%.o,$(LIB))

MAKE = make

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -I . -Wall -Wextra -Werror -c $(LIB) $(SRCS) 
	@ar rc $(NAME) $(OBJ) $(OBJLB)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJ) $(OBJLB)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re