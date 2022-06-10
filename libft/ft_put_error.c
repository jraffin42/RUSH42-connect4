/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 03:57:51 by jraffin           #+#    #+#             */
/*   Updated: 2021/12/13 10:25:52 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <linux/limits.h>

int	ft_put_error(char *launch_path, char *object, char *msg, int ret_value)
{
	static char	buf[PATH_MAX * 3 + 5];
	char		*basename;
	size_t		len;

	basename = ft_basename(launch_path);
	len = 0;
	if (basename)
	{
		len += ft_strlcpy(buf + len, basename, PATH_MAX + 1);
		len += ft_strlcpy(buf + len, ": ", 3);
	}
	if (object)
	{
		len += ft_strlcpy(buf + len, object, PATH_MAX + 1);
		len += ft_strlcpy(buf + len, ": ", 3);
	}
	if (msg)
		len += ft_strlcpy(buf + len, msg, PATH_MAX + 1);
	else
		len += ft_strlcpy(buf + len, strerror(errno), PATH_MAX + 1);
	len += ft_strlcpy(buf + len, "\n", 2);
	if (write(STDERR_FILENO, buf, len))
		NULL;
	return (ret_value);
}
