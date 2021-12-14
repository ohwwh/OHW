#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    char    *ret;
    int     fd;

    fd = open("/Users/ohw/42git/gnl/file", O_RDONLY);
    ret = get_next_line(fd);
    for(int i = 0; i < 15; i ++)
        printf("%c", ret[i]);
    free(ret);
    ret = get_next_line(fd);
    for(int i = 0; i < 17; i ++)
        printf("%c", ret[i]);
    free(ret);
    ret = get_next_line(fd);
    for(int i = 0; i < 12; i ++)
        printf("%c", ret[i]);
    free(ret);
    /*ret = get_next_line(fd);
    printf("%s", ret);
    //free(ret);
    ret = get_next_line(fd);
    printf("%s", ret);
    //free(ret);*/
    //파일의 문자열에 개행문자가 없이 끝나는 경우
}
