/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:24:13 by dayou             #+#    #+#             */
/*   Updated: 2023/05/20 21:59:21 by dayou            ###   ########.fr       */
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
	ssize_t	len;
    ssize_t idx;
	char	*line;

	len = 0;
	idx = 0;
	while (s1[len])
        len++;
    while (s2[idx] && idx < size + 1)
    {   
		idx++; 
		len++;
	}
	// printf("s2 len: %zd\n", len);
	line = (char *)malloc(sizeof(char) * (len + 1));
	// printf("result: %zd\n", result);
	if (line == NULL)
		return (NULL);
    line[len] = '\0';
    len = ft_strlcpy(line, s1, ft_strchr(s1, '\0'));
    ft_strlcpy(line + len, s2, size);
    free(s1);
	return (line);
}

size_t	ft_strlcpy(char *dest, char *src, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (src[i] && i < size)
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
	if(character == '\0')
		return i;
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
        ft_strlcpy(remainder, remainder + size + 1, ft_strchr(remainder, '\0'));
        return line;
    }
    else
    {
        while (-1 < (flag = read(fd, buff, BUFFER_SIZE)))
        {
            if(flag == 0)
                break;
            buff[flag] = '\0';
            if (-1 < (size = ft_strchr(buff, '\n')))
            {
                line = ft_strjoin(line, buff, size); // '\n' 까지 돔
                ft_strlcpy(remainder, buff + size + 1, ft_strchr(buff, '\0'));
                return line;
            }
            else
                line = ft_strjoin(line, buff, flag); // flag 까지 돔 (읽은 바이트 수)
        }
		if (flag == 0 && *line)
		{
			line = ft_strjoin(line, remainder, ft_strchr(remainder, '\0'));
        	return line;
		}
    }
    if (flag == -1)
		free(line);
    return NULL;
}