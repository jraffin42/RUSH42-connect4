/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:22:33 by jraffin           #+#    #+#             */
/*   Updated: 2022/01/21 15:46:43 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (!s)
		return (NULL);
	while (*s && start)
	{
		s++;
		start--;
	}
	strlen = 0;
	while (s[strlen] && strlen < len)
		strlen++;
	str = malloc(sizeof(char) * (strlen + 1));
	ft_strlcpy(str, s, (strlen + 1));
	return (str);
}
