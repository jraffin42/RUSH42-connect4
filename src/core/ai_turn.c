/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:44:50 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 15:45:49 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

#define BT_MAX_DEPTH	50

static int	backtracking(t_board *board, int is_player_turn, int depth)
{
	int					i;
	int					wins;

	if (depth >= BT_MAX_DEPTH)
		return (0);
	wins = 0;
	i = 0;
	while (i < board->width)
	{
		if (board->lengths[i] < board->height)
		{
			if (is_player_turn)
				board->map[i][board->lengths[i]++] = board->token[1];
			else
				board->map[i][board->lengths[i]++] = board->token[0];
			if (!is_player_turn && is_won(board, i))
				++wins;
			else
				wins += backtracking(board, !is_player_turn, depth + 1);
			board->map[i][--board->lengths[i]] = 0;
		}
		++i;
	}
	return (wins);
}

int	ai_turn(t_board *board)
{
	int	i;
	int	wins;
	int	max_wins;
	int	best_move;

	max_wins = 0;
	best_move = -1;
	i = 0;
	while (i < board->width)
	{
		if (board->lengths[i] < board->height)
		{
			board->map[i][board->lengths[i]++] = board->token[0];
			wins = backtracking(board, 1, 0);
			if (wins > max_wins)
			{
				max_wins = wins;
				best_move = i;
			}
			board->map[i][--board->lengths[i]] = 0;
		}
		++i;
	}
	return (best_move);
}

