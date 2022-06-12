/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:02:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 18:51:18 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"
#include <limits.h>
#include "display.h"
#include "core.h"

static int	arg_check(int argc, char **argv, int *width, int *height)
{
	char	numbuf[12];

	if (argc != 3 && argc != 4)
		return (ft_putstr_fd("wrong number of argument.\n\t"
				"USAGE : ./connect4 [height] [width] [--display]\n", 1), 1);
	if (argc == 4 && ft_strncmp(argv[3], "--display", ft_strlen("--display")))
		return (ft_putstr_fd("Third argument not valid.\n"
				"\tUSAGE : ./connect4 [height] [width] [--display]\n", 1), 1);
	if (ft_atoi_err(argv[1], height) || *height < 6)
		return (ft_putstr_fd("invalid height (must be a valid "
				"integer >= 6)\n", 1), 1);
	if (ft_atoi_err(argv[2], width) || *width < 7)
		return (ft_putstr_fd("invalid width (must be a valid "
				"integer >= 7)\n", 1), 1);
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

static int	check_envp(char **envp)
{
	if (!envp)
		return (1);
	if (!envp[0])
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_board	board;

	if (arg_check(argc, argv, &board.width, &board.height))
		return (1);
	if (init_board(&board))
		return (ft_putstr_fd("Error : couldn't allocate memory !\n", 2), 1);
	if (argc == 3 && !(game_loop(&board)))
		ft_putstr_fd("\x1B[2J\x1B[H", 1);
	if (argc == 4 && check_envp(envp))
		return (ft_putstr_fd("Error : couldn't init mlx !\n", 2), 1);
	else if (argc == 4 && xdisplay(&board))
		return (ft_putstr_fd("Error : couldn't init mlx !\n", 2), 1);
	free_board(&board);
	return (0);
}
