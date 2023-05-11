#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
    char *path = "/Users/u_u/Desktop/42seoul/get_next_line/moby_dick.txt";

    int fd = open(path, O_RDONLY);
    char *tmp = get_next_line(fd);
    while (tmp)
    {
        printf("%s", tmp);
        free(tmp);
        tmp = get_next_line(fd);
    }
    return 0;
}