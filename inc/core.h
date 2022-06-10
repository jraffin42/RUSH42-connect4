/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:07:35 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/10 22:27:31 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

// in map : 0 for empty, 1 for player, -1 for IA
typedef struct s_board
{
	char			map[256][256];
	unsigned char	width;
	unsigned char	height;
}	t_board;

#endif
