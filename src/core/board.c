/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:35:42 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 15:33:11 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "libft.h"
#include "core.h"

static int	init_content(t_board *board)
{
	int	i;

	i = 0;
	while (i < board->width)
	{
		board->map[i] = ft_calloc(board->height + 1, sizeof(char));
		if (!board->map[i])
		{
			while (i--)
				free(board->map[i]);
			free(board->map);
			return (1);
		}
		ft_memset(board->map[i], NUL_CHAR, board->height);
		++i;
	}
	return (0);
}

int	init_board(t_board *board)
{
	int	i;

	board->map = ft_calloc(board->width, sizeof(char *));
	if (!board->map)
		return (1);
	board->lengths = ft_calloc(board->width, sizeof(size_t));
	if (!board->lengths)
		return (free(board->map), 1);
	if (init_content(board))
		return (1);
	board->fill = 0;
	board->size = board->width * board->height;
	i = (srand(time(NULL)), rand() % 2);
	board->token[i] = YEL_CHAR;
	board->token[!i] = RED_CHAR;
	return (0);
}

void	free_board(t_board *board)
{
	while (board->width)
		free(board->map[--board->width]);
	board->height = 0;
	free(board->lengths);
	board->lengths = NULL;
	free(board->map);
	board->map = NULL;
}

static int	count_line_from(t_board *brd, int last_move, int way_x, int way_y)
{
	char	c;
	int		count;
	int		x;
	int		y;

	x = last_move;
	y = brd->lengths[last_move] - 1;
	c = brd->map[x][y];
	count = 0;
	x += way_x;
	y += way_y;
	while (x >= 0 && x < brd->width && y >= 0 && y < brd->height
		&& brd->map[x][y] == c)
	{
		++count;
		x += way_x;
		y += way_y;
	}
	return (count);
}

char	is_won(t_board *board, int last_move)
{
	if (1 + count_line_from(board, last_move, 0, -1) >= NUM_TO_WIN
		|| 1 + count_line_from(board, last_move, -1, -1)
		+ count_line_from(board, last_move, +1, +1) >= NUM_TO_WIN
		|| 1 + count_line_from(board, last_move, -1, +1)
		+ count_line_from(board, last_move, +1, -1) >= NUM_TO_WIN)
		return (board->map[last_move][board->lengths[last_move] - 1]);
	return (0);
}
