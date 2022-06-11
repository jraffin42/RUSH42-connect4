/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:43:36 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 01:50:55 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*init_flist(const char *s, int len)
{
	t_strlist	*new;

	new = (t_strlist *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	init_flags(new);
	new->str = malloc((len + 1) * sizeof(char));
	if (!new->str)
		return (NULL);
	ft_strlcpy(new->str, s, len + 1);
	if (new->str[0] == '%')
		if (!check_f(new))
			return (NULL);
	return (new);
}

int	parse_format(t_list **lst, const char *f)
{
	int	i;

	i = 1;
	while (f[i])
	{
		if (end_char(f[i]))
		{
			ft_lstadd_back(lst, ft_lstnew(init_flist(f, ++i)));
			return (i);
		}
		else if (ok_char(f[i]))
			i++;
		else
			break ;
	}
	return (-1);
}

int	parse_str(t_list **lst, const char *f)
{
	int	i;

	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			ft_lstadd_back(lst, ft_lstnew(init_flist(f, i)));
			f += i;
			i = parse_format(lst, f);
			if (i == -1)
				return (-1);
			f += i;
			i = 0;
		}
		else
			i++;
	}
	if (i > 0)
		ft_lstadd_back(lst, ft_lstnew(init_flist(f, i)));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	myargs;
	t_list	**lst;
	size_t	len;

	if (!format)
		return (0);
	lst = 0;
	lst = malloc(sizeof(t_list **));
	if (!lst)
		return (0);
	*lst = 0;
	if (parse_str(lst, format) == -1)
		return (0);
	va_start(myargs, format);
	len = ft_lstiter_printf(*lst, &myargs, &print_lst);
	ft_lstclear(lst, &ft_clear_flst);
	free(lst);
	va_end(myargs);
	return (len);
}
