/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月08日 星期二 22时33分15秒
 ************************************************************************/
#include "_stack.h"
#include<stdio.h>
#include <stdlib.h>


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
    stack->top = NULL;
}

void *stack_pop(Stack *stack)
{
    if (stack->size >= 0) {
        void *data = stack->top->data;
        Node *temp = stack->head;
        while (temp->next != stack->top) {
            temp = temp->next; 
        }
        free(stack->top);
        stack->top = temp;
        stack->size--;
        return data;
    }
    return NULL;
}


