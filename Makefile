# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ralves-g <ralves-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:26:20 by ralves-g          #+#    #+#              #
#    Updated: 2023/10/20 15:43:17 by ralves-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address 
RM			=	rm -f

NAME		=	uttt

INCLUDE		=	-I ./ mlx-linux/libmlx_Linux.a

SRCS		=	$(shell find src/ -name '*.c')

DEPS		=	./mlx-linux/libmlx_Linux.a

_MLX		=	./mlx-linux

OBJS		=	$(patsubst %.c, %.o, $(SRCS))
all:	$(NAME)

$(_OBJ)%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(DEPS) $(OBJS)
	$(CC) $(CFLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(OBJS) -o $(NAME) $(INCLUDE) -L $(_MLX)

./mlx-linux/libmlx_Linux.a:
	cd mlx-linux;./configure

$(_OBJ):
	mkdir $@

clean:
	$(RM) -r $(OBJS)
	cd mlx-linux; make clean

fclean:	clean
	$(RM) -r $(NAME)
	$(RM) -r $(_MLX)libmlx_Linux.a

re:fclean all
