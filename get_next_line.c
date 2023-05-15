/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:03:23 by dayou             #+#    #+#             */
/*   Updated: 2023/05/15 22:05:27 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

ssize_t find_newline(char *s)
{
    ssize_t size;

    size = 0;
    while (size < BUFFER_SIZE && s[size])
    {
        if(s[size] == '\n')
            return size;
        size++;
    }
    return -1;
}

char * make_line(char * s, ssize_t size)
{
    ssize_t idx;
    char * line;

    idx = 0;
    if(size == BUFFER_SIZE)
        line = (char *)malloc(sizeof(char) * (size + 1));
    else if (size > 0)
        line = (char *)malloc(sizeof(char) * (size + 2));
    else
    {
        while (s[idx])
            idx++;
        line = (char *)malloc(sizeof(char) * (idx + 1));
    }
    if(line == 0)
        return 0;
    idx = 0;
    while (idx <= size && s[idx])
    {
        line[idx] = s[idx];
        idx++;
    }
    line[idx] = '\0';
    return line;
}

void push_str(char * s, ssize_t size)
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

char * line_join(char * no_newline, char * s, ssize_t size)
{
    ssize_t len;
    ssize_t idx;
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

void copy_str(char * buff, char * remainder, ssize_t size)
{
    ssize_t i;

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
    char * line;
    char * no_newline;
    ssize_t size;

    size = find_newline(remainder);
    if(size != -1)
    {
        line = make_line(remainder, size);
        push_str(remainder, size);
        return line;        
    }
    else
    {
        no_newline = make_line(remainder, size);
        remainder[0] = '\0';
        while (0 < (size = read(fd, buff, BUFFER_SIZE)))
        {   
            size = find_newline(buff);
            if(size != -1)
            {
                line = line_join(no_newline, buff, size);
                copy_str(buff, remainder, size + 1);
                return line;
            }
            else
                no_newline = line_join(no_newline, buff, -1);
        }
        line = line_join(no_newline, buff, -1);
        return line;
    }
}
