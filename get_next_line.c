/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:18:13 by dayou             #+#    #+#             */
/*   Updated: 2023/06/27 23:02:22 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	remainder_find_n(int fd, char **line, char remainder[][BUFFER_SIZE + 1])
{
	ssize_t	size;
	
	size = 0;
	if(*line == NULL)
		return 0;
	while (remainder[fd][size])
	{
		if (remainder[fd][size] == '\n')
		{
			*line = ft_strjoin(*line, remainder[fd], size + 1);
			if (*line == NULL)
				return (2);
			ft_strlcpy(remainder[fd], &(remainder[fd][size + 1]));
			return (1);
		}
		size++;
	}
	if (size)
	{
		*line = ft_strjoin(*line, remainder[fd], size);
		if(*line == NULL)
			return (2);
		remainder[fd][0] = '\0';
	}
	return (0);
}

ssize_t	read_file(int fd, char **line, char remainder[][BUFFER_SIZE + 1])
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	flag;
	ssize_t	size;

	while (0 < (flag = read(fd, buff, BUFFER_SIZE)))
	{
		buff[flag] = '\0';
		size = 0;
		while (buff[size])
		{
			if (buff[size] == '\n')
			{
				*line = ft_strjoin(*line, buff, size + 1);
				if (*line == NULL)
					return (-1);
				ft_strlcpy(remainder[fd], buff + (size + 1));
				return (flag);
			}
			size++;
		}
		*line = ft_strjoin(*line, buff, size);
		if (*line == NULL)
			return (-1);
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	static char remainder[OPEN_MAX][BUFFER_SIZE + 1] = {0, };
	char *line;
	ssize_t flag;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	line = ft_strdup("");
	if (line == NULL)
		return NULL;
	flag = remainder_find_n(fd, &line, remainder);
	if (flag == 2)
		return NULL;
	if (flag == 1)
		return (line);
	flag = read_file(fd, &line, remainder);
	if (0 < flag)
		return (line);
	else if (flag == 0)
	{
		if (*line != '\0')
			return (line);
		else
		{
			free(line);
			return (NULL);
		}
	}
	else if (flag == -1)
		free(line);
	return (NULL);
}
