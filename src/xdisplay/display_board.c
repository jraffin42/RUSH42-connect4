/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:49:10 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 11:53:27 by jraffin          ###   ########.fr       */
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
			if (board->map[x][y] == PLAYER_CHAR)
				write(1, "\e[1;43m[", 8);
			else if (board->map[x][y] == AI_CHAR)
				write(1, "\e[1;41m[", 8);
			else
				write(1, "\e[0m", 4);

			write(1, " ", 1);
			++x;
		}
		write(1, "\e[0m|\n", 6);
	}
	display_line('-', board->width + 2);
}
