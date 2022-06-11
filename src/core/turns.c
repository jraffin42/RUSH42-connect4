/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:31:01 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 03:50:54 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

#define BT_MAX_DEPTH	50

static int	backtracking(t_board *board, int is_player_turn, int depth)
{
	static const char	c[2] = {AI_CHAR, PLAYER_CHAR};
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
			board->map[i][board->lengths[i]++] = c[is_player_turn];
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
			board->map[i][board->lengths[i]++] = AI_CHAR;
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

int	player_turn(t_board *board)
{
	int		err;
	int		move;
	char	*line;
	char	*err_str;

	move = -1;
	err_str = "";
	while (1)
	{
		display_board(board);
		display_error(err_str);
		display_info("Please enter the column you want to play : ");
		line = ft_gnl(0);
		if (!line)
			return (-1);
		err = ft_atoi_err(line, &move);
		free(line);
		if (err)
			err_str = "Invalid integer.";
		else if (move < 0 || move > board->width)
			err_str = "Column out of range.";
		else
			return (move);
	}
}
