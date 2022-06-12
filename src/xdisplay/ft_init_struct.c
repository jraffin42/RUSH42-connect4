/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:19:57 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 17:15:51 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

static void	ft_init1(t_c4 **c4)
{
	(*c4)->x = (*c4)->board->height + 1;
	(*c4)->y = (*c4)->board->width;
	(*c4)->width = WIDTH;
	(*c4)->height = HEIGHT;
	(*c4)->p_color = (*c4)->board->token[1];
	(*c4)->p_pos = 0;
	(*c4)->move = -1;
	(*c4)->won = 0;
	(*c4)->anim_count = 0;
	(*c4)->anim = 0;
	(*c4)->err_str = NULL;
	(*c4)->do_display = 1;
	(*c4)->is_player_turn = (*c4)->p_color == YEL_CHAR;
}

int	ft_init(t_c4 **c4)
{
	ft_init1(c4);
	(*c4)->mlx = mlx_init();
	if (!(*c4)->mlx)
		return (1);
	(*c4)->win = mlx_new_window((*c4)->mlx, WIDTH * (*c4)->y,
			HEIGHT * (*c4)->x, "connect4_bonus");
	if (!(*c4)->win)
		return (1);
	if (ft_init_tex(c4))
		return (1);
	if (ft_init_img(c4))
		return (1);
	return (0);
}
