/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:49:10 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 01:50:53 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ok_char(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || ft_isdigit(c)
		|| c == '.')
		return (1);
	return (0);
}

int	end_char(char c)
{
	if (c == 'c' || c == 'p' || c == 's' || c == 'x' || c == 'X'
		|| c == 'd' || c == 'i' || c == 'u' || c == '%')
		return (1);
	return (0);
}

char	*ft_str_toupper(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
