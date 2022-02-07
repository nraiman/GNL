/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraiman <nraiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:59:28 by nraiman           #+#    #+#             */
/*   Updated: 2022/02/07 18:24:50 by nraiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

char	*read_extend(int fd, char *buff, char *remainder)
{
	ssize_t	read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && gnl_strchr(remainder, '\n') == -1)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buff[read_bytes] = '\0';
			remainder = gnl_strjoin(remainder, buff);
		}
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*buff;
	char		*line;

	if (fd == -1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	remainder[fd] = read_extend (fd, buff, remainder[fd]);
	free (buff);
	line = chop_line(remainder[fd]);
	remainder[fd] = chop_remainder(remainder[fd], 0, 0);
	return (line);
}
