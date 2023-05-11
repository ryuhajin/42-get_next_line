/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:03:23 by dayou             #+#    #+#             */
/*   Updated: 2023/05/11 22:25:56 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_n(char *buff)
{
    size_t idx = 0;
    while (buff[idx++])
    {
        if(buff[idx] == '\n')
            return idx;
    }
    return idx; //'\n' 발견하면 size(idx), 못 발견하면 0
}

char *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE < 0)
        return;
    char buff[BUFFER_SIZE];
    static char temp[BUFFER_SIZE +1];
    char * no_newlines;
    char * line;
	
	if (*temp) //  템프가 채워져 있으면
	{
		if(!find_n(temp)) //!0 템프에 개행을 발견하지 못했다면
		{	
			if(!no_newlines) // no_newlines에 문자열이 없다면 temp 넣어주기
				no_newlines = ft_strdup(temp);
			else // no_newlines에 문자열이 있다면 템프와 이어주기
				ft_strjoin(temp, no_newlines);
		}
		else // 템프에 개행이 있다면
		{
			ft_strlcpy
		}	
	}
	else
	{	
		if(-1 < read(fd, buff, BUFFER_SIZE))
			
		if(find_n(buff)) // !0 버퍼에 개행을 발견하지 못했다면
			ft_strlcpy(temp, buff);
	}
	
	return line;
}
