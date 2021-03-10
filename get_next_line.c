/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/06 17:32:19 by ztan          #+#    #+#                 */
/*   Updated: 2020/12/06 20:21:32 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

#include "get_next_line.h"
// this is ft_strlen and ft_strchr in 1 function, if you call it with '\0' as the character parameter it is strlen, else it measures the distance to c (usually '\n') in an int
static int      ft_len_until_c(char *str, char c)
{
    int     i;
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    if (c == '\0')
        return (i);
    return (-1);
}
// this is just strjoin with one key difference; free(s1) at the end which frees the previous version of your static character variable, so you don't have to mess around with another *temp in your main
static char     *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    int     i;
    int     j;
    i = 0;
    j = 0;
    if (!(str = malloc(sizeof(char) * (ft_len_until_c(s1, '\0') + ft_len_until_c(s2, '\0') + 1))))
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    free(s1);
    str[i] = '\0';
    return (str);
}
// very simple ft_substr, malloc protection probably unnecessary because you're only calling it from your main
static char     *ft_substr(char *s, unsigned int start, int len)
{
    char    *str;
    int     i;
    i = 0;
    if (!(str = malloc(sizeof(char) * (len - start + 1))))
        return (NULL);
    while (start < (unsigned)len)
        str[i++] = s[start++];
    str[i] = '\0';
    return (str);
}
// the rest is rather simple, malloc size of 1 for the first iteration, then keep reading until there's nothing left or you find an '\n', and then place the appropriate string into *line and free the previous static
int             get_next_line(char **line)
{
    static char     *rest;
    char            *tmp;
    char            buf[BUFFER_SIZE + 1];
    int             ret;
    if (!line)
        return (-1);
    if (!rest)
    {
        rest = (char *)malloc(1);
        rest = 0;
        if (!rest)
            return (-1);
    }
    while ((ft_len_until_c(rest, '\n')) < 0 && (ret = read(0, buf, BUFFER_SIZE)) > 0)
    {
        buf[ret] = '\0';
        rest = ft_strjoin(rest, buf);
    }
    if ((ft_len_until_c(rest, '\n')) < 0)
    {
        *line = ft_substr(rest, 0, ft_len_until_c(rest, '\0'));
        free(rest);
        return (0);
    }
    *line = ft_substr(rest, 0, ft_len_until_c(rest, '\n'));
    tmp = rest;
    rest = ft_substr(rest, ft_len_until_c(rest, '\n') + 1, ft_len_until_c(rest, '\0'));
    free(tmp);
    return (1);
}