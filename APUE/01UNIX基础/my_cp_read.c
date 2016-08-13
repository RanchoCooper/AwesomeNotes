/**
 *  @author  : Rancho Cooper
 *  @date    : 2016-08-13 08:14
 *  @email   : rancho941110@gmail.com
 *  ./a.out < infile > outfile   复制文件
 *  终端中<Ctrl-D>产生EOF
 */
 #include "apue.h"
 #define BUFFSIZE 4096

int main(int argc, char const *argv[])
{
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)     // 返回成功读取的字节数
        if (write(STDOUT_FILENO, buf, n) != n)              // 返回写入的字节数
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    return 0;
}
