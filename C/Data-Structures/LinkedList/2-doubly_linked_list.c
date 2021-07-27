/**
 * @file        2-linked_list.c 
 * @author      artfu 
 * @date        2020.7.21 
 * 
 * @brief       Implement double linked lists(NO header) and related operations, 
 *              including insert and delete operations. 
 * 
 * @details     Other function, like search, print are same to singly linked list.
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
 * @brief       insert -- insert a node to the head or tail of a list      
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
        struct node *tail = *head_ref;
        struct node *ptr = (struct node*) malloc(sizeof(struct node));
        ptr->data = data;

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
/* insert node to the i-th node */
void i_insert(struct node **head_ref, int data, int i)
{
        struct node *ptem = (struct node*) malloc(sizeof(struct node));
        ptem->data = data;

        struct node *ptr = *head_ref;
        int j = 1;
        
        while (p != NULL && j < i) {
                ptr = ptr->next;
                j++;
        }

        ptr->prev->next = ptem;
        ptem->prev = ptr->prev;
        ptem->next = ptr;
        ptr->prev = ptem;
}

/* README: COMMENT OUT TO RUN */
void p_insert(struct node **head_ref, int data, struct node* pos)
{
        struct node *ptem = (struct node*) malloc(sizeof(struct node));
        ptem->data = data;

        /* insert node after pos */
        pos->next->prev = ptem;
        ptem->next = pos->next;
        pos->next->ptem;
        ptem->prev = pos;

        /* insert node before pos */
        pos->prev->next = ptem;
        ptem->prev = pos->prev;
        ptem->next = pos;
        pos->prev = ptem;
}

/****************************     DELETE     **********************************/

/**
 * @brief       delete() -- delete a node from list
 * 
 * @details     
 *              
 * @note        
 * 
 * @param       head_ref        -- pointer to pointer                 
 * @param       i               -- index
 * 
 * @return      void
 * @retval      void
*/
/* delete the i-th node (i>0) */
void i_delete(struct node **head_ref, int i)
{
        struct node *ptem = *head_ref;
        int j = 1;

        while (j < i && ptem != NULL) {
                ptem = ptem->next;
                j++;
        }

        ptem->next->prev = ptem->prev;
        ptem->prev->next = ptem->next;
        free(ptem);
}

void p_delete(struct node **head_ref, struct node *pos)
{
        struct node *ptem = *head_ref;

        pos->next->prev = pos->prev;
        pos->prev->next = pos->next;
        free(pos);
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
