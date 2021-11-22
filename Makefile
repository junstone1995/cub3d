# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseole <junseole@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 16:59:41 by junseole          #+#    #+#              #
#    Updated: 2021/11/22 18:24:40 by junseole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRC_NAME = draw.c \
		get_next_line.c \
		init.c \
		keys_utils.c \
		keys.c \
		main.c \
		mapcheck.c \
		move.c \
		parse1_utils.c \
		parse1.c \
		parse2_utils.c \
		parse2.c \
		pos.c \
		raycasting_util.c \
		raycasting_util2.c \
		raycasting.c \
		render.c \
		screenshot.c \
		sprite.c \
		texture.c \
		utils.c \
		utils2.c

SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

SCREENSHOT = screenshot.bmp

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror

LIBFT	= libft.a

LIBMLX	= libmlx.a

MLX	= -framework OpenGL -framework Appkit

LIBS	= -L./lib/libft -lft -L./lib/mlx -lmlx

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

$(LIBFT):
	$(MAKE) -C lib/libft

$(LIBMLX):
	$(MAKE) -C lib/mlx

clean	:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/mlx clean
	rm -rf $(OBJ_PATH) $(BOBJ_PATH) $(SCREENSHOT)

fclean	: clean
	$(MAKE) -C lib/libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re
