/**
 * @file        2-linked_list_queue.c
 * @author      artfu
 * @date        2020.8.5
 *
 * @brief       circular queue
 *
 * @details
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct queue {
        struct node *front;
        struct node *rear;
};

void init(struct queue *q)
{
        q->front = (struct queue*) malloc(sizeof(struct queue));
        q->rear = q->front;
        q->front->next = NULL;
}

void enqueue(struct queue *q, int data)
{
        struct queue *p = (struct node*) malloc(sizeof(struct node));
        p->data = data;
        p->next = NULL;
        q->rear->next = p;
        q->rear = p;
}

void dequeue(struct queue *q)
{
        // Assume header
        struct node *p = q->front->next;
        q->front->next = p->next;
        if (q->rear == p)
                q->rear = q->front;
        free(p);
}

int main(int argc, char** argv)
{
        return 0;
}
