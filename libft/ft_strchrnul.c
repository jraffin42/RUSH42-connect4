/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 07:32:40 by jraffin           #+#    #+#             */
/*   Updated: 2021/08/07 16:47:34 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *(unsigned char *)s != (unsigned char)c)
		s++;
	return ((char *)s);
}
