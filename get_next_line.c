/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:03:23 by dayou             #+#    #+#             */
/*   Updated: 2023/05/12 17:18:13 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t find_n(char * s)
{
    size_t size;

    size = 0;
    while (s[size++])
    {
        if(s[size] == '\n')
            return size; // '\n'이 3번째 인덱스에 있을 때, 3 반환 = 배열 만들 때 size(인덱스) + 1 + '\0' 까지 총 + 2 필요.
    }
    return 0;
}

char * make_line(char * s, size_t size)
{
    char * line;
    size_t idx;

    idx = -1;
    line = (char *)malloc(sizeof(char) * (size + 1));
    if(line == 0)
        return 0;
    while (++idx <= size)
        line[idx] = s[idx];
    line[idx + 1] = '\0';
    return line;    
}

void push_str(char * s, size_t size)
{
    size_t idx;

    idx = 0;
    while (size < BUFFER_SIZE && s[size])
    {
        s[idx] = s[size];
        idx++;
        size++;
    }
    s[idx] = '\0';
}

char * join_str(char * s1, char * s2, size_t s2_size) // s1 뒤에 s2 붙이기
{
    size_t size;
    size_t len;
    char * join_s;

    size = 0;
    while(s1[size])
        size++;
    len = size + s2_size;
    join_s = (char *)malloc(sizeof(char) * (len));
    if(join_s == 0)
        return 0;
    join_s[len] = '\0';
    size = -1;
    while (s1[++size])
        join_s[size] = s1[size];
    size = -1;
    while (s2[++size])
        join_s[size] = s2[size];
    free(s1);
    return join_s;
}

ssize_t read_flag(int fd, char * buff)
{
    ssize_t flag;

    flag = read(fd, buff, BUFFER_SIZE);
    while (flag < 0)
        flag = read(fd, buff, BUFFER_SIZE);
    if (flag == 0)
        return 0;
    else
        return flag;
}

char * get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE < 0)
        return;
    
    char buff[BUFFER_SIZE];
    static char temp[BUFFER_SIZE +1] = {0, };
    char * no_newlines;
    char * line;
    size_t size;

    size = 0; // size = idx
    //temp에 문자가 있는가?
    if(*temp) // -> yes
    {   size = find_n(temp); //temp에 개행이 있는가?
        if(size) // -> yes 개행 있음
        {
            line = make_line(temp, size + 1); // 0 반환했을 때 처리 생각하기
            push_str(temp, size); // line을 뺀 만큼 temp 문자열 밀기
        }
        else // -> no 개행 없음
        { // no_newlines에 저장된 문자가 있는가?
            if(no_newlines) // -> yes 저장된 문자 있음
            {
                no_newlines = join_s(no_newlines, temp, size);
                *temp = '\0'; //temp 초기화
            }
            else // -> no 저장된 문자 없음
            {
                no_newlines = make_line(temp, size + 1); // no_new에 문자열 할당
                *temp = '\0'; //temp 초기화
            } 
        }
    }
    else // -> no
    {
        if(0 == read_flag(fd, buff))
        {
            
        }  
    }

	return line;
}
