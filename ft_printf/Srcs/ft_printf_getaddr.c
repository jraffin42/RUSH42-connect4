/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getaddr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:24:35 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 01:50:47 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_tohexl2(unsigned long int nb)
{
	size_t	len;

	len = 1;
	while (nb >= 16)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static char	*ft_tohexl(unsigned long int nb)
{
	char	*hex;
	char	*result;
	size_t	len;

	hex = "0123456789abcdef";
	len = ft_tohexl2(nb);
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

char	*ft_getaddr(void *ptr)
{
	char	*addr;
	char	*r;

	if (!ptr)
		return (ft_strdup("(nil)"));
	addr = ft_tohexl((unsigned long int)ptr);
	if (!addr)
		return (NULL);
	r = malloc((ft_strlen(addr) + 2 + 1) * sizeof(char));
	if (!r)
	{
		free(addr);
		return (NULL);
	}
	ft_memcpy(r, "0x\0", 3);
	ft_strlcat(r, addr, 3 + ft_strlen(addr) + 1);
	free(addr);
	return (r);
}
