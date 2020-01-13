# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/01 14:57:04 by tlouekar          #+#    #+#              #
#    Updated: 2020/01/13 11:16:00 by tlouekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	srcs/ft_printf.c \
		srcs/main.c \
		srcs/display_c.c \
		srcs/display_str.c \
		srcs/parser.c \
		srcs/structurize.c \
		srcs/initialize.c \

OBJS = 	ft_printf.o \
		main.o \
		display_c.o \
		display_str.o \
		parser.o \
		structurize.o \
		initialize.o \


INCL = -I ./srcs -I ./libft/includes/

CFLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(CFLAGS) -c $(SRCS) $(INCS)
	gcc $(CFLAGS) $(INCS) $(OBJS) $(LIB) -o $(NAME)

.PHONY: clean fclean re all

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
