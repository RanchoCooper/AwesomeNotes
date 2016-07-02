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

// VM main memory
uint32_t *old_text,     // for dump text segment
         *stack,        // stack
         *text;         // text segment
char     *data;         // data segment

// VM register
uint32_t *pc,           // program counter
         *bp,           // stack pointer
         *sp,           // base pointer
          ax,           // au.. register
          cycle;        // 

// VM instrction set
enum {  LEA, IMM, JMP, CALL, JZ , JNZ, ENT, ADJ, LEV, LI, LC , SI, SC, PUSH, 
       OR, XOR, AND, EQ, NE, LT, GT, LE, GE, SHL, SHR, ADD, SUB, MUL, DIV, 
       MOD, OPEN, READ, CLOS, PRTF, MALC, MSET, MCMP, EXIT
};
/* 
/* 
/* 
/********** instrctions detail *********/

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

// entry VM, interprete source code
int eval() {
    int op, *tmp;
    while (1) {
        // MOV
        if (op == IMM)          { ax = *pc++; }
        else if (op == LC)      { ax = *(char*) ax; }
        else if (op == LI)      { ax = *(int*) ax; }
        else if (op == SC)      { ax = *(char*) *sp++ = ax; }
        else if (op == SI)      { *(int*) *sp++ = ax; }
        // *sp++ equals to POP() 

        // PUSH
        else if (op == PUSH)    { *--sp = ax; }

        // JMP
        else if (op == JMP)     { pc = (int*) *pc; } 

        // JZ/JNZ
        else if (op == JZ)      { pc = ax ? pc + 1 : (int*) *pc; }                   // jump if ax is zero
        else if (op == JNZ)     { pc = ax ? (int*)*pc : pc + 1; } 
        
        // subfuction call
        else if (op == CALL)    { *--sp = (int)(pc+1); pc = (int*) *pc; }
        // else if (op == RET)  { pc = (int*) *sp++; }
        else if (op == ENT)     { *--sp = (int) bp; bp = sp; sp = sp - *pc++; }
        // make new stack frame

        // ADJ
        else if (op == ADJ)     { sp = sp + *pc++; }

        // LEV
        else if (op == LEV)     { sp = bp; bp = (int*) *sp++; pc = (int*) *sp++; }
        // restore call frame

        // LEA
        else if (op == LEA)     { ax = (int)(bp + *pc++); }
                                      
        // operator instruction    
        else if (op == OR)      ax = *sp++  | ax;
        else if (op == XOR)     ax = *sp++  ^ ax;
        else if (op == AND)     ax = *sp++  & ax;
        else if (op == EQ)      ax = *sp++ == ax;
        else if (op == NE)      ax = *sp++ != ax;
        else if (op == LI)      ax = *sp++  < ax;
        else if (op == LE)      ax = *sp++ <= ax;
        else if (op == GT)      ax = *sp++  > ax;
        else if (op == GE)      ax = *sp++ >= ax;
        else if (op == SHL)     ax = *sp++ << ax;
        else if (op == SHR)     ax = *sp++ >> ax;
        else if (op == ADD)     ax = *sp++  + ax;
        else if (op == SUB)     ax = *sp++ - ax;
        else if (op == MUL)     ax = *sp++ * ax;
        else if (op == DIV)     ax = *sp++ / ax;
        else if (op == MOD)     ax = *sp++ % ax;

        // built-in function
        else if (op == EXIT)    { printf("exit(%d)", *sp); return *sp; }
        else if (op == OPEN)    { ax = open((char*) sp[1], sp[0]); }
        else if (op == CLOS)    { ax = close(*sp);}
        else if (op == READ)    { ax = read(sp[2], (char*) sp[1], *sp); }
        else if (op == PRTF)    { tmp = sp + pc[1]; ax = printf((char*) tmp[-1], tmp[-2], tmp[-3], tmp[-4], tmp[-5], tmp[-6]); }
        else if (op == MALC)    { ax = (int) malloc(*sp);}
        else if (op == MSET)    { ax = (int) memset((char*) sp[2], sp[1], *sp); }
        else if (op == MCMP)    { ax = memcmp((char*) sp[2], (char*) sp[1], *sp); }

        // none
        else {
            printf("unknow instruction: %d\n", op);
            return -1;
        }
    }
    return 0;
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

    
    // allocate memory for virtual machine
    if (!(text = old_text = malloc(poolsize))) {
        printf("could not malloc(%d) for text area\n", poolsize);
        return -1;
    }

    if (!(data = malloc(poolsize))) {
        printf("could not malloc(%d) for data area\n", poolsize);
        return -1;
    }

    if (!(stack = malloc(poolsize))) {
        printf("could not malloc(%d) for stack area\n", poolsize);
        return -1;
    }

    memset(text, 0, poolsize);
    memset(data, 0, poolsize);
    memset(stack, 0, poolsize);

    // init register
    bp = sp = (int *)((int) stack + poolsize);

    program();
    return eval();
}
