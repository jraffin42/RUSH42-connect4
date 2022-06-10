/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:39:10 by jraffin           #+#    #+#             */
/*   Updated: 2021/06/09 20:01:23 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putnbr_fd(int n, int fd)
{
	static char	buf[11];
	bool		neg;
	int			i;

	neg = (n < 0);
	if (n > 0)
		n = -n;
	i = 10;
	buf[i] = '0' - (n % 10);
	n /= 10;
	while (n)
	{
		buf[--i] = '0' - (n % 10);
		n /= 10;
	}
	if (neg)
		buf[--i] = '-';
	if (write(fd, buf + i, 11 - i))
		NULL;
}
