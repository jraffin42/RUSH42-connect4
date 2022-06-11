/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/11 12:00:45 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xdisplay.h"

void	ft_usage(void)
{
	ft_putstr_fd("Error\nusage: ./connect4 n_line n_column [--display]\n", 2);
}

/*int	main(int ac, char **av)
{
	t_c4	*c4;

	if (ac < 3)
	{
		ft_usage();
		return (0);
	}
	c4 = (t_c4 *)ft_calloc(1, sizeof(t_c4));
	if (!c4)
		return (0);
	if (!ft_init(&c4, &av[1]))
	{
		ft_close(&c4, 'E');
		return (0);
	}
	mlx_key_hook(c4->win, e_key_down, &c4);
	mlx_hook(c4->win, 17, 1L << 17, red_cross_close, &c4);
	mlx_loop(c4->mlx);
	ft_close(&c4, 'W');
	return (EXIT_SUCCESS);
}*/
