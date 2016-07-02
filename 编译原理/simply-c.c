/*
 * @author: Rancho (rancho941110@gmail.com)
 * @date  : 2016-07-02 01:38:24
 * @brief : a simple c-interpreter
 *
 * VM: only concerned .text, .data, .stack
 */
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

int token;              // current token char
char *src, *old_src;    // pointer to source code string
int poolsize;           // default VM size of text/data/stack
int line;               // line number

// scanner, ommit blank char
void next() {
    token = *src++;
    return;
}

// parse an expr
void expression(int level) {
    // do nothing
}

// syntax analysis
void program() {
    next();
    while (token > 0) {
        printf("token is: %c\n", token);
        next();
    }
}

int main(int argc, char**argv) {
    int i, fd;
    
    argc--;
    argv++;

    poolsize = 256 * 1024;
    line = 1;

    if ((fd = open(*argv, 0)) < 0) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    if (!(src = old_src = malloc(poolsize))) {
        printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
    }

    // read the source file
    if ((i = read(fd, src, poolsize - 1)) <= 0) {
        printf("read() returned %d\n", i);
        return -1;
    }
    src[i] = 0; // add EOF character
    close(fd);

    program();
    return eval();
}
