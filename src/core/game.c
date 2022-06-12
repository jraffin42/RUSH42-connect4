/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:38:02 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 14:42:50 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core.h"
#include "display.h"

static int game_end(int won, int is_player_turn)
{
    if (!won)
		write(2, "IT'S A TIE !\n", 13);
	else if (is_player_turn)
		write(2, "PLAYER WON !\n", 13);
	else
		write(2, "IA WON !\n", 9);
	return (0);
}

int	game_loop(t_board *board)
{
	int		is_player_turn;
	int		move;
	int		won;

	is_player_turn = board->token[1] == YEL_CHAR;
	display_board(board);
	while (board->left)
	{
		if (is_player_turn)
			move = player_turn(board);
		else
			move = ai_turn(board);
		if (move == -1)
            return (write(2, "Error reading stdin\n", 20), 1);
		board->map[move][board->lengths[move]++] = board->token[is_player_turn];
		--board->left;
		display_board(board);
		won = is_won(board, move);
		if (won)
			break ;
		else
			is_player_turn = !is_player_turn;
	}
	return (game_end(won, is_player_turn));
}