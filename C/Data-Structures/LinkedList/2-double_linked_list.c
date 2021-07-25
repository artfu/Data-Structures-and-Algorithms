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
 * @details             
 * 
 * @note        What's the difference between linked list and double linked list? 
 *              - the double linked list have another link to previous node.
 *              And Why we need it? What's change when we have another pointer?
 *              - we can easily find previous node.
 *              - when insert a node, we have to deal with the prev pointer.
 *              - so does delete.
 *                      
 *              This time we use another way instead of Global pointer(HEAD) as list
 *              - Given a reference (pointer to pointer) to the head of a list
 *              
 *              And this rises another question -- How to creat a list?
 *              a. Initialize function, which create the first node of a list
 *                      or create a list with one node.
 * 
 * @param       head_ref        -- pointer to pointer                 
 * @param       data            -- int value
 * 
 * @return      void
 * @retval      void
*/

void insert(struct node** head_ref, int data) 
{ 
    struct node *ptem = (struct node*)malloc(sizeof(struct node)); 
    ptem->data = data; 

    ptem->prev = NULL;
    ptem->next = NULL;

    *head_ref = ptem;
} 

int main(int argc, char* argv[])
{
        struct node *head = NULL;
        insert(&head, 3);

        printf("%d", head->data);
        return 0;
}
