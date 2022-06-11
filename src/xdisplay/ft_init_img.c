/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:13:53 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 08:48:07 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

static int	ft_push_img(t_c4 **c4, char c, int x, int y)
{
	if (c == 'T')
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->bg_top, (x * WIDTH), (y * HEIGHT));
	if (c == '0')
		mlx_put_image_to_window((*c4)->mlx, (*c4)->win,
			(*c4)->bg, x * WIDTH, y * HEIGHT);
	return (1);
}

int	ft_init_img(t_c4 **c4)
{
	int	i;
	int	j;

	i = 0;
	while ((*c4)->map[i])
	{
		j = 0;
		while ((*c4)->map[i][j] != '\0')
		{
			ft_push_img(c4, (*c4)->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (1);
}
