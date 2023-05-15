/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:04:25 by dayou             #+#    #+#             */
/*   Updated: 2023/05/15 17:27:39 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

ssize_t find_newline(char *s);
char * make_line(char * s, ssize_t size);
void push_str(char * s, ssize_t size);
char * line_join(char * no_newline, char * s, ssize_t size);
void copy_str(char * buff, char * remainder, ssize_t size);

char *get_next_line(int fd);

#endif