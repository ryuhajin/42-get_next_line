/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:33:47 by dayou             #+#    #+#             */
/*   Updated: 2023/05/25 00:32:13 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    //char *path = "/Users/u_u/Desktop/42seoul/get_next_line/moby_dick.txt";
    char *path = "/Users/u_u/Desktop/42seoul/get_next_line/test.txt";

    int fd = open(path, O_RDONLY);
    char *line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return 0;
}