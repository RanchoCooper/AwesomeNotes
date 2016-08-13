/**
 *  @author  : Rancho Cooper
 *  @date    : 2016-08-13 07:55
 *  @email   : rancho941110@gmail.com
 *  argv[0] 是shell所执行命令名称, 终端输入的第一个参数
 *  argv[1] 才是真正传给程序的第一个参数
 *  目录条目并不是按照字母排序输出
 *  readdir()的工作方式像生成器
 */
#include "apue.h"               // err_quit() err_sys()
#include <dirent.h>             // opendir() readdir() struct dirent

int main(int argc, char const *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("usage: ls DIR_NAME");

    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
    return 0;
}
