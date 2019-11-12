/*************************************************************************
	> File Name: bt_size1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 13时21分55秒
 ************************************************************************/

#include "_stack.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char ch;
    struct Node *lchild;
    struct Node *rchild;
}BiTree;

typedef struct node {
    void *data;
    struct node *next;
}Node;

typedef struct stack {
    Node *head;
    Node *top;
    size_t size;
}Stack;

Stack *stack_init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stack_push(Stack *stack, void *data)
{
    if (stack->size == 0) {
        stack->head = (Node *)malloc(sizeof(Node));
        stack->head->data = data;
        stack->top = stack->head;
    }
    else {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        stack->top->next = temp;
        stack->top = temp;
    }
    stack->size++;
    stack->top->next = NULL;
}

void *stack_pop(Stack *stack)
{
    void *data = stack->top->data;
    Node *temp = stack->head;
    if (stack->size > 1) {
        while (temp->next != stack->top) {
            temp = temp->next; 
        }
        free(stack->top);
        stack->top = temp;
        stack->size--;
        return data;
    }
    else if (stack->size == 1){
        free(temp);
        stack->size--;
        return data;
    }
    return NULL;
}

int stack_size(Stack *stack)
{
    return stack->size;
}

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
