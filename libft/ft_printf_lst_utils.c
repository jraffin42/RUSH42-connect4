/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lst_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:27:51 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 15:08:51 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_flst(void *lst)
{
	t_strlist	*tmp;

	tmp = (struct str_list *)lst;
	if (tmp->str)
		free(tmp->str);
	free(tmp);
}

size_t	ft_lstiter_printf(t_list *lst, va_list *va_lst,
		size_t (*f)(void *, va_list *))
{
	t_list	*index;
	size_t	len;

	if (!lst || !f)
		return (0);
	index = lst;
	len = 0;
	while (index)
	{
		len += (*f)(index->content, va_lst);
		index = index->next;
	}
	return (len);
}
