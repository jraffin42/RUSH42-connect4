/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:44:50 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 19:33:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>
#include "libft.h"
#include "core.h"
#include "display.h"

#define BT_MAX_DEPTH	5

static double	backtracking(t_board *board, int is_player_turn, int depth)
{
	int		i;
	double	score;

	if (depth >= BT_MAX_DEPTH)
		return (0);
	score = 0;
	i = 0;
	while (i < board->width)
	{
		if (board->lengths[i] < board->height)
		{
			board->map[i][board->lengths[i]++] = board->token[is_player_turn];
			--board->left;
			if (is_won(board, i))
			{
				if (is_player_turn)
					score -= board->left;
				else
					score += board->left;
			}
			else if (board->left)
				score += backtracking(board, !is_player_turn, depth + 1);
			board->map[i][--board->lengths[i]] = 0;
			++board->left;
		}
		++i;
	}
	return (score);
}

int	ai_turn(t_board *board)
{
	int		i;
	int		m;
	double	score;
	double	max_score;
	int		best_move;

	max_score = -INFINITY;
	best_move = -1;
	m = 0;
	i = board->width / 2;
	while (i >= 0 && i < board->width)
	{
		if (board->lengths[i] < board->height)
		{
			board->map[i][board->lengths[i]++] = board->token[0];
			score = backtracking(board, 1, 0);
			printf("%d %le\n", i, score);
			if (score > max_score)
			{
				max_score = score;
				best_move = i;
			}
			board->map[i][--board->lengths[i]] = 0;
		}
		++m;
		if (m & 1)
			i -= m;
		else
			i += m;
	}
	printf("%d %le\n", best_move, max_score);
	return (best_move);
}
