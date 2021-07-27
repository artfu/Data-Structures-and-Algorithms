/**
 * @file        3-circular_linked_list.c 
 * @author      artfu 
 * @date        2020.7.27 
 * 
 * @brief       Implement circular linked lists and related operations, 
 * 
 * @details     What's the biggest difference? if plast is the pointer to last node:
 *              The last node of singly linked list: plast->next = NULL;
 *              The last node of circular linked list: plast->next = head;(the pointer to list head node)
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

/* remove func -- we'll talk about Linus Torvalds good taste linked list */
void bad_remove(struct node **head_ref, struct node *target)
{
        struct node *curr = *head_ref;
        struct node *prev = NULL;
        
        while (curr != target) {
                prev = curr;
                curr = curr->next;
        }
        if (prev)
                prev->next = curr->next;
        else
                *head_ref = curr->next;
}

void elegant_remove(struct node **head_ref, struct node *target)
{
        struct node **ptr = **head_ref;

        while ((*ptr) != target)
                ptr = &(*ptr)->next;
        *ptr = target->next;
}


int main(int argc, char** argv)
{
        return 0;
}
