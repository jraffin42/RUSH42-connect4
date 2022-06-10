/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:54:56 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/15 18:41:45 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#define LLMAX_D10 922337203685477580

int	ft_atoll_err(const char *str, long long int *nbr)
{
	bool					neg;
	unsigned long long int	abs;

	if (!*str)
		return (1);
	neg = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	abs = 0;
	while (*str == '0')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (abs >= LLMAX_D10 && (abs > LLMAX_D10 || *str > ('7' + neg)))
			return (1);
		abs *= 10;
		abs += *str - '0';
		str++;
	}
	if (*str)
		return (1);
	*nbr = abs;
	if (neg)
		*nbr = -abs;
	return (0);
}
