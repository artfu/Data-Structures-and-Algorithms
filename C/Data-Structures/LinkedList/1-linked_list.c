/**
 * @file        1-linked_list.c 
 * @author  
 * @date    
 * 
 * @brief       Implement linked lists(NO header) and related operations, 
 *              including insert, search, delete and print operations. 
 * 
 * @details     1. head_insert() -- Insert a node at the Head of list
 */

#include <stdio.h>
#include <stdlib.h>         /* malloc(), free() */

struct node {
        int data;
        struct node *next;
};

struct node *HEAD = NULL;
struct node *TAIL = NULL;

/**
 * @brief       head_insert() -- Insert a node at the HEAD of list
 * 
 * @details 
 * 
 * @note        1. Use Global pointer value as the target list, or
 *              2. use pointer to pointer as formal parameters, or
 *                      eg: void head_insert(struct node** head, int data) { }
 *              3. use pointer as return value
 *                      eg: struct node* head_insert(struct node* head, int data) { }
 *              WE HAVE TO DO THIS BECAUSE:
 *              Insert a node to the list, we have to change the link aka the pointer next,
 *              All function arguments are passed 'by value', which means 
 *              a temporary copy of originals and will be lost at the end of call. so
 *              A. Global value, exits all the time, change it when you need to do;
 *              B. Use pointer to change the originals;
 *              C. Use return value to save the change.
 *              That's WHY.
 * 
 * @param       data
 * 
 * @return      void
 * @retval      void
*/
void head_insert(int data)
{
        struct node *pn = (struct node*) malloc(sizeof(struct node));

        pn->data = data;
        pn->next = HEAD;
        HEAD = pn;
}


/**
 * @brief       tail_insert() -- Insert a node at the END of list
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       data
 * 
 * @return      void
 * @retval      void
*/
void tail_insert(int data)
{
        struct node *ptem = HEAD;
        struct node *pn = (struct node*) malloc(sizeof(struct node));
        pn->data = data;

        while (ptem->next != NULL)
                ptem++;
        ptem->next = pn;
        pn->next = NULL;
}

int main(int argc, char* argv[])
{
        head_insert(42);
        printf("%p\n", HEAD);
        printf("%p\n", TAIL);
        head_insert(41);
        printf("%p\n", HEAD);
        printf("%p\n", TAIL);
        head_insert(40);
        printf("%p\n", HEAD);
        printf("%p\n", TAIL);
        head_insert(39);
        printf("%p\n", HEAD);
        printf("%p\n", TAIL);
        head_insert(38);
        printf("%p\n", HEAD);
        printf("%p\n", TAIL);
        head_insert(37);
        printf("%p\n", HEAD);
        printf("%p\n", TAIL);
        tail_insert(43);
        printf("%p\n", HEAD);
        printf("%p\n", TAIL);
        struct node *ptem = HEAD;
        while (ptem->next != NULL) {
                ptem--;
                printf("%d ", ptem->data);
        }
        return 0;
}