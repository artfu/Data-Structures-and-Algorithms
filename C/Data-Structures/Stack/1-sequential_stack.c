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
        *pstack = (struct stack*) malloc(sizeof(struct stack));
        (*pstack)->base = (int*) malloc(MAXSIZE * sizeof(int));
        printf("%p\n", (*pstack)->base);
        (*pstack)->top = (*pstack)->base;
        printf("%p\n", (*pstack)->base);
}

int push(struct stack *ps, int data)
{
        if (ps->top - ps->base == MAXSIZE)
                return -1;
        *(ps->top) = data;
        ps->top++;
        // *ps->top++ = data;
        return 0;
}

int pop(struct stack *ps, int *add)
{
        if (ps->top == ps->base)
                return -1;
        ps->top--;
        *add = *(ps->top);
        // *add = *--ps->top;
}

int main(int argc, char *argv[])
{
        struct stack *s = NULL;

        init(&s);
        push(s, 100);
        push(s, 200);
        push(s, 300);
        push(s, 400);
        push(s, 500);

        int *p = s->base;
        while (p != s->top) {
                printf("%d ", *p++);
        }
        printf("\n");

        int a, b, c;
        pop(s, &a);
        pop(s, &b);
        pop(s, &c);

        p = s->base;
        while (p != s->top) {
                printf("%d ", *p++);
        }
        printf("\n");

        return 0;
}
