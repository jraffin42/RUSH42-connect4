/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:02:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 18:21:20 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"
#include <limits.h>
#include "display.h"
#include "core.h"

static int	arg_check(int argc, char **argv, int *width, int *height)
{
	if (argc != 3 && argc != 4)
		return (ft_put_error(argv[0], NULL,
				"wrong number of argument.\n\t"
				"USAGE : ./connect4 [height] [width] [--display]", 1));
    if (argc == 4 && ft_strncmp(argv[3], "--display", ft_strlen("--display")))
		return (ft_put_error(argv[0], NULL,
				"third argument not valid.\n\t"
				"USAGE : ./connect4 [height] [width] [--display]", 1));
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

	is_player_turn = board->token[1] == YEL_CHAR;
	display_board(board);
	while (board->left)
	{
		if (is_player_turn)
			move = player_turn(board);
		else
			move = ai_turn(board);
		if (move == -1)
		{
			write(2, "Error reading stdin\n", 20);
			return (1);
		}
		board->map[move][board->lengths[move]++] = board->token[is_player_turn];
		--board->left;
		display_board(board);
		won = is_won(board, move);
		if (won)
			break ;
		else
			is_player_turn = !is_player_turn;
	}
	if (!won)
		write(2, "IT'S A TIE !\n", 13);
	else if (is_player_turn)
		write(2, "PLAYER WON !\n", 13);
	else
		write(2, "IA WON !\n", 9);
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
    if (argc == 3 && !(game_loop(&board)))
		write(1, "\x1B[2J\x1B[H", 7);
	if (argc == 4 && xdisplay(&board))
		write(1, "\x1B[2J\x1B[H", 7);
	free_board(&board);
	return (0);
}