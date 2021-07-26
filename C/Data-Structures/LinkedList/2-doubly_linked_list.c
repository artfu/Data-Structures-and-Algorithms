/**
 * @file        2-linked_list.c 
 * @author      artfu 
 * @date        2020.7.21 
 * 
 * @brief       Implement double linked lists(NO header) and related operations, 
 *              including insert, search, delete and other operations. 
 * 
 * @details     
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
        struct node *prev;
};

/****************************     INSERT     **********************************/

/**
 * @brief       insert() -- insert a node to the head or tail of a list      
 * 
 * @details     like singly linked list, there are 3 conditons:
 *              1. add next node to head;
 *              2. add next node to tail;
 *              3. add the next node to a specific position.
 *              This function can do 1 and 2.
 * 
 * @note        What's the difference between singly linked list and doubly linked list? 
 *              
 *              This time there is no Global pointer, what should we do deal this situation?
 *              As I mentioned, there are another way:
 *                      - Given a reference (pointer to pointer) to the head of a list
 *                      - Use pointer to node as return value
 *              Let's try Reference way.
 * 
 * @param       head_ref        -- pointer to pointer                 
 * @param       data            -- int value
 * 
 * @return      void
 * @retval      void
*/
void head_insert(struct node **head_ref, int data) 
{ 
        struct node *ptr = (struct node*) malloc(sizeof(struct node));
        ptr->data = data;

        ptr->next = *head_ref;
        ptr->prev = NULL;

        if (*head_ref != NULL)
                (*head_ref)->prev = ptr;

        *head_ref = ptr;
}

void tail_insert(struct node **head_ref, int data) 
{ 
        struct node *ptr = (struct node*) malloc(sizeof(struct node));
        ptr->data = data;

        struct node *tail = *head_ref;
        if (tail != NULL) {
                while (tail->next != NULL)
                        tail = tail->next;
                ptr->prev = tail;
                ptr->next = NULL;
                tail->next = ptr;
        }
        else {
                ptr->prev = NULL;
                ptr->next = NULL;
                *head_ref = ptr;
        }
} 

int main(int argc, char* argv[])
{
        struct node *head = NULL;
        tail_insert(&head, 4);
        tail_insert(&head, 5);
        tail_insert(&head, 6);
        head_insert(&head, 1);
        head_insert(&head, 2);
        head_insert(&head, 3);

        // 3 2 1 4 5 6
        struct node *p = head;
        while (p) {
                printf("%d ", p->data);
                p = p->next;
        }

        return 0;
}
