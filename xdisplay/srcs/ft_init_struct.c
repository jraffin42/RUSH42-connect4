/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:19:57 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 08:59:56 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

char	*ft_strnset(char c, size_t len)
{
	char	*ret;
	size_t	i;

	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = c;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**init_map(int x, int y)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc(x + 1, sizeof(char *));
	if (!map)
		return (NULL);
	map[0] = ft_strnset('T', y);
	i = 1;
	while (i < x)
	{
		map[i] = ft_strnset('0', y);
		if (!map[i++])
			return (free_tab(map), NULL);
	}
	map[i] = NULL;
	return (map);
}

static int	ft_init1(t_c4 **c4, char **av)
{
	(*c4)->x = ft_atoi(av[0]) + 1;
	(*c4)->y = ft_atoi(av[1]);
	(*c4)->width = WIDTH;
	(*c4)->height = HEIGHT;
	(*c4)->p_color = RED;
	(*c4)->p_pos = 0;
	(*c4)->map = init_map((*c4)->x, (*c4)->y);
	if (!(*c4)->map)
		return (0);
	return (1);
}

int	ft_init(t_c4 **c4, char **av)
{
	ft_init1(c4, av);
	(*c4)->mlx = mlx_init();
	if (!(*c4)->mlx)
		return (0);
	(*c4)->win = mlx_new_window((*c4)->mlx, WIDTH * (*c4)->y,
			HEIGHT * (*c4)->x, "connect4");
	if (!(*c4)->win)
		return (0);
	if (!ft_init_tex(c4))
		return (0);
	if (!ft_init_img(c4))
		return (0);
	return (1);
}
