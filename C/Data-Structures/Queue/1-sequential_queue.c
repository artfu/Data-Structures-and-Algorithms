/**
 * @file        1-sequential_queue.c
 * @author      artfu
 * @date        2020.8.5
 *
 * @brief       circular queue
 *
 * @details
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct queue {
        int *base;
        int front, rear;
};

void init(struct queue *q)
{
        q = (struct queue*) malloc(sizeof(struct q));
        if (q) {
                q->base = (int*) malloc(MAXSIZE * sizeof(int));
                q->front = q->rear = 0;
        } else {
                printf("Error.\n");
        }
}

void enqueue(struct queue *q, int data)
{
        if((q->rear + 1) % MAXSIZE == q->front)
                printf("The queue is FULL.\n");

        *(q->base + q->rear) = data;
        q->rear = (q->rear + 1) % MAXSIZE; 
}

void dequeue(struct queue *q)
{
        if (q->rear == q->front)
                printf("The queue is EMPTY.\n");

        q->front = (q->front + 1) % MAXSIZE;
}

int length(struct queue *q)
{
        return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

int main(int argc, char** argv)
{
        return 0;
}
