# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/01 14:57:04 by tlouekar          #+#    #+#              #
#    Updated: 2020/04/10 11:41:05 by tlouekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	srcs/ft_printf.c \
		srcs/main.c \
		srcs/con_c.c \
		srcs/con_d.c \
		srcs/con_o.c \
		srcs/con_u.c \
		srcs/con_p.c \
		srcs/con_s.c \
		srcs/con_x.c \
		srcs/con_f.c \
		srcs/preparser.c \
		srcs/parser.c \
		srcs/initialize.c \
		srcs/output.c \
		srcs/helpers.c \
		srcs/ftoa.c \

OBJS = 	ft_printf.o \
		main.o \
		con_c.o \
		con_d.o \
		con_o.o \
		con_u.o \
		con_p.o \
		con_s.o \
		con_x.o \
		con_f.o \
		preparser.o \
		parser.o \
		initialize.o \
		output.o \
		helpers.o \
		ftoa.o \


INCS = -I ./srcs -I ./libft/includes/

CFLAGS = -g

LIB = -L./libft -lft

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(CFLAGS) -c $(SRCS) $(INCS)
	gcc $(CFLAGS) $(INCS) $(OBJS) $(LIB) -o $(NAME)

debug:

.PHONY: clean fclean re all

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
