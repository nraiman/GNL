/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraiman <nraiman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:58:28 by nraiman           #+#    #+#             */
/*   Updated: 2022/01/28 16:41:56 by nraiman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
int		gnl_strlen(char *str);
int		gnl_strchr(char *str, char c);
char	*gnl_strjoin(char *s1, char *s2);
char	*chop_line(char *remainder);
char	*chop_remainder(char *remainder, int i, int j);

#endif
