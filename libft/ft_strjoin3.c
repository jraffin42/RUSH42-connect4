/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:03:56 by bcano             #+#    #+#             */
/*   Updated: 2022/01/25 20:36:47 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s0, char const *s1, char const *s2)
{
	size_t	len[3];
	char	*newstr;

	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	if (s0)
		len[0] = ft_strlen(s0);
	if (s1)
		len[1] = ft_strlen(s1);
	if (s2)
		len[2] = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len[0] + len[1] + len[2] + 1));
	if (!newstr)
		return (NULL);
	newstr[len[0] + len[1] + len[2]] = '\0';
	while (len[2]-- > 0)
		newstr[len[0] + len[1] + len[2]] = s2[len[2]];
	while (len[1]-- > 0)
		newstr[len[0] + len[1]] = s1[len[1]];
	while (len[0]-- > 0)
		newstr[len[0]] = s0[len[0]];
	return (newstr);
}
