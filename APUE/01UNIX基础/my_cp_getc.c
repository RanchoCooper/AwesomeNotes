/**
 *  @author  : Rancho Cooper
 *  @date    : 2016-08-13 08:23
 *  @email   : rancho941110@gmail.com
 */
 #include "apue.h"

int main(int argc, char const *argv[])
{
    int c;

    while ((c = getc(stdin)) != EOF)
        printf("get: %s\n", &c);
        if (putc(c, stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");

    return 0;
}
