/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xanim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:25:07 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 14:34:12 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

static void	push_img(t_c4 **c4)
{
	if ((*c4)->anim > 1)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->bg,
			(*c4)->move * WIDTH, ((*c4)->anim - 1) * HEIGHT);
	if ((*c4)->is_player_turn && (*c4)->p_color == RED_CHAR)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->red,
			(*c4)->move * WIDTH, (*c4)->anim * HEIGHT);
	else if ((*c4)->is_player_turn)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->yellow,
			(*c4)->move * WIDTH, (*c4)->anim * HEIGHT);
	else if (!(*c4)->is_player_turn && (*c4)->p_color == RED_CHAR)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->yellow,
			(*c4)->move * WIDTH, (*c4)->anim * HEIGHT);
	else if (!(*c4)->is_player_turn)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->red,
			(*c4)->move * WIDTH, (*c4)->anim * HEIGHT);
}

static void	do_anim(t_c4 **c4)
{
	int	y;

	y = (*c4)->board->height - (*c4)->anim;
	push_img(c4);
	if ((*c4)->board->map[(*c4)->move][y] != NUL_CHAR)
	{
		(*c4)->move = -1;
		(*c4)->anim = 0;
		(*c4)->is_player_turn = !(*c4)->is_player_turn;
	}
	else
		(*c4)->anim++;
}

int	move_anim(t_c4 **c4)
{
	if (!(*c4)->anim)
		return (0);
	(*c4)->anim_count++;
	if ((*c4)->anim_count == -1)
		(*c4)->anim_count = 0;
	if ((*c4)->anim_count == ANIM_RATE)
	{
		(*c4)->anim_count = 1;
		do_anim(c4);
	}
	return (0);
}

void	do_move(t_c4 **c4, t_board *board, int player, int move)
{
	int	y;

	y = board->height - board->lengths[move];
	board->map[move][board->lengths[move]++] = board->token[player];
	--board->left;
	(*c4)->move = move;
	(*c4)->anim = 1;
	if (is_won(board, move))
	{
		if (player)
			return (end_game(c4, 'W'));
		return (end_game(c4, 'L'));
	}
	(*c4)->do_display = 1;
}
