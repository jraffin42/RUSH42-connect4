/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:49:10 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 15:32:35 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

static void	display_line(char c, int count)
{
	while (count--)
		ft_printf("%c", c);
	ft_printf("\n");
}

void	display_board(t_board *board)
{
	int	x;
	int	y;

	ft_printf("\x1B[2J\x1B[H");
	display_line('-', board->width + 2);
	y = board->height;
	while (y--)
	{
		ft_printf("|");
		x = 0;
		while (x < board->width)
		{
			if (board->map[x][y] == RED_CHAR)
				ft_printf("\e[1;91mX");
			else if (board->map[x][y] == YEL_CHAR)
				ft_printf("\e[1;93m0");
			else
				ft_printf("\e[0m ");
			++x;
		}
		ft_printf("\e[0m|\n", 6);
	}
	display_line('-', board->width + 2);
	ft_printf("\n");
}
