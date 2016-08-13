/**
 *  @author  : Rancho Cooper
 *  @date    : 2016-08-13 09:06
 *  @email   : rancho941110@gmail.com
 *  只能执行基本的无参命令
 *
 *  fort调用一次但返回两次, 向子进程返回0, 向父进程返回子进程pid
 */
#include "apue.h"
#include <sys/wait.h>

#define MAXLEN 5

int main(int argc, char const *argv[])
{
    pid_t pid;
    int status;
    char buf[MAXLEN];       // apue.h

    printf("%% ");          // print prompt '%'

    while (fgets(buf, MAXLEN, stdin) != NULL) { // readline from stdin, ended with '\n'
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;           // replace '\n' with NULL

        if ((pid = fork()) < 0) {
            err_sys("fork failed");
        } else if (pid == 0) {                  // child
            execlp(buf, buf, (char*)0);
            err_ret("couldn't execute: %s", buf);
        }

        // parent
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");

        printf("%% ");
    }

    return 0;
}
