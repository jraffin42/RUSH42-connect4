/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:50:15 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 16:30:59 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

void	display_welcome(void)
{
	ft_putstr_fd("\e[1;33mWELCOME TO CONNECT4 !\nPRESS ENTER TO CONTINUE...\e[0m\n", 1);
	free(ft_gnl(0));
}

void	display_ai_move(int move)
{
	static char	msg[30] = "AI played column ";

	msg[29] = move + '0';
	ft_putstr_fd("\e[1;32m", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\e[0m\n", 1);

}

void	display_info(char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
}

void	display_error(char *error)
{
	ft_putstr_fd("\e[1;31m", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
}

void	display_winner(int player)
{
	if (player)
	{
		ft_putstr_fd("\e[1;32mThe AI won! Sorry...\e[0m\n", 1);
	}
	else
	{
		ft_putstr_fd("\e[1;94mYou are the winner! Congratulations!\e[0m\n", 1);
	}
}

void	endgame(void)
{
	ft_putstr_fd("\e[1;33mPRESS ENTER TO EXIT...\e[0m\n", 1);
	free(ft_gnl(0));
	ft_putstr_fd("\x1B[2J\x1B[H", 1);
}
