/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:50:15 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 15:47:56 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

void	display_welcome(void)
{
	ft_printf("\e[1;33mWELCOME TO CONNECT4 !\nPRESS ENTER TO CONTINUE...\e[0m\n");
	free(ft_gnl(0));
}

void	display_ai_move(int move)
{
	static char	msg[30] = "AI played column ";

	msg[29] = move + '0';
	ft_printf("\e[1;32m");
	ft_printf("\e[1;32m%s\e[0m\n", msg);
}

void	display_info(char *message)
{
	ft_printf("%s\n", message);
}

void	display_error(char *error)
{
	ft_printf("\e[1;31m%s\e[0m\n",error, ft_strlen(error));
}

void	display_winner(int player)
{
	if (player)
	{
		ft_printf("\e[1;32mThe AI won! Sorry...\e[0m\n");
	}
	else
	{
		ft_printf("\e[1;94mYou are the winner! Congratulations!\e[0m\n");
	}
}

void	endgame(void)
{
	ft_printf("\e[1;33mPRESS ENTER TO EXIT...\e[0m\n");
	free(ft_gnl(0));
	ft_printf("\x1B[2J\x1B[H");
}
