/**
 * @file        2-linked_list_stack.c
 * @author      artfu
 * @date        2020.8.2
 *
 * @brief       
 *
 * @details
 */

#include <stdio.h>
#include <stdlib.h>

struct stack {
        int data;
        struct stack *next;
};

void init(struct stack **s)
{
        *s = NULL;
}

void push(struct stack **s, int data)
{
        struct stack *p = (struct stack*) malloc(sizeof(struct stack));
        p->data = data;
        p->next = *s;
        *s = p;
}

void pop(struct stack *s)
{
        struct stack *p = s;
        s = s->next;
        free(p);
}

int main(int argc, char** argv)
{
        struct stack *s;
        init(&s);

        push(&s, 100);
        push(&s, 200);
        push(&s, 300);

        struct stack *p = s;
        while (p) {
                printf("%d ", p->data);
                p = p->next;
        }
        return 0;
}
