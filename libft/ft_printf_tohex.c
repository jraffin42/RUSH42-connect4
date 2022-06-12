/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tohex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:59:31 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 15:09:14 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tohex2(unsigned int nb)
{
	size_t				len;

	len = 1;
	while (nb >= 16)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

char	*ft_tohex(unsigned int nb)
{
	char	*hex;
	char	*result;
	size_t	len;

	nb = (unsigned int)(4294967295 + 1 + nb);
	hex = "0123456789abcdef";
	len = ft_tohex2(nb);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	while (nb >= 16)
	{	
		result[len--] = hex[nb % 16];
		nb /= 16;
	}
	result[len] = hex[nb % 16];
	return (result);
}
