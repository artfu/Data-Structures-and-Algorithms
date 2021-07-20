/**
 * @file        1-linked_list.c 
 * @author      artfu 
 * @date        2021.7.21 
 * 
 * @brief       Implement linked lists(NO header) and related operations, 
 *              including insert, search, delete and other operations. 
 * 
 * @details     1. head_insert() -- Insert a node at the HEAD of list
 *              2. tail_insert() -- Insert a node at the END of list
 *              3. insert() -- Insert a node at the specific position of list
 *
 *              4. pos_of() -- search the position of specific value
 *              5. value_of() -- get the value on specific position 
 *              6. head_loc() -- locate the first node of list
 *              7. tail_loc() -- locate the last node of list
 *              8. prev() -- locate the previous node of target node by data value
 *              9. advan() -- locate the advanced node through positon
 *
 *              10. del_node() -- delete node through the data value
 *              11. del_list() -- delete the whole list
 *
 *              12. is_empty() -- check if the list is empty
 *              13. is_last() -- check if the node is the last one
 *
 *              14. print() -- print the list
 */

#include <stdio.h>
#include <stdlib.h>         /* malloc(), free() */

struct node {
        int data;
        struct node *next;
};

struct node *HEAD = NULL;

/****************************     INSERT     **********************************/

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
 *              HAVE TO DO THIS BECAUSE:
 *              Insert a node to the list, we have to change the link aka the pointer next,
 *              All function arguments are passed 'by value', which means 
 *              a temporary copy of originals and will be lost at the end of call. so
 *              A. Global value, exits all the time, change it when you need to;
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
 * @note        1. find the tail
 *              2. add the link
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
                ptem = ptem->next;
        /* use tail_loc() */
        /* ptem = tail_loc(); */
        ptem->next = pn;
        pn->next = NULL;
}

/**
 * @brief       insert() -- Insert a node at the specific position of list
 * 
 * @details 
 * 
 * @note        Always deal with pn->next, then pn. Or list will be lost.
 * 
 * @param       data
 * @param       pos     -- add node after @pos
 * 
 * @return      void
 * @retval      void
*/
void insert(struct node *pos, int data)
{
        struct node *ptem = HEAD;
        struct node *pn = (struct node*) malloc(sizeof(struct node));
        pn->data = data;

        while (ptem->next != pos)
                ptem = ptem->next;
        pn->next = ptem->next;
        ptem->next = pn;
}

/****************************     SEARCH     **********************************/

/**
 * @brief       pos_of() -- search the position of specific value
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       data    --        
 * 
 * @return      pointer to node
 * @retval      NULL -- if not found
 *              pointer of the value -- if found 
*/
struct node* pos_of(int data)
{
        struct node* ptem = HEAD;

        while (ptem != NULL && ptem->data != data)
                ptem = ptem->next;

        return ptem;
}

/**
 * @brief       value_of() -- find the value on specific position
 * 
 * @details 
 * 
 * @note        
 * 
 * @param          
 * 
 * @return      the data of the specific position      
 * @retval      
*/
int value_of(struct node* pos)
{
        return pos->data;
}

/**
 * @brief       head_loc() -- locate the first node of list
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return     
 * @retval    
*/
struct node* head_loc()
{
        return HEAD;
}

/**
 * @brief       tail_loc() -- locate the last node of list
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      tail pointer of list     
 * @retval    
*/
struct node* tail_loc()
{
        struct node *ptem = HEAD;
        while (ptem->next != NULL)
                ptem = ptem->next;

        return ptem;
}

/**
 * @brief       prev() -- locate the previous node
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      the pointer of previous node    
 * @retval    
*/
struct node* prev(int data)
{
        struct node* ptem = HEAD;
        while (ptem->next != NULL && ptem->next->data != data)
                ptem = ptem->next;

        return ptem;
}

/**
 * @brief       advan() -- locate the advanced node
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      the pointer of next node    
 * @retval    
*/
struct node* advan(struct node *pos)
{
        return pos->next;
}

/****************************     DELETE     **********************************/

/**
 * @brief       del_node() -- delete node through the data
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      void
 * @retval    
*/
void del_node(int data)
{
        struct node* pr = prev(data);
        struct node* ptem;

        ptem = pr->next;
        pr->next = ptem->next;
        free(ptem);
}

/**
 * @brief       del_list() -- delete the whole list
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      void
 * @retval    
*/
void del_list()
{
        struct node* ptem = HEAD;
        struct node* tmp;

        HEAD = NULL;
        while (ptem != NULL) {
                tmp = ptem->next;
                free(ptem);
                ptem = tmp;
        }
}

/****************************     STATUS     **********************************/

/**
 * @brief       is_empty() -- check if the list is empty
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      int value
 * @retval      1 -- list is empty
 *              0 -- list is not empty
*/
int is_empty()
{
        return HEAD == NULL;
}

/**
 * @brief       is_last() -- check if the node is the last one
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      int value
 * @retval      1 -- is the last
 *              0 -- is not the last
*/
int is_last(struct node *pos)
{
        return pos->next == NULL;
}

/****************************     OTHERS     **********************************/

/**
 * @brief       print() -- print the list
 * 
 * @details 
 * 
 * @note        
 * 
 * @param       
 * 
 * @return      
 * @retval     
*/
void print()
{
        struct node *ptem = HEAD;
        while (ptem != NULL) {
                printf("%p: %d\n", ptem, ptem->data);
                ptem = ptem->next;
        }
        printf("\n");

}

int main(int argc, char* argv[])
{
        /* Insert */
        head_insert(42);
        tail_insert(24);
        insert(HEAD, 40);

        /* The linked list is: 40 42 24 */
        int tag = is_empty();
        printf("tag of empty = %d\n", tag);
        print();

        /* Search */
        struct node* pos2 = pos_of(42);
        struct node* pos1 = prev(42);
        struct node* pos3 = advan(pos2);
        int loc = is_last(pos3);
        printf("pos3:24 is last = %d\n", loc);
        loc = is_last(pos1);
        printf("pos1:42 is last = %d\n", loc);

        /* Delete */
        del_node(24);
        /* Now the linked list is: 42 40 */
        print();
        del_list();
        tag = is_empty();
        printf("tag of empty = %d\n", tag);
        
        return 0;
}
