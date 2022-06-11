/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:08:07 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 15:32:09 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "core.h"
#include "display.h"

int	arg_check(int argc, char **argv, int *width, int *height)
{
	if (argc != 3)
		return (ft_put_error(argv[0], NULL,
				"wrong number of argument.\n\t"
				"USAGE : ./connect4 [height] [width]", 1));
	if (ft_atoi_err(argv[1], height) || *height < 6)
		return (ft_put_error(argv[0], NULL,
				"invalid height (must be a valid integer >= 6)", 1));
	if (ft_atoi_err(argv[2], width) || *width < 7)
		return (ft_put_error(argv[0], NULL,
				"invalid width (must be a valid integer >= 7)", 1));
	if (*width > (INT_MAX / *height))
		return (ft_put_error(argv[0], NULL,
				"width * height product must be <= INT_MAX", 1));
	return (0);
}

int	game_loop(t_board *board)
{
	int		is_player_turn;
	int		move;
	int		won;

	won = 0;
	is_player_turn = board->token[1] == YEL_CHAR;
	while (!won && board->fill < board->size)
	{
		display_board(board);
		// if (is_player_turn)
		move = player_turn(board);
		// else
		// 	move = ai_turn(board);
		if (move == -1)
		{
			write(2, "Error reading stdin\n", 25);
			return (1);
		}
		won = is_won(board, move);
		board->map[move][board->lengths[move]++] = board->token[is_player_turn];
		board->fill++;
		is_player_turn = !is_player_turn;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_board	board;

	if (arg_check(argc, argv, &board.width, &board.height))
		return (1);
	if (init_board(&board))
		return (ft_put_error(argv[0], NULL,
				"Error : couldn't allocate memory !", 1));
	if (!game_loop(&board))
		write(1, "\x1B[2J\x1B[H", 7);
	free_board(&board);
	return (0);
}
