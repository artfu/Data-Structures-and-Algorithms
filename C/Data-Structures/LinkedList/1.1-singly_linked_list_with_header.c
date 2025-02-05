/**
 * @file        1.1-singly_linked_list_with_header.c 
 * @author      artfu 
 * @date        2021.8.3 
 * 
 * @brief       
 *             
 * @details     
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct header {
        struct node *head;
};

struct header* init1()
{
        struct header *list = (struct header*) malloc(sizeof(struct header));
        list->head = NULL;
        return list;
}

struct node* init2(struct node* head)
{
        struct node *p = (struct node*) malloc(sizeof(struct node));
        if (!p) {
                printf("malloc error.\n");
        } else {
                p->next = NULL;
                head = p;
        }
        return head;
}

void add_node1(struct node **head, int data)
{
        struct node *p = (struct node*) malloc(sizeof(struct node));
        if (!p) {
                printf("Unable to allocate memory.\n");
        } else {
                p->data = data;
                p->next = *head;
                *head = p;
        }
}

void add_node2(struct node *head, int data)
{
        struct node *p = (struct node*) malloc(sizeof(struct node));
        if (p) {
                p->data = data;
                p->next = head->next;
                head->next = p;
        } else {
                printf("ERROR.\n");
        }
}

int main(int argc, char** argv)
{
        struct header *list = init();

        add_node(&(list->head), 100);

        struct node* p = list->head;
        while (p) {
            printf("%d ", p->data);
            p = p->next;
        }

        return 0;
}
