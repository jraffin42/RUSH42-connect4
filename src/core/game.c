/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:38:02 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 15:53:15 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core.h"
#include "display.h"

static int game_end(int won, int is_player_turn)
{
    if (!won)
		ft_printf("IT'S A TIE !\n");
	else if (is_player_turn)
		ft_printf("PLAYER WON !\n");
	else
		ft_printf("IA WON !\n");
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
            return (ft_printf("Error reading stdin\n"), 1);
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