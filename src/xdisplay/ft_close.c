/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:39:15 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 17:15:00 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

static void	free_struct(void *mlx, void *ptr, char type)
{
	if (type == 'I' && ptr && mlx)
		mlx_destroy_image(mlx, ptr);
	else if (type == 'W' && ptr && mlx)
		mlx_destroy_window(mlx, ptr);
	else if (type == 'M' && mlx)
		mlx_destroy_display(mlx);
	else if (type == 'P' && ptr)
		free(ptr);
}

int	red_cross_close(t_c4 **c4)
{
	mlx_loop_end((*c4)->mlx);
	return (0);
}

static int	ft_close_img(t_c4 **c4)
{
	free_struct((*c4)->mlx, (*c4)->bg, 'I');
	free_struct((*c4)->mlx, (*c4)->bg_top, 'I');
	free_struct((*c4)->mlx, (*c4)->red, 'I');
	free_struct((*c4)->mlx, (*c4)->top_red, 'I');
	free_struct((*c4)->mlx, (*c4)->yellow, 'I');
	free_struct((*c4)->mlx, (*c4)->top_yellow, 'I');
	return (0);
}

void	ft_close(t_c4 **c4)
{
	ft_close_img(c4);
	free_board((*c4)->board);
	free_struct((*c4)->mlx, (*c4)->win, 'W');
	free_struct((*c4)->mlx, NULL, 'M');
	ft_putstr_fd(COLOR_YELLOW "Exit\n" COLOR_YELLOW, 1);
	free_struct(NULL, (*c4)->mlx, 'P');
	free_struct(NULL, (*c4), 'P');
}
