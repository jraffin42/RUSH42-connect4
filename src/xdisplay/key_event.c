/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 15:31:53 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"
#include "display.h"

void	end_game(t_c4 **c4, char type)
{
	display_board((*c4)->board);
	if (type == 'W')
		ft_printf(COLOR_GREEN "Win\n" COLOR_GREEN);
	if (type == 'S')
		ft_printf(COLOR_YELLOW "Spare\n" COLOR_YELLOW);
	if (type == 'L')
		ft_printf(COLOR_RED "Lose\n" COLOR_RED);
	ft_printf("Press ESC or click the red cross to exit\n");
	(*c4)->won = 1;
}

int	move_p(t_c4 **c4, int y)
{
	if (y == -1)
		y = (*c4)->y - 1;
	if (y == (*c4)->y)
		y = 0;
	mlx_put_image_to_window((*c4)->mlx, (*c4)->win, (*c4)->bg_top,
		(*c4)->p_pos * WIDTH, 0 * HEIGHT);
	if ((*c4)->p_color == RED_CHAR)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->top_red, y * WIDTH, 0 * HEIGHT);
	else if ((*c4)->p_color == YEL_CHAR)
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->top_yellow, y * WIDTH, 0 * HEIGHT);
	(*c4)->p_pos = y;
	return (1);
}

int	e_key_down(int keycode, t_c4 **c4)
{
	if (keycode == EVENT_ESC)
		ft_close(c4, 'E');
	if (!(*c4)->won)
	{
		if (keycode == EVENT_A)
			move_p(c4, (*c4)->p_pos - 1);
		if (keycode == EVENT_D)
			move_p(c4, (*c4)->p_pos + 1);
		if (keycode == EVENT_SPACE && !(*c4)->anim)
			(*c4)->move = (*c4)->p_pos;
	}
	return (0);
}
