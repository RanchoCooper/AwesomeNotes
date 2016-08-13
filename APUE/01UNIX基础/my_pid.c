/**
 *  @author  : Rancho Cooper
 *  @date    : 2016-08-13 09:03
 *  @email   : rancho941110@gmail.com
 *  getpid()返回pid_t类型, 标准只保证它能存放在一个长整形中
 *  所以将其强转为long, 以提高可移植性
 */
 #include "apue.h"

int main(int argc, char const *argv[])
{
    printf("current PID: %ld\n", (long)getpid());

    return 0;
}
