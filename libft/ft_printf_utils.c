/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:49:10 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 15:22:09 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsize(int n, int *minus, unsigned int *tmp)
{
	int				len;

	len = 1;
	*minus = 1;
	if (n < 0)
	{
		*tmp = -n;
		*minus = -1;
		len++;
	}
	else
		*tmp = n;
	while (*tmp >= 10)
	{
		*tmp *= 0.1;
		len++;
	}
	*tmp = n * (*minus);
	return (len);
}

char	*ft_printf_itoa(int n)
{
	int				len;
	int				minus;
	char			*result;
	unsigned int	tmp;

	len = ft_strsize(n, &minus, &tmp);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		result[--len] = (tmp % 10) + '0';
		tmp *= 0.1;
	}
	if (minus == -1)
		result[0] = '-';
	return (result);
}

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
