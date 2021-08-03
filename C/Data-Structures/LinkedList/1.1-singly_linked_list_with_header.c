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

struct header* init()
{
        struct header *list = (struct header*) malloc(sizeof(struct header));
        list->head = (struct node*) malloc(sizeof(struct node));
        list->head->next = NULL;
        return list;
}

int add_node(struct node *head, int data)
{
        struct node *p = (struct node*) malloc(sizeof(struct node));
        if (!p) {
                printf("Unable to allocate memory.\n");
                exit(1);
        } else {
                p->data = data;
                p->next = head;
                head = p;
                return 0;
        }
}

int main(int argc, char** argv)
{
        struct header *list = init();

        add_node(list->head, 100);

        return 0;
}
