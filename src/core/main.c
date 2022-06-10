/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:08:07 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/10 22:22:39 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**alloc_map(int width, int height)
{

}

int	arg_check(int argc, char **argv, int *width, int *height)
{
	if (argc != 3)
		return (ft_put_error(argv[0], "",
				"wrong number of argument.\n\t"
				"USAGE : ./connect4 [height] [width]", 1));
	if (ft_atoi_err(argv[1], height) || *height < 6 || *height > 255)
		return (ft_put_error(argv[0], "",
				"invalid height (must be a valid number in range [6, 255]", 1));
	if (ft_atoi_err(argv[2], width) || *width < 7 || *width > 255)
		return (ft_put_error(argv[0], "",
				"invalid width (must be a valid number in range [7, 255]", 1));
	return (0);
}

int	main(int argc, char** argv)
{
	int	width;
	int	height;

	if (arg_check(argc, argv, &width, &height))
		return (1);


}
