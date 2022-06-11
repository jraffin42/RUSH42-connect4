/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdisplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:50:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 01:29:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XDISPLAY_H
# define XDISPLAY_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "core.h"

# include "libft.h"

# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"

# define EVENT_ESC 65307
# define EVENT_A 97
# define EVENT_D 100
# define EVENT_SPACE 32

# define HEIGHT 50
# define WIDTH 50

typedef struct s_c4 {
	void	*mlx;
	void	*win;
	t_board	*board;
	int		x;
	int		y;
	int		width;
	int		height;
	char	p_color;
	int		p_pos;
	int		move;
	int		won;
	int		do_display;
	void	*bg;
	void	*red;
	void	*yellow;
	void	*bg_top;
	void	*top_red;
	void	*top_yellow;
	char	*err_str;
	int		is_player_turn;
}	t_c4;

int		xdisplay(t_board *board);

int		ft_init(t_c4 **c4);
int		ft_init_tex(t_c4 **c4);
int		ft_init_img(t_c4 **c4);

void	do_move(t_c4 **c4, t_board *board, int player, int move);

int		e_key_down(int keycode, t_c4 **c4);
int		red_cross_close(t_c4 **c4);
void	end_game(t_c4 **c4, char type);

void	ft_close(t_c4 **c4, char type);

void	xdisplay_error(char *s);

#endif
