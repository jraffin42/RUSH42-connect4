/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:13:53 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 20:24:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

static int	ft_push_img(t_c4 **c4, char c, int x, int y)
{
	if (c == ' ')
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->bg, x * WIDTH, y * HEIGHT);
	else if (c == 'P' && (*c4)->p_color == YEL_CHAR)
		if (!mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->top_yellow, x * WIDTH, y * HEIGHT));
	else if (c == 'P' && (*c4)->p_color == RED_CHAR)
		if (!mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->top_red, x * WIDTH, y * HEIGHT));
	return (0);
}

int	ft_init_img(t_c4 **c4)
{
	int	i;
	int	j;

	if (ft_push_img(c4, 'P', 0, 0))
		return (1);
	(*c4)->p_pos = 0;
	i = 1;
	while (i < (*c4)->x)
	{
		j = 0;
		while (j < (*c4)->y)
		{
			if (ft_push_img(c4, ' ', j, i))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
