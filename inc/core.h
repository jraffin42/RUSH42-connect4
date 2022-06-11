/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:07:35 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 04:01:26 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define PLAYER_CHAR	'X'
# define AI_CHAR		'O'
# define NUM_TO_WIN		4

typedef struct s_board
{
	int		width;
	int		height;
	char	**map;
	int		*lengths;
}	t_board;

int		allocate_board(t_board *board);
void	free_board(t_board *board);
int		is_full(t_board *board);
char	is_won(t_board *board, int last_move);

int		ai_turn(t_board *board);
int		player_turn(t_board *board);


#endif
