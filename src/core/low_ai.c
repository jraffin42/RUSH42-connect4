/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_ai.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:47:33 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 11:40:01 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "core.h"

int undo_move(t_board *board, int move)
{
    int x;

    x = -1;
    while (++x < board->height)
        if (board->map[x][move] != NUL_CHAR)
            return ((board->map[x][move] = NUL_CHAR), 0);
    return (1);
}

int play_move(t_board *board, int move, char c)
{
    int x;

    x = board->height;
    while (--x >= 0)
        if (board->map[x][move] == NUL_CHAR)
        {
            return ((board->map[x][move] = c), 0);
        }
    return (1);
}

int check_connect4(t_board *board)
{
    int i;

    i = -1;
    while (++i < board->width)
    {
        if (is_won(board, i))
            return (i);
    }
    return (-1);
}

int mid_prio(t_board *board)
{
    int i;

    i = board->width/2 - 1;
    while (++i < board->width)
    {
        if (board->map[board->height - 1][i] == NUL_CHAR)
            return (i);
    }
    return (-1);
}

int low_ai(t_board *board)
{
    int move;
    
    move = check_connect4(board);
    if (move != -1)
        return (move);
    move = mid_prio(board);
    if (move != -1)
        return (move);
    return (-1);
}
