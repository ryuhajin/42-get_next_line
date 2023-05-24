/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:18:13 by dayou             #+#    #+#             */
/*   Updated: 2023/05/25 00:39:27 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	remainder_find_n(char **line, char *remainder)
{
	ssize_t	size;
	char	*new_line;

	size = 0;
	while (remainder[size])
	{
		if (remainder[size] == '\n')
		{
			*line = ft_strjoin(*line, remainder, size + 1);
			ft_strlcpy(remainder, remainder + (size + 1));
			return (1);
		}
		size++;
	}
	if (size)
	{
		*line = ft_strjoin(*line, remainder, size);
		remainder[0] = '\0';
	}
	return (0);
}

ssize_t	read_file(int fd, char **line, char *remainder)
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
				ft_strlcpy(remainder, buff + (size + 1));
				return (flag);
			}
			size++;
		}
		*line = ft_strjoin(*line, buff, size);
	}
	return (flag);
}

char	*get_next_line(int fd)
{
	static char remainder[BUFFER_SIZE + 1] = {
		0,
	};
	char *line;
	ssize_t flag;

	line = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	flag = remainder_find_n(&line, remainder);
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
