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
 * @brief       insert() -- insert a node to the list       
 * 
 * @details     like singly linked list, there are 3 conditons:
 *              1. add next node to head;
 *              2. add next node to tail;
 *              3. add the next node to a specific position.
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
void insert(struct node** head_ref, int data) 
{ 
        /* head insert node to an list */
        struct node *ptr = (node*) malloc(sizeof(node));
        ptr->data = data;

        ptr->next = *head_ref;
        ptr->prev = NULL;

        if (*head_ref != NULL)
                (*head_ref)->prev = ptr;

        *head_ref = ptr;

        /* tail insert node to an empty list */
} 

int main(int argc, char* argv[])
{
        struct node *head = NULL;
        insert(&head, 3);

        printf("%d", head->data);
        return 0;
}
