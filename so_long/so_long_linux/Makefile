# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 18:35:15 by pgouasmi          #+#    #+#              #
#    Updated: 2023/07/17 12:38:31 by pgouasmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = 	./utils/utils.c						\
		./utils/arg_parsing.c					\
		./utils/get_map_from_file.c			\
		./utils/is_map_solvable.c			\
		./utils/map_checker.c				\
		./utils/set_struct.c				\
		./utils/struct_checker.c			\
		./utils/free.c						\
		./utils/render/render.c				\
		./utils/render/render_next_frame.c	\
		./utils/render/key_hook.c			\

LIBFT_PATH	=	./includes/

LIBFT_FILE	=	libft.a
		
MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_FLAG	=	-I/usr/include -Imlx_linux -lXext -lX11 -lm -lz

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

OBJS = ${SRCS:.c=.o}

HEADER = so_long.h

CC = cc

FLAG = -Wall -Wextra -Werror

C_FILE		=	so_long.c				\

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

lib:	
	@make -C $(LIBFT_PATH)

mlx:
	@make -sC $(MLX_PATH)

%.o:	%.c $(HEADER) Makefile
			$(CC) $(FLAG) -I . -c $< -o $@

$(NAME): lib mlx $(OBJ) $(OBJS)
	$(CC) $(OBJ) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ) $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
