/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:40:56 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 18:10:56 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

char	*ft_itoa(int n, char *str)
{
	int	i;

	i = ft_intlen(n);
	if (!str)
		return (NULL);
	if (n > 0)
		n = -n;
	str[i] = '\0';
	str[--i] = '0' - (n % 10);
	n /= 10;
	while (n)
	{
		str[--i] = '0' - (n % 10);
		n /= 10;
	}
	if (i)
		str[0] = '-';
	return (str + i);
}
