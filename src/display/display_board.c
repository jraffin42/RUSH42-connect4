/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:49:10 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 23:58:41 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

static void	display_line(char c, int count)
{
	while (count--)
		write(1, &c, 1);
	write(1, "\n", 1);
}

static void	display_digits(int count)
{
	int		i;
	char	c;

	write(1, " ", 1);
	i = 0;
	while (i < count)
	{
		c = '0' + i % 10;
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
}

void	display_board(t_board *board)
{
	int	x;
	int	y;

	write(1, "\x1B[2J\x1B[H", 7);
	display_line('-', board->width + 2);
	y = board->height;
	while (y--)
	{
		write(1, "|", 1);
		x = 0;
		while (x < board->width)
		{
			if (board->map[x][y] == RED_CHAR)
				write(1, "\e[1;91m", 7);
			else if (board->map[x][y] == YEL_CHAR)
				write(1, "\e[1;93m", 7);
			else
				write(1, "\e[0m", 4);
			write(1, &board->map[x][y], 1);
			++x;
		}
		write(1, "\e[0m|\n", 6);
	}
	display_line('-', board->width + 2);
	display_digits(board->width);
	write(1, "\n", 1);
}
