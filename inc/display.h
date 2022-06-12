/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:07:52 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 17:37:26 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "core.h"

void	endgame(void);

void	display_board(t_board *board);

void	display_info(char *msg);
void	display_error(char *error);

#endif
