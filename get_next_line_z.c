/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_z.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 19:01:34 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/06 20:40:01 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

#include <stdio.h>
#include "get_next_line.h"

int		ft_len_chr(char *str, char c) // c = \0 = strlen
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		++i;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *str;
	int i, j;
	i = 0;
	j = 0;

	str = (char *)malloc(sizeof(char) * (ft_len_chr(s1, '\0') + ft_len_chr(s2, '\0') + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char *str;
	int i = 0;

	str = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	while (start < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int		get_next_line(char **line)
{
	static char *tail;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	
	if (!line)
		return (-1);
	if (!tail)
	{
		tail = (char *)malloc(1);
		tail = 0;
		if (!tail)
			return (-1);
	}
	while (ft_len_chr(tail, '\n') == -1 && (ret = read(0, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tail = ft_strjoin(tail, buff);
	}
	if (ft_len_chr(tail, '\n') == -1)
	{
		*line = ft_substr(tail, 0, ft_len_chr(tail, '\0'));
		free(tail);
		return (0);
	}
	*line = ft_substr(tail, 0, ft_len_chr(tail, '\n'));
	tmp = tail;
	tail = ft_substr(tail, ft_len_chr(tail, '\n') + 1, ft_len_chr(tail, '\0'));
	free(tmp);
	return (1);
}