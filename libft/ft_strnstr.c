/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:16:50 by jraffin           #+#    #+#             */
/*   Updated: 2021/04/12 05:03:57 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	_Bool	found;

	if (!little[0])
		return ((char *)big);
	i = 0;
	j = 0;
	found = 0;
	while (!found && i < len && big[i])
	{
		if (little == (big + i))
			return ((char *)little);
		j = 0;
		while ((i + j) < len && big[i + j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			found = 1;
		else
			i++;
	}
	if (found)
		return ((char *)(big + i));
	return (0);
}
