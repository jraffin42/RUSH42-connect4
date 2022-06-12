/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:50:15 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 20:54:39 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

void	display_info(char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
}

void	display_error(char *error)
{
	ft_putstr_fd("\e[1;31m", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\e[0m\n", 2);
}

void	xdisplay_error(char **s)
{
	if (s)
	{
		if (*s)
		{
			display_error(*s);
			free(*s);
			*s = NULL;
		}
	}
	else
		display_error("");
}
