/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:34:27 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 01:50:46 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strsize(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n *= 0.1;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int				len;
	char			*result;

	n = (unsigned int)(4294967295 + 1 + n);
	len = ft_strsize(n);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		result[--len] = (n % 10) + '0';
		n *= 0.1;
	}
	return (result);
}
