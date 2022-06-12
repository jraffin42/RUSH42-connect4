/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:08:07 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 18:04:24 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "core.h"
#include "display.h"

static int	arg_check(int argc, char **argv, int *width, int *height)
{
	char	numbuf[12];

	if (argc != 3)
		return (ft_putstr_fd("wrong number of argument.\n\t"
				"USAGE : ./connect4 [height] [width]", 1), 1);
	if (ft_atoi_err(argv[1], height) || *height < 6)
		return (ft_putstr_fd("invalid height (must be a valid "
				"integer >= 6)", 1), 1);
	if (ft_atoi_err(argv[2], width) || *width < 7)
		return (ft_putstr_fd("invalid width (must be a valid "
				"integer >= 7)", 1), 1);
	if (*width > MAX_BOARD_WIDTH)
		return (ft_putstr_fd("width must be <= ", 1),
			ft_itoa(MAX_BOARD_WIDTH, numbuf), ft_putstr_fd(numbuf, 1),
			ft_putchar_fd('\n', 1), 1);
	if (*height > MAX_BOARD_HEIGHT)
		return (ft_putstr_fd("height must be <= ", 1),
			ft_itoa(MAX_BOARD_HEIGHT, numbuf), ft_putstr_fd(numbuf, 1),
			ft_putchar_fd('\n', 1), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_board	board;

	if (arg_check(argc, argv, &board.width, &board.height))
		return (1);
	if (init_board(&board))
		return (ft_putstr_fd("Error : couldn't allocate memory !", 1), 1);
	game_loop(&board);
	free_board(&board);
	ft_gnl(~0);
	return (0);
}
