/*************************************************************************
	> File Name: bt_size.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 11时12分06秒
 ************************************************************************/
#include "_stack.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char ch;
    struct node *lchild;
    struct node *rchild;
}BiTree;

void creat_tree(BiTree **T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *T = NULL;
    }
    else {
        *T = (BiTree *)malloc(sizeof(BiTree));
        (*T)->ch = ch;
        creat_tree(&(*T)->lchild);
        creat_tree(&(*T)->rchild);
    }
}


void a_print_tree(BiTree *T)
{
    Stack *stack = stack_init();
    BiTree *p = T;
    while (p || stack_size(stack)!= 0) {
        if (p) {
            printf("%c", p->ch);
            stack_push(stack, p);
            p = p->lchild;
            continue;
        }
        if (stack_size(stack) != 0) {
            p = stack_pop(stack);
            p = p->rchild;
        }
    }
}

void c_print_tree(BiTree *T)
{
    Stack *stack = stack_init();
    BiTree *p = T;
    while (p || stack_size(stack)!= 0) {
        if (p) {
            stack_push(stack, p);
            p = p->lchild;
            continue;
        }
        if (stack_size(stack) != 0) {
            p = stack_pop(stack);
            printf("%c", p->ch);
            p = p->rchild;
        }
    }
}

int main()
{
    BiTree *T;
    creat_tree(&T);
    a_print_tree(T);
    printf("\n");
    c_print_tree(T);
    printf("\n");
}
