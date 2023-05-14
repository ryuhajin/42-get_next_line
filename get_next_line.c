/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:03:23 by dayou             #+#    #+#             */
/*   Updated: 2023/05/15 02:30:02 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t find_newline(char *s)
{
    size_t size;

    size = 0;
    while (size < BUFFER_SIZE)
    {
        if(s[size] == '\n')
            return size;
        size++;
    }
    return 0;
}

char * make_line(char * s, size_t size)
{
    size_t idx;
    char * line;
    
    idx = -1;
    if(size == BUFFER_SIZE)
        line = (char *)malloc(sizeof(char) * (size + 1));
    else
        line = (char *)malloc(sizeof(char) * (size + 2));
    if(line == 0)
        return 0;
    while (++idx <= size && s[idx])
        line[idx] = s[idx];
    line[idx] = '\0';
    return line;
}

void push_str(char * s, size_t size)
{
    size_t cnt;

    cnt = 0;
    while (s[cnt])
    {
        s[cnt] = s[size + cnt + 1];
        cnt++;
    }
    s[cnt] = '\0';
}

char * line_join(char * no_newline, char * s, size_t size)
{
    size_t len;
    size_t idx;
    char * line_join;

    len = 0;
    idx = 0;
    while (no_newline[len])
        len++;
    line_join = (char *)malloc(sizeof(char) * (len + size + 2));
    if(line_join == 0)
        return 0;
    while (no_newline[idx])
    {
       line_join[idx] = no_newline[idx];
       idx++; 
    }
    len = 0;
    while (len <= size)
    {
        line_join[idx++] = s[len++];
    }
    line_join[idx] = '\0';
    free(no_newline);
    return line_join;
}

void copy_str(char * buff, char * remainder, size_t size)
{
    size_t i;

    i = 0;
    while (size < BUFFER_SIZE && buff[size])
    {
        remainder[i++] = buff[size++];
    }
    remainder[i] = '\0';
}

char * get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE < 0)
        return 0;
    
    char buff[BUFFER_SIZE];
    static char remainder[BUFFER_SIZE + 1] = {0, };
    char * no_newline;
    char * line;
    size_t size = 0;

    size = find_newline(remainder);
    if(size)
    {
        line = make_line(remainder, size);
        line = line_join(no_newline, line, size);
        push_str(remainder, size);
    }
    else
    {
        if(-1 == read(fd, buff, BUFFER_SIZE))
        {
            free(no_newline);
            free(line);
            return 0;
        }
        else
        {
            size = find_newline(buff);
            if(size)
            {    
                line = make_line(buff, size);
                copy_str(buff, remainder, size + 1);
            }
            else
                no_newline = make_line(buff, size);
        }
    }
    return line;
}
