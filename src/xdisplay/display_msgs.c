/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:50:15 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 14:58:11 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

void	display_welcome(void)
{
	write(1, "\e[1;33m", 7);
	write(1, "WELCOME TO CONNECT4 !\nPRESS ENTER TO CONTINUE...", 48);
	write(1, "\e[0m\n", 5);
	free(ft_gnl(0));
}

void	display_ai_move(int move)
{
	static char	msg[30] = "AI played column ";

	msg[29] = move + '0';
	write(1, "\e[1;32m", 7);
	write(1, msg, 9);
	write(1, "\e[0m\n", 5);
}

void	display_info(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
}

void	xdisplay_error(char *s)
{
	if (s)
	{	display_error(s);
		free(s);
		s = NULL;
	}
	else
		display_error("");
}

void	display_error(char *error)
{
	write(1, "\e[1;31m", 7);
	write(1, error, ft_strlen(error));
	write(1, "\e[0m\n", 5);
}

void	display_winner(int player)
{
	if (player)
	{
		write(1, "\e[1;32m", 7);
		write (1, "The AI won! Sorry...", 20);
	}
	else
	{
		write(1, "\e[1;94m", 7);
		write (1, "You are the winner! Congratulations!", 36);
	}
	write(1, "\e[0m\n", 5);
}

void	endgame(void)
{
	write(1, "\e[1;33m", 7);
	write(1, "PRESS ENTER TO EXIT...", 22);
	write(1, "\e[0m\n", 5);
	free(ft_gnl(0));
	write(1, "\x1B[2J\x1B[H", 7);
}
