/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraiman <nraiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:18:27 by nraiman           #+#    #+#             */
/*   Updated: 2022/01/28 18:36:26 by nraiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

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
	static char	*remainder;
	char		*buff;
	char		*line;

	if (fd == -1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	remainder = read_extend (fd, buff, remainder);
	free (buff);
	line = chop_line(remainder);
	remainder = chop_remainder(remainder, 0, 0);
	return (line);
}

/*int main(void)
{
    char    *str;
    int fd;

    fd = open("text.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    free(str);
	return (0);
}*/