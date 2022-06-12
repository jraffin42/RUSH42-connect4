/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:31:01 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 17:42:26 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"
#include "display.h"

int	get_move_and_free_line(char *line, int *move)
{
	char	*ptr;
	int		ret;

	ptr = ft_strchr(line, '\n');
	if (ptr)
		*ptr = '\0';
	ret = ft_atoi_err(line, move);
	free(line);
	return (ret);
}

int	player_turn(t_board *board)
{
	int		move;
	char	*line;
	char	*err_str;

	move = -1;
	err_str = "";
	while (1)
	{
		display_error(err_str);
		display_info("Please enter the column you want to play : ");
		line = ft_gnl(0);
		if (!line)
			return (-1);
		if (get_move_and_free_line(line, &move))
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
