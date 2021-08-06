#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *lchild, *rchild;
};

struct stack {
        struct node *ptr;
        struct stack *next;
};

void creat(struct node **tree)
{
        char check;
        *tree = (struct node*) malloc(sizeof(struct node));

        printf("Input node value:\n");
        scanf("%d", &((*tree)->data));
        getchar();
        printf("Add left child to %d?(Y/N):\n", (*tree)->data);
        scanf("%c", &check);
        getchar();
        if (check == 'Y')
                creat(&((*tree)->lchild));
        else
                (*tree)->lchild = NULL;
        printf("Add right child to %d?(Y/N):\n", (*tree)->data);
        scanf("%c", &check);
        getchar();
        if (check == 'Y')
                creat(&((*tree)->rchild));
        else
                (*tree)->rchild = NULL;
}

void preorder(struct node *tree)
{
        if (tree) {
                printf("%d -> ", tree->data);
                preorder(tree->lchild);
                preorder(tree->rchild);
        }
}

void inorder(struct node *tree)
{
        if (tree) {
                inorder(tree->lchild);
                printf("%d -> ", tree->data);
                inorder(tree->rchild);
        }
}

void posorder(struct node *tree)
{
        if (tree) {
                posorder(tree->lchild);
                posorder(tree->rchild);
                printf("%d -> ", tree->data);
        }
}

struct stack* init(struct stack *ps)
{
        ps = NULL;
}

void push(struct stack **ps, struct node *pn)
{
        struct stack *ptmp = (struct stack*) malloc(sizeof(struct stack));
        ptmp->ptr = pn;

        ptmp->next = *ps;
        *ps = ptmp;
}

void pop(struct stack *ps)
{
        struct stack *ptmp = ps;
        ps = ps->next;
        free(ptmp);
}

struct node* top(struct stack *ps)
{
        return ps->ptr;
}

int empty(struct stack *ps)
{
        return ps == NULL;
}

void level_traverse(struct node *tree)
{
        struct stack S;
        struct stack *head = init(&S);

        push(&head, tree);
        
        while (!empty(head)) {
                struct node *p = top(head); 
                pop(head);
                printf("%d\n", p->data);

                if (p->lchild)
                        push(&head, p->lchild);
                if (p->rchild)
                        push(&head, p->rchild);
        }
}

int main(int argc, char** argv)
{
        struct node *ptree;
        creat(&ptree);

        level_traverse(ptree);

        return 0;
}
