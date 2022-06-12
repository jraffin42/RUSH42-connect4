/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:49:10 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 21:44:41 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

static void	ft_putchar_count(char c, int count)
{
	while (count--)
		ft_putchar_fd(c, 1);
}

static void	display_line(char c, int count)
{
	ft_putchar_count(c, count);
	ft_putchar_fd('\n', 1);
}

static void	display_numbers(int count)
{
	char	numbuf[12];
	int		i;
	int		indent;
	int		len;

	i = 0;
	while (i < count)
	{
		len = ft_intlen(i);
		indent = 2 - (len / 2);
		ft_putchar_count(' ', indent);
		ft_itoa(i, numbuf);
		ft_putstr_fd(numbuf, 1);
		ft_putchar_count(' ', 4 - indent - len);
		++i;
	}
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
}

void	display_board(t_board *board)
{
	int	x;
	int	y;

	ft_putstr_fd("\x1B[2J\x1B[H", 1);
	y = board->height;
	while (y--)
	{
		display_line('-', board->width * 4 + 1);
		ft_putchar_fd('|', 1);
		x = 0;
		while (x < board->width)
		{
			ft_putchar_fd(' ', 1);
			if (board->map[x][y] == RED_CHAR)
				ft_putstr_fd("\e[1;91m", 1);
			else if (board->map[x][y] == YEL_CHAR)
				ft_putstr_fd("\e[1;93m", 1);
			else
				ft_putstr_fd("\e[0m", 1);
			ft_putchar_fd(board->map[x][y], 1);
			ft_putstr_fd("\e[0m |", 1);
			++x;
		}
		ft_putchar_fd('\n', 1);
	}
	display_line('-', board->width * 4 + 1);
	display_numbers(board->width);
}
