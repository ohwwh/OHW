#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
     char    *ret;
    int     fd[1];
    //fd[0] = open("/Users/ohw/42git/ohw/gnl/file", O_RDONLY);
	fd[0] = 0;
    ret = get_next_line(fd[0]);
    printf("%s", ret);
    free(ret);
    //fd[1] = open("/Users/ohw/42git/ohw/gnl/testfile", O_RDONLY);
    //char c = 0; read(fd, &c, 1); printf("%c", c);
    //ret = get_next_line(fd[1]);
    //printf("%s", ret);
    //free(ret);
    /*ret = get_next_line(fd[0]);
    printf("%s", ret);
    free(ret);
    //ret = get_next_line(fd[1]);
    //printf("%s", ret);
    //free(ret);
    ret = get_next_line(fd[0]);
    printf("%s", ret);
    free(ret);*/
    /*ret = get_next_line(4);
    printf("%s", ret);
    free(ret);
    ret = get_next_line(fd[0]);
    printf("%s", ret);
    free(ret);
    ret = get_next_line(fd[1]);
    printf("%s", ret);
    free(ret);
    ret = get_next_line(fd[0]);
    printf("%s", ret);
    free(ret);*/
}
