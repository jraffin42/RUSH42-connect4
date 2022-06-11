/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:02:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 19:59:58 by fmauguin         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_board	board;

	if (arg_check(argc, argv, &board.width, &board.height))
		return (1);
	if (init_board(&board))
		return (ft_put_error(argv[0], NULL,
				"Error : couldn't allocate memory !", 1));
	//if (argc == 3 && !(game_loop(&board)))
	//	write(1, "\x1B[2J\x1B[H", 7);
	if (argc == 4 && xdisplay(&board))
		write(1, "\x1B[2J\x1B[H", 7);
	free_board(&board);
	return (0);
}
