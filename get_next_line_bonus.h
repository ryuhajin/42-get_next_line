/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:04:25 by dayou             #+#    #+#             */
/*   Updated: 2023/06/27 21:32:28 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef OPEN_MAX
#	define	OPEN_MAX 10240
# endif

char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2, ssize_t size);
size_t	ft_strlcpy(char *dest, char *src);
ssize_t	remainder_find_n(int fd, char **line, char remainder[][BUFFER_SIZE + 1]);
ssize_t	read_file(int fd, char **line, char remainder[][BUFFER_SIZE + 1]);
char	*get_next_line(int fd);

#endif