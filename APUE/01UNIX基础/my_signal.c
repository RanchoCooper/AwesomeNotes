/**
 *  @author  : Rancho Cooper
 *  @date    : 2016-08-13 15:54
 *  @email   : rancho941110@gmail.com
 *
 *  对之前的my_shell.c作信号捕获的示例
 */
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);   // 自定义信号处理函数

int main(int argc, char const *argv[])
{
    pid_t pid;
    int status;
    char buf[MAXLINE];

    /**
     *  signal()需要指定所产生的信号及其信号处理函数
     */
    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");

    while (fgets(buf, MAXLINE, stdin) != NULL) { // readline from stdin, ended with '\n'
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

void sig_int(int signo) {
    printf("interrupt\nrestart\n%%");
}
