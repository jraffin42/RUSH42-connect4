/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 19:27:54 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

int	do_move(t_c4 **c4, t_board *board, int player, int move)
{
	int	y;

	y = board->height - board->lengths[move];
	board->map[move][board->lengths[move]++] = board->token[player];
	--board->left;
	if ((*c4)->p_color == RED_CHAR)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->red,
			(*c4)->move	* WIDTH, y * HEIGHT);
	else
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->yellow,
			(*c4)->move * WIDTH, y * HEIGHT);
	mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->bg_top,
			(*c4)->move * WIDTH, 0 * HEIGHT);
	(*c4)->is_player_turn = !(*c4)->is_player_turn;
	(*c4)->do_display = 1;
	return (0);
}

int	move_p(t_c4 **c4, int y)
{
	if (y == -1)
		y = (*c4)->y - 1;
	if (y == (*c4)->y)
		y = 0;
	mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->bg_top,
		(*c4)->p_pos * WIDTH, 0 * HEIGHT);
	if ((*c4)->p_color == RED_CHAR)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->top_red, y * WIDTH, 0 * HEIGHT);
	else if ((*c4)->p_color == YEL_CHAR)
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
	if (keycode == EVENT_SPACE)
		(*c4)->move = (*c4)->p_pos;
	return (0);
}
