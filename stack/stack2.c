/*************************************************************************
	> File Name: stack2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 13时42分19秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next;
}Node;

typedef struct stack {
    Node *top;
    size_t size;
}Stack;

Stack *stack_init()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void stack_push(Stack *stack, void *data)
{
    if(stack->size == 0)
    {
        stack->top = (Node *)malloc(sizeof(Node));
        stack->top->next = NULL;
        stack->top->data = data;
        stack->size++;
    }
    else {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->next = stack->top;
        stack->top = temp;
        stack->size++;
    }
}

void *stack_pop(Stack *stack)
{
    void *data = stack->top->data;
    if (stack->size > 1) {
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
        return data;
    }
    else if (stack->size == 1) {
        free(stack->top);
        stack->size--;
        return data;
    }
    return NULL;
}

int stack_size(Stack *stack)
{
    return stack->size;

}
