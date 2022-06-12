/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:31:01 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 12:40:08 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

void	clean_gnl(char *s)
{
	char	*ptr;

	ptr = ft_strchr(s, '\n');
	if (!ptr)
		return ;
	*ptr = '\0';
}

int	player_turn(t_board *board)
{
	int		err;
	int		move;
	char	*line;
	char	*err_str;

	move = -1;
	err_str = "";
	line = "";
	while (1)
	{
		display_error(err_str);
		display_info("Please enter the column you want to play : ");
		line = ft_gnl(0);
		if (!line)
			return (-1);
		clean_gnl(line);
		err = ft_atoi_err(line, &move);
		free(line);
		if (err)
			err_str = "Invalid integer.";
		else if (move < 0 || move >= board->width)
			err_str = "Column out of range.";
		else if (board->lengths[move] == board->height)
			err_str = "Column filled.";
		else
			return (move);
		display_board(board);
	}
}
