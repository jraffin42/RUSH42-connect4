/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 08:48:14 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

int	move_p(t_c4 **c4, int y)
{
	if (y == -1)
		y = (*c4)->y - 1;
	if (y == (*c4)->y)
		y = 0;
	mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->bg_top,
		(*c4)->p_pos * WIDTH, 0 * HEIGHT);
	if ((*c4)->p_color == RED)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->top_red, y * WIDTH, 0 * HEIGHT);
	if ((*c4)->p_color == YELLOW)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->top_yellow, y * WIDTH, 0 * HEIGHT);
	(*c4)->p_pos = y;
	return (1);
}

int	e_key_down(int keycode, t_c4 **c4)
{
	if (keycode == EVENT_ESC)
		mlx_loop_end((*c4)->mlx);
	if (keycode == EVENT_A)
		move_p(c4, (*c4)->p_pos - 1);
	if (keycode == EVENT_D)
		move_p(c4, (*c4)->p_pos + 1);
	return (0);
}
