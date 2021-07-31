/**
 * @file        1-sequential_stack.c 
 * @author      artfu 
 * @date        2020.7.27 
 * 
 * @brief       
 * 
 * @details     
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct stack {
        int *base;
        int *top;
};

void init(struct stack **pstack)
{
        *pstack->base = (int*) malloc(MAXSIZE * sizeof(int));
        *pstack->top = *pstack->base;
}

int main(int argc, char *argv[])
{
        struct stack s;
        init(&(&s));
        return 0;
}
