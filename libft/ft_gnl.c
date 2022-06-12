/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraffin <jraffin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:42:49 by jraffin           #+#    #+#             */
/*   Updated: 2022/06/12 17:18:05 by jraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*add_n_to_line(char *line, size_t *len, t_gnlbuf *buffer, size_t n)
{
	char	*newline;

	if (!n)
		return (line);
	newline = malloc(sizeof(char) * (*len + n + 1));
	newline[*len + n] = '\0';
	if (!newline)
		return (free(line), NULL);
	ft_memmove(newline, line, *len);
	free(line);
	ft_memmove(newline + *len, buffer->data, n);
	*len += n;
	ft_memmove(buffer->data, buffer->data + n, buffer->size - n);
	buffer->size -= n;
	return (newline);
}

static char	*gnl_core(t_gnlbuf *buf, int fd)
{
	char			*nl;
	char			*line;
	size_t			linelen;

	line = NULL;
	linelen = 0;
	nl = ft_memchr(buf->data, '\n', buf->size);
	while (!nl)
	{
		line = add_n_to_line(line, &linelen, buf, buf->size);
		if (buf->size && !line)
			return (NULL);
		buf->size = read(fd, buf->data, GNL_BUFFER_SIZE);
		if (buf->size < 0)
			buf->size = (free(line), line = NULL, 0);
		if (!buf->size)
			return (line);
		nl = ft_memchr(buf->data, '\n', buf->size);
	}
	line = add_n_to_line(line, &linelen, buf, nl - buf->data + 1);
	return (line);
}

static void	cleanup(t_gnlbuf **buf, int fd)
{
	if (fd < GNL_FD_MAXSIZE)
		buf[fd] = (free(buf[fd]), NULL);
	else
	{
		fd = -1;
		while (++fd < GNL_FD_MAXSIZE)
			buf[fd] = (free(buf[fd]), NULL);
	}
}

char	*ft_gnl(int fd)
{
	static t_gnlbuf	*buf[GNL_FD_MAXSIZE];
	char			*line;

	if (fd < 0)
		return (cleanup(buf, fd), NULL);
	if (fd >= GNL_FD_MAXSIZE)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc(sizeof(t_gnlbuf));
		buf[fd]->size = 0;
	}
	if (!buf[fd])
		return (NULL);
	line = gnl_core(buf[fd], fd);
	if (!line || !buf[fd]->size)
		buf[fd] = (free(buf[fd]), NULL);
	return (line);
}
