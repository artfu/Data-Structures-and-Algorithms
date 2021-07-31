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
        (*pstack)->base = (int*) malloc(MAXSIZE * sizeof(int));
        (*pstack)->top = (*pstack)->base;
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
        struct stack *s;
        printf("%p      %zu\n", s, sizeof(*s));

        // struct stack *ps = s;
        // printf("%p      %zu\n", ps, sizeof(*ps));

        init(&s);
        printf("%p\n", s);
        printf("base = %p       top = %p\n", s->base, s->top);
        printf("%d \n", *(s->top));
        // push(s, 100);
        printf("%d\n",push(s, 100));
        printf("base = %p       top = %p\n", s->base, s->top);
        printf("%d \n", *(s->top-1));
        push(s, 200);
        printf("base = %p       top = %p\n", s->base, s->top);
        printf("%d \n", *(s->top-1));
        push(s, 300);
        printf("base = %p       top = %p\n", s->base, s->top);
        printf("%d \n", *(s->top-1));
        push(s, 400);
        printf("base = %p       top = %p\n", s->base, s->top);
        printf("%d \n", *(s->top-1));
        push(s, 500);
        printf("base = %p       top = %p\n", s->base, s->top);
        printf("%d \n", *(s->top-1));


        return 0;
}
