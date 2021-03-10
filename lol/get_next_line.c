#ifndef BUFFERSIZE
# define BUFFERSIZE 128
#endif

#include "get_next_line.h"
#include <stdio.h>

int ft_strchrlen(char *str, char c)
{
	int i = 0;
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

char *ft_strjoin(char *str1, char *str2)
{
	char *str;
	int i = 0, j = 0;
	
	str = (char *)malloc(sizeof(char) * (ft_strchrlen(str1, '\0') + ft_strchrlen(str2, '\0') + 1));
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
		
	while (str2[j])
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str1);
	return (str);
}

char *ft_substr(char *s, unsigned int start, int len)
{
	char *str;
	int i = 0;

	str = (char *)malloc(sizeof(char) * (len - start + 1));
	if (!str)
		return (NULL);
	while (start < (unsigned)len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}


int get_next_line(char **line)
{
	static char	*tail;
	char 		*tmp;
	char 		buff[BUFFERSIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	// initialize tail
	if (!tail)
	{
		tail = (char *)malloc(1);
		tail[0] = '\0';
		if (!tail)
			return (-1);
	}
	// read till \n or eof
	while (ft_strchrlen(tail, '\n') < 0 && (ret = read(0, buff, BUFFERSIZE)) > 0)
	{
		buff[ret] = '\0';
		tail = ft_strjoin(tail, buff);
	}
	// check if eof by checking for \n
	if (ft_strchrlen(tail, '\n') == -1)
	{
		*line = ft_substr(tail, 0, ft_strchrlen(tail, '\0'));
		free(tail);
		return (0);
	}
	//normal proc if no eof reached
	*line = ft_substr(tail, 0, ft_strchrlen(tail, '\n'));
	tmp = tail;
	tail = ft_substr(tail, ft_strchrlen(tail, '\n') + 1, ft_strchrlen(tail, '\0'));
	free(tmp);
	return (1);
}
