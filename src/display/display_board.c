/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:49:10 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 16:36:03 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

static void	display_line(char c, int count)
{
	while (count--)
		ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

static void	display_digits(int count)
{
	int		i;
	char	c;

	ft_putchar_fd(' ', 1);
	i = 0;
	while (i < count)
	{
		c = '0' + i % 10;
		ft_putchar_fd(c, 1);
		++i;
	}
		ft_putchar_fd('\n', 1);
}

void	display_board(t_board *board)
{
	int	x;
	int	y;

	ft_putstr_fd("\x1B[2J\x1B[H", 1);
	display_line('-', board->width + 2);
	y = board->height;
	while (y--)
	{
		ft_putchar_fd('|', 1);
		x = 0;
		while (x < board->width)
		{
			if (board->map[x][y] == RED_CHAR)
				ft_putstr_fd("\e[1;91m", 1);
			else if (board->map[x][y] == YEL_CHAR)
				ft_putstr_fd("\e[1;93m", 1);
			else
				ft_putstr_fd("\e[0m", 1);
			ft_putchar_fd(board->map[x][y], 1);
			++x;
		}
		ft_putstr_fd("\e[0m|\n", 1);
	}
	display_line('-', board->width + 2);
	display_digits(board->width);
	ft_putchar_fd('\n', 1);
}
