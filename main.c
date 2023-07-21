/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:33:47 by dayou             #+#    #+#             */
/*   Updated: 2023/07/19 21:38:36 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	check_leak(void)
{
	system("leaks a.out");
}

int main(void)
{
    char *path1 = "/Users/dayou/Desktop/42seoul/get_next_line/moby_dick.txt";
    char *path2 = "/Users/dayou/Desktop/42seoul/get_next_line/test.txt";
	char *path3 = "/Users/dayou/Desktop/42seoul/get_next_line/test2.txt";
	char *path4 = "/Users/dayou/Desktop/42seoul/get_next_line/no_new_line.txt";
	
    int fd1 = open(path1, O_RDONLY);
	int fd2 = open(path2, O_RDONLY);
	int fd3 = open(path3, O_RDONLY);
	int fd4 = open(path4, O_RDONLY);
	char *ddddch = malloc(1000);

	int fd_bonus_check[] = {fd1, fd2, fd4, fd3, fd2, fd1, fd1, fd1, fd3, fd3};

	char * line;
	int i = 0;
	
	while(i < 10)
	{
		line = get_next_line(fd_bonus_check[i]);
		printf("%d: %s", i, line);
		free(line);
		i++;
	}
		
	// while ((line = get_next_line(fd1)) != NULL)
	// {
	// 	printf("fd1 : %s", line);
	// 	free(line);
	// }
	
	// while ((line = get_next_line(fd2)) != NULL)
	// {
	// 	printf("fd2 : %s", line);
	// 	free(line);
	// }

	// while ((line = get_next_line(fd3)) != NULL)
	// {
	// 	printf("fd3 : %s", line);
	// 	free(line);
	// }

	// while ((line = get_next_line(fd4)) != NULL)
	// {
	// 	printf("fd4 : %s", line);
	// 	free(line);
	// }

    close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	atexit(check_leak);
	
    return 0;
} 