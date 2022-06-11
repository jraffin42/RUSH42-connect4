/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:33:36 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/11 00:22:28 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;

	if (count && size > SIZE_MAX / count)
		return (NULL);

	mem = malloc(count * size);
	if (mem)
		return (ft_memset(mem, 0, count * size));
	else
		return (NULL);
}
