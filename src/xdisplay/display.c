/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 18:09:48 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"
#include "display.h"
#include "core.h"

void	do_error(char *s)
{
	if (s)
		display_error(s);
	else
		display_error("");
}

int	xplayer_turn(t_c4 **c4, t_board *board)
{
	if ((*c4)->is_player_turn)
	{
		display_board(board);
		do_error((*c4)->err_str);
		display_info("Please press SPACE on the column you want to play");
		(*c4)->is_player_turn = !(*c4)->is_player_turn;
	}
	if ((*c4)->move != -1)
	{
		ft_putstr_fd("hrer\n", 2);
		display_board(board);
		do_error((*c4)->err_str);
		display_info("Please press SPACE on the column you want to play");
		if (board->lengths[(*c4)->move] == board->height)
			(*c4)->err_str = ft_strdup("Column filled.");
		else
		{
			if ((*c4)->err_str)
				free((*c4)->err_str);
			return ((*c4)->move);
		}
		(*c4)->move = -1;
	}
	return (-1);
}

int	x_game_loop(t_c4 **c4)
{
	int		move;
	t_board	*board;

	board = (*c4)->board;
	if (board->fill == board->size)
		return (mlx_loop_end((*c4)->mlx));
	move = xplayer_turn(c4, board);
	if (move != -1)
	{
		board->map[move][board->lengths[move]++] = board->token[1];
		board->fill++;
		(*c4)->err_str = NULL;
		(*c4)->move = -1;
		(*c4)->is_player_turn = !(*c4)->is_player_turn;
		if (is_won(board, move))
			return (mlx_loop_end((*c4)->mlx));
	}
	return (0);
}

int	xdisplay(t_board *board)
{
	t_c4	*c4;

	c4 = (t_c4 *)ft_calloc(1, sizeof(t_c4));
	if (!c4)
		return (0);
	c4->board = board;
	if (!ft_init(&c4))
	{
		ft_close(&c4, 'E');
		return (0);
	}
	mlx_hook(c4->win, 17, 1L << 17, red_cross_close, &c4);
	mlx_key_hook(c4->win, e_key_down, &c4);
	mlx_loop_hook(c4->mlx, x_game_loop, &c4);
	mlx_loop(c4->mlx);
	ft_close(&c4, 'W');
	return (EXIT_SUCCESS);
}
