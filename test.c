/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:24:13 by dayou             #+#    #+#             */
/*   Updated: 2023/05/19 22:05:46 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(char *s1)
{
	char	*line;
	size_t	size;
    size_t  idx;
    
    size = 0;
	while (s1[size])
        size++;
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (line == NULL)
		return (NULL);
    idx = 0;
	while (s1[idx])
	{
		line[idx] = s1[idx];
		idx++;
	}
	line[size] = '\0';
	return (line);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t size)
{
	size_t	len;
    size_t  result;
	char	*line;

	len = 0;
	while (s1[len])
        len++;
    result = len;
    while (len <= size)
        len++;
    result += len;
	line = (char *)malloc(sizeof(char) * (result + 1));
	if (line == NULL)
		return (NULL);
    line[result] = '\0';
    len = ft_strlcpy(line, s1);
    ft_strlcpy(line + len, s2);
    free(s1);
	return (line);
}

size_t	ft_strlcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i > 0)
		dest[i] = '\0';
	return (i);
}

ssize_t ft_strchr(char *str, int c)
{
	char	character;
	ssize_t	i;

	i = 0;
	character = (char)c;
	while (str[i])
	{
		if (str[i] == character)
			return (i);
		i++;
	}
	return (-1);
}

//개행체크 + 널체크해서 붙이기, 밀기.

char * get_next_line(int fd)
{
    static char remainder[BUFFER_SIZE + 1] = {0, };
    char buff[BUFFER_SIZE + 1];
    char * line;
    ssize_t size;
    ssize_t flag;

    line = ft_strdup("");
    if (-1 < (size = ft_strchr(remainder, '\n')))
    {
        line = ft_strjoin(line, remainder, size);
        ft_strlcpy(remainder, remainder + size + 1);
        return line;
    }
    else
    {   
        while (-1 < (flag = read(fd, buff, BUFFER_SIZE)))
        {
            if(flag == 0)
                break;
            buff[flag] = '\0';
            if ((size = ft_strchr(buff, '\n')))
            {
                line = ft_strjoin(line, buff, size);
                ft_strlcpy(remainder, buff + size + 1);
                return line;
            }
            else
                line = ft_strjoin(line, buff, flag);
        }
    }
    if (flag == -1)
        free(line);
    else if(*line)
        return line;
    return NULL;
}