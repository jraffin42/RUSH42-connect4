/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:51:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/06/12 15:09:08 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_flags(t_strlist *lst)
{
	if (!lst)
		return ;
	lst->str = 0;
	lst->form = 0;
	lst->type = 0;
}

int	check_f(t_strlist *lst)
{
	lst->type = lst->str[ft_strlen(lst->str) - 1];
	lst->form = 1;
	return (1);
}
