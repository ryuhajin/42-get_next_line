/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:03:23 by dayou             #+#    #+#             */
/*   Updated: 2023/05/11 18:24:56 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1, size_t size)
{
	char	*line;
	size_t	i;

    i = -1;
	if (s1[0] == '\0')
		return 0;
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (line == NULL)
		return (NULL);
	while (s1[++i])
		line[i] = s1[i];
	line[size] = '\0';
	return (line);
}

int find_n(char *buff)
{
    size_t idx = -1;
    while (buff[++idx])
    {
        if(buff[idx] == '\n')
            return idx;
    }
    return idx; //'\n' 발견하면 size(idx), 못 발견하면 -1
}

char *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE < 0)
        return;
    char buff[BUFFER_SIZE];
    static char temp[BUFFER_SIZE];
    char * no_newlines;
    char * line;
}