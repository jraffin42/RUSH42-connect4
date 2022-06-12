/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:53:30 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 15:22:36 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*print_format3(t_strlist *s, va_list *arg, int *ismalloc)
{
	if (s->type == 'u')
	{
		*ismalloc = 1;
		return (ft_uitoa(va_arg(*arg, unsigned int)));
	}
	else if (s->type == 'x')
	{
		*ismalloc = 1;
		return (ft_tohex(va_arg(*arg, int)));
	}
	else if (s->type == 'X')
	{
		*ismalloc = 1;
		return (ft_str_toupper(ft_tohex(va_arg(*arg, int))));
	}
	return (NULL);
}

static char	*print_format2(t_strlist *s, va_list *arg, int *ismalloc)
{
	if (s->type == 's')
		return (va_arg(*arg, char *));
	else if (s->type == 'p')
	{
		*ismalloc = 1;
		return (ft_getaddr(va_arg(*arg, void *)));
	}
	else if (s->type == 'd')
	{
		*ismalloc = 1;
		return (ft_printf_itoa(va_arg(*arg, int)));
	}
	else if (s->type == 'i')
	{
		*ismalloc = 1;
		return (ft_printf_itoa(va_arg(*arg, int)));
	}
	return (print_format3(s, arg, ismalloc));
}

static size_t	end_printf_format(char *str, int ismalloc)
{
	size_t	len;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	if (ismalloc)
		free(str);
	return (len);
}

size_t	print_format(t_strlist *s, va_list *arg)
{
	char	*str;
	int		ismalloc;

	ismalloc = 0;
	str = print_format2(s, arg, &ismalloc);
	if (!str)
	{
		if (s->type == '%')
		{
			ft_putchar_fd('%', 1);
			return (1);
		}
		else if (s->type == 'c')
		{
			ft_putchar_fd((char)(va_arg(*arg, int)), 1);
			return (1);
		}
	}
	return (end_printf_format(str, ismalloc));
}

size_t	print_lst(void *data, va_list *arg)
{
	t_strlist	*tmp;

	tmp = (struct str_list *)data;
	if (tmp->form == 0)
	{
		ft_putstr_fd(tmp->str, 1);
		return (ft_strlen(tmp->str));
	}
	else
	{
		return (print_format(tmp, arg));
	}
}
