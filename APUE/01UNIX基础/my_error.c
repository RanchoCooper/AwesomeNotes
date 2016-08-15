/**
 *  @author  : Rancho Cooper
 *  @date    : 2016-08-13 15:25
 *  @email   : rancho941110@gmail.com
 *
 *  <errno.h>中定义了很多具有特定意义的出错处理的常量, 它们都以E开头
 *  Linux环境下 $ man errno 可以查看更多细节
 *
 *  注意两条规则:
 *  1. 如果没有出错, errno的值不会被例程清除
 *  2. 任何函数不得将其置0
 */
#include "apue.h"
#include <errno.h>

int main(int argc, char const *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    /**
     *  #include <string.h>
     *  char *strerror(int errnum);
     *  将一个错误号映射为对应的错误信息, 并返回此字符串的指针
     */

    errno = ENOENT;
    perror(argv[0]);
    /**
     *  #include <stdio.h>
     *  void perror(const char* msg);
     *  根据当前errno输出错误信息
     *  输出格式为 "%s: %s\n", *msg, strerror(errno)
     *  UNIX惯例是把当前程序名作为msg输出(这样能在一条多管道的命令中区分出错的程序)
     */

    return 0;
}
