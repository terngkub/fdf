# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 19:35:45 by nkamolba          #+#    #+#              #
#    Updated: 2018/12/15 12:26:48 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
_SRCS = main.c structure.c utils.c \
		parse_file.c get_points.c env.c \
		display.c get_coord.c rotate.c draw_map.c draw_line.c \
		key.c
_INCLUDES = fdf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))
OBJS = $(SRCS:.c=.o)

INCLUDES_DIR = includes
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(_INLCUDES))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAG = -Llibft -lft

MLX_DIR = minilibx_macos
MLX_FLAG = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all : lib $(INCLUDES) $(NAME)

lib:
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAG) $(MLX_FLAG) -I $(INCLUDES_DIR)
	@echo "$(NAME) created"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@echo "$(NAME) clean done"

fclean: clean
	@rm -f $(LIBFT)
	@echo "libft.a fclean done"
	@rm -f $(NAME)
	@echo "$(NAME) fclean done"

re: fclean all

.PHONY: all clean fclean re
