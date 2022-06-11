# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 14:10:06 by fmauguin          #+#    #+#              #
#    Updated: 2022/06/11 08:57:37 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH	=	srcs/
SRCS_FILES	=	display.c key_event.c ft_close.c ft_init_xpm.c ft_init_img.c \
				ft_init_struct.c
SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS		=	$(SRCS:%.c=%.o)
INC			=	./includes $(MLX_PATH) $(LIBFT_PATH)
INCLUDE		=	$(addprefix -I, $(INC))
LIBFT_PATH	=	../libft/
MLX_PATH	=	minilibx-linux/
LIBFT		=	libft.a
LINK		=	-L$(MLX_PATH) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L$(LIBFT_PATH) -lft
NAME		=	connect4

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE) -Imlx_linux -O3

all:		$(NAME)

$(NAME): 	message libft_build $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

libft_build:
			@make -C $(LIBFT_PATH)

clean:
			@rm -f $(OBJS)
			@make clean -C $(LIBFT_PATH)
			@echo "clean done"

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C $(LIBFT_PATH)
			@echo "fclean done"

re:			fclean all

message:
		@echo "Building $(NAME)"
