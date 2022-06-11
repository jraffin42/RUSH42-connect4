# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by jraffin           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/06/11 12:06:55 by fmauguin         ###   ########.fr        #
=======
#    Updated: 2022/06/11 12:04:30 by jraffin          ###   ########.fr        #
>>>>>>> b43d2aac0e2f6fa3d22b20fe5da2416abd0c2cad
#                                                                              #
# **************************************************************************** #

SHELL				=	/bin/sh

PROGNAME			:=	connect4
PROGNAME_BONUS		:=	$(PROGNAME)_bonus

LIBFT				:=	libft/libft.a

MLX					:=	mlx/libmlx.a

INCLUDEDIR			:=	inc
SRCDIR				:=	src

OBJDIR				:=	./obj
DEBUGDIR			:=	./debugobj

COMMONSRCS			:=	core/main.c						\
						core/board.c					\
						core/turns.c					\
						core/low_ai.c					\

NOBONUSSRCS			:=	display/display_board.c			\
						display/display_msgs.c			\

BONUSSRCS			:=	xdisplay/display_board.c		\
						xdisplay/display_msgs.c			\
						xdisplay/display.c				\
						xdisplay/ft_close.c				\
						xdisplay/ft_init_img.c			\
						xdisplay/ft_init_struct.c		\
						xdisplay/ft_init_xpm.c			\
						xdisplay/key_event.c			\

CC					:=	cc
RM					:=	rm

CCFLAGS				:=	-Wall -Wextra -Werror
LIBFLAGS			:=
OPTFLAG				:=

NAME				:=	$(PROGNAME)
BONUSNAME			:=	$(PROGNAME_BONUS)

OUTDIR				:=	$(OBJDIR)

DEBUGNAME			:= $(addsuffix .debug,$(PROGNAME))
BONUSDEBUGNAME		:= $(addsuffix .debug,$(PROGNAME_BONUS))

ifdef DEBUG
	OPTFLAG 		:=	-g
	LIBFT			:=	$(addsuffix .debug,$(LIBFT))
	NAME			:=	$(DEBUGNAME)
	BONUSNAME		:=	$(BONUSDEBUGNAME)
	OUTDIR			:=	$(DEBUGDIR)
endif

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) $(addprefix -I ,$(INCLUDEDIR)) $(addprefix -I ,$(dir $(LIBFT))) $(addprefix -I ,$(dir $(MLX))) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(NOBONUSSRCS:.c=.o)) $(LIBFT)
	$(CC) $(CCFLAGS) $(OPTFLAG) -o $(NAME) $(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(NOBONUSSRCS:.c=.o)) $(LIBFT) $(LIBFLAGS)

$(BONUSNAME)		:	$(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(BONUSSRCS:.c=.o)) $(LIBFT) $(MLX)
	$(CC) $(CCFLAGS) $(OPTFLAG) -o $(BONUSNAME) $(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(BONUSSRCS:.c=.o)) $(LIBFT) $(MLX) -lXext -lX11 -lm -lbsd $(LIBFLAGS)

all					:	$(NAME) $(BONUSNAME)

bonus				:	$(BONUSNAME)

$(DEBUGNAME)		:
ifndef DEBUG
	$(MAKE) $(DEBUGNAME) DEBUG=1
endif

$(BONUSDEBUGNAME)	:
ifndef DEBUG
	$(MAKE) $(BONUSDEBUGNAME) DEBUG=1
endif

ifdef DEBUG
$(PROGNAME)			:	$(NAME)
$(PROGNAME_BONUS)	:	$(BONUSNAME)
endif

debug				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

ifdef LIBFT
$(LIBFT)			:
	$(MAKE) -j -C $(dir $(LIBFT)) $(notdir $(LIBFT))
endif

ifdef MLX
$(MLX)			:
	$(MAKE) -j -C $(dir $(MLX))
endif

$(OUTDIR)			:
	mkdir $(OUTDIR)

clean				:
ifdef LIBFT
	$(MAKE) -C $(dir $(LIBFT)) fclean
endif
ifdef MLX
	$(MAKE) -C $(dir $(MLX)) clean
endif
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME) $(PROGNAME_BONUS) $(DEBUGNAME) $(BONUSDEBUGNAME)

re					:	fclean
	$(MAKE) $(NAME)

.PHONY				:	all bonus clean fclean re

-include	$(addprefix $(OUTDIR)/,$(SRCS:.c=.d))
