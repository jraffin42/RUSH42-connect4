/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdisplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:50:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 11:54:00 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XDISPLAY_H
# define XDISPLAY_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

# include "libft.h"

# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"

# define EVENT_ESC 65307
# define EVENT_A 97
# define EVENT_D 100
# define SPACE 3

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define HEIGHT 50
# define WIDTH 50

# define RED 1
# define YELLOW 0

typedef struct s_c4 {
	void	*mlx;
	void	*win;
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
	int		p_color;
	int		p_pos;
	void	*bg;
	void	*red;
	void	*yellow;
	void	*bg_top;
	void	*top_red;
	void	*top_yellow;
}	t_c4;

int		ft_close(t_c4 **c4, char type);
int		ft_init(t_c4 **c4, char **av);
int		ft_init_tex(t_c4 **c4);
int		ft_init_img(t_c4 **c4);
int		e_key_down(int keycode, t_c4 **c4);
int		red_cross_close(t_c4 **c4);
void	free_tab(char **tab);

#endif
