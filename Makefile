# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 14:25:17 by jraffin           #+#    #+#              #
#    Updated: 2022/06/11 11:03:27 by fmauguin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				=	/bin/sh

PROGNAME			:=	connect4
PROGNAME_BONUS		:=	$(PROGNAME)_bonus

LIBFT				:=	libft/libft.a

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

BONUSSRCS			:=	display_bonus/display_board.c	\
						display_bonus/display_msgs.c	\

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
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) $(addprefix -I ,$(INCLUDEDIR)) $(addprefix -I ,$(dir $(LIBFT))) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(NOBONUSSRCS:.c=.o)) $(LIBFT)
	$(CC) $(CCFLAGS) $(OPTFLAG) -o $(NAME) $(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(NOBONUSSRCS:.c=.o)) $(LIBFT) $(LIBFLAGS)

$(BONUSNAME)		:	$(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(BONUSSRCS:.c=.o)) $(LIBFT)
	$(CC) $(CCFLAGS) $(OPTFLAG) -o $(BONUSNAME) $(addprefix $(OUTDIR)/,$(COMMONSRCS:.c=.o)) $(addprefix $(OUTDIR)/,$(BONUSSRCS:.c=.o)) $(LIBFT) $(LIBFLAGS)

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

$(OUTDIR)			:
	mkdir $(OUTDIR)

clean				:
ifdef LIBFT
	$(MAKE) -C $(dir $(LIBFT)) fclean
endif
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME) $(PROGNAME_BONUS) $(DEBUGNAME) $(BONUSDEBUGNAME)

re					:	fclean $(NAME)

.PHONY				:	all bonus clean fclean re

-include	$(addprefix $(OUTDIR)/,$(SRCS:.c=.d))
