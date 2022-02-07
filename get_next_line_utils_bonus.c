/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraiman <nraiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:51:20 by nraiman           #+#    #+#             */
/*   Updated: 2022/02/07 18:10:10 by nraiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (i);
	}
	while (str[i])
		i++;
	return (i);
}

int	gnl_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (-1);
	}
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(*s1) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i++])
			str[j++] = s1[i];
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	if (s1)
		free (s1);
	return (str);
}

char	*chop_line(char *remainder)
{
	int		length;
	char	*line;

	if (!remainder)
		return (NULL);
	length = 0;
	while (remainder[length] && remainder[length] != '\n')
		length++;
	line = (char *)malloc((length + 2) * (sizeof (char)));
	if (!line)
		return (NULL);
	length = 0;
	while (remainder[length] && remainder[length] != '\n')
	{
		line[length] = remainder[length];
		length++;
	}
	if (remainder[length] == '\n')
	{
		line[length] = '\n';
		length++;
	}
	line[length] = '\0';
	return (line);
}

char	*chop_remainder(char *remainder, int i, int j)
{
	char	*str;

	if (!remainder)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = (char *)malloc(sizeof (char) * (gnl_strlen(remainder) - i + 1));
	if (!str)
		return (NULL);
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return (str);
}
