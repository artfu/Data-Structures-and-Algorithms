/**
 * @file        3-circular_linked_list.c 
 * @author      artfu 
 * @date        2020.7.27 
 * 
 * @brief       Implement circular linked lists and related operations, 
 * 
 * @details     What's the biggest difference between singly liked list and circular linked list? 
 *              Head node pointer: head;        Last node pointer: tail
 *              singly linked list      -- tail->next = NULL;
 *              circular linked list    -- tail->next = head;
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

/****************************     CREATE     **********************************/
/**
 * @brief       create -- creat a list from empty
 * 
 * @details     
 * 
 * @note        Let's do the third way -- Use pointer to node as return value
 * 
 * @param       head_ref        -- pointer to pointer                 
 * @param       data            -- int value
 * 
 * @return      void
 * @retval      void
*/
struct node* create(struct node *head)
{
        struct node *ptem = (struct node*) malloc(sizeof(struct node));
        int data;
        printf("Input an int value: ");
        scanf("%d", &data);
        ptem->data = data;

        if (head == NULL) 
                /* the special part I: */
                ptem->next = ptem;

        ptem->next = head;
        head = ptem;


        return head;
}

/* remove -- we'll talk about Linus Torvalds good taste linked list */
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
        struct node **ptr = &(*head_ref);

        while ((*ptr) != target)
                ptr = &(*ptr)->next;
        *ptr = target->next;
}


int main(int argc, char** argv)
{
        struct node *head = NULL;
        head = create(head);
        head = create(head);
        head = create(head);

        struct node *ptr = head;
        /* the special part II: */
        while (ptr->next = head) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
        }

        return 0;
}
