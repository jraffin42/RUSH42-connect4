/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:45:03 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 18:53:58 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

static int	ft_init_bg(t_c4 **c4)
{
	(*c4)->bg = mlx_xpm_file_to_image((*c4)->mlx,
			"./textures/bg.xpm", &(*c4)->width, &(*c4)->height);
	(*c4)->bg_top = mlx_xpm_file_to_image((*c4)->mlx,
			"./textures/tbg.xpm", &(*c4)->width, &(*c4)->height);
	if (!(*c4)->bg || !(*c4)->bg_top)
		return (1);
	return (0);
}

static int	ft_init_player(t_c4 **c4)
{
	(*c4)->red = mlx_xpm_file_to_image((*c4)->mlx,
			"./textures/red.xpm", &(*c4)->width, &(*c4)->height);
	(*c4)->top_red = mlx_xpm_file_to_image((*c4)->mlx,
			"./textures/tred.xpm", &(*c4)->width, &(*c4)->height);
	(*c4)->yellow = mlx_xpm_file_to_image((*c4)->mlx,
			"./textures/yel.xpm", &(*c4)->width, &(*c4)->height);
	(*c4)->top_yellow = mlx_xpm_file_to_image((*c4)->mlx,
			"./textures/tyel.xpm", &(*c4)->width, &(*c4)->height);
	if (!(*c4)->red || !(*c4)->top_red || !(*c4)->yellow || !(*c4)->top_yellow)
		return (1);
	return (0);
}

int	ft_init_tex(t_c4 **c4)
{
	if (ft_init_bg(c4))
		return (1);
	if (ft_init_player(c4))
		return (1);
	return (0);
}
