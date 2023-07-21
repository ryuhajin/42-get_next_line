/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:04:25 by dayou             #+#    #+#             */
/*   Updated: 2023/06/28 19:46:21 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

typedef enum e_read_status
{
	read_failed = -1,
	read_EOF = 0,
}		t_read_status;

typedef enum e_new_line_status
{
	no_new_line = 0,
	make_new_line = 1,
	line_malloc_failed = 2
}		t_make_line_status;

char	*get_next_line(int fd);

char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2, ssize_t size);
size_t	ft_strlcpy(char *dest, char *src);
ssize_t	find_newline(char *buff, ssize_t *size);

ssize_t	remainder_find_n(int fd, char **line,
			char remainder[][BUFFER_SIZE + 1]);
ssize_t	read_file(int fd, char **line, char remainder[][BUFFER_SIZE + 1]);
char	*read_flag_check(ssize_t flag, char *line);

#endif
