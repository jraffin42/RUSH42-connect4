/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:44:50 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 12:40:09 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"
#include "core.h"
#include "display.h"

#define MAX_DEPTH	4

static int	win_column(t_board *board, int player)
{
	int	i;
	int	won;

	i = -1;
	while (++i < board->width)
	{
		if (board->lengths[i] < board->height)
		{
			board->map[i][board->lengths[i]++] = board->token[player];
			won = is_won(board, i);
			board->map[i][--board->lengths[i]] = NUL_CHAR;
			if (won)
				return (i);
		}
	}
	return (-1);
}

static int	backtrack(t_board *board, int alpha, int beta, int player, int depth)
{
	int	i;
	int	m;
	int	score;

	if (!depth || !board->left)
		return (0);
	if (win_column(board, player) != -1)
		return ((board->left + 1) / 2);
	score = (board->left - 1) / 2;
	if (beta > score)
	{
		beta = score;
		if (alpha >= beta)
			return (beta);
	}
	m = 0;
	i = board->width / 2;
	while (i >= 0 && i < board->width)
	{
		if (board->lengths[i] < board->height)
		{
			board->map[i][board->lengths[i]++] = board->token[player];
			--board->left;
			score = -backtrack(board, -beta, -alpha, !player, depth - 1);
			board->map[i][--board->lengths[i]] = NUL_CHAR;
			++board->left;
			if (score >= beta)
				return (score);
			if (score > alpha)
				alpha = score;
		}
		++m;
		if (m & 1)
			i -= m;
		else
			i += m;
	}
	return (alpha);
}

int	ai_turn(t_board *board)
{
	int		i;
	int		m;
	int		score;
	int		max_score;
	int		move;

	max_score = INT_MIN;
	move = win_column(board, 0);
	if (move != -1)
		return (move);
	m = 0;
	i = board->width / 2;
	while (i >= 0 && i < board->width)
	{
		if (board->lengths[i] < board->height)
		{
			board->map[i][board->lengths[i]++] = board->token[0];
			--board->left;
			score = -backtrack(board, -board->left / 2, board->left / 2, 1, MAX_DEPTH);
			board->map[i][--board->lengths[i]] = NUL_CHAR;
			++board->left;
			if (score > max_score)
			{
				max_score = score;
				move = i;
			}
		}
		++m;
		if (m & 1)
			i -= m;
		else
			i += m;
	}
	return (move);
}
