/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:07:35 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 14:39:42 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define RED_CHAR	'X'
# define YEL_CHAR	'O'
# define NUL_CHAR	' '
# define NUM_TO_WIN		4

//	token[0] for AI token, token[1] for player token.
typedef struct s_board
{
	int		width;
	int		height;
	char	**map;
	int		*lengths;
	int		left;
	char	token[2];
}	t_board;

int		init_board(t_board *board);
void	free_board(t_board *board);
int		is_full(t_board *board);
char	is_won(t_board *board, int last_move);

int		ai_turn(t_board *board);
int		player_turn(t_board *board);

int		game_loop(t_board *board);

int 	play_move(t_board *board, int move, char c);

#endif
