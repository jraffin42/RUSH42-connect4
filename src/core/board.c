/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:35:42 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 11:53:27 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core.h"

int	allocate_board(t_board *board)
{
	int	i;
	int	step;

	write (1, "Allocating memory space", 23);
	board->map = ft_calloc(board->width, sizeof(char *));
	board->lengths = ft_calloc(board->width, sizeof(size_t));
	if (!board->map || !board->lengths)
		return (free(board->map), 1);
	i = 0;
	step = ft_max(board->width / 100, 1);
	while (i < board->width)
	{
		if (!(i % step))
			write(1, ".", 1);
		board->map[i] = ft_calloc(board->height + 1, sizeof(char));
		if (!board->map[i])
		{
			while (i--)
				free(board->map[i]);
			free(board->map);
			return (1);
		}
		++i;
	}
	board->n_fill = 0;
	board->ai_char = RED_CHAR;
	board->p_char = RED_CHAR;
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

int	is_full(t_board *board)
{
	int	i;

	i = board->width;
	while (i--)
		if (board->lengths[i] < board->height)
			return (0);
	return (1);
}

int	get_completion(t_board *board)
{
	int	slots;

	slots = board->width * board->height;
	return ((slots * board->n_fill) / 100);
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
