/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:04:25 by dayou             #+#    #+#             */
/*   Updated: 2023/05/15 01:30:39 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t find_newline(char *s);
char * make_line(char * s, size_t size);
void push_str(char * s, size_t size);
char * line_join(char * no_newline, char * s, size_t size);
void copy_str(char * buff, char * remainder, size_t size);

char *get_next_line(int fd);

#endif