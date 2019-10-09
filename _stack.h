/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: 2019年10月08日 星期二 22时51分51秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
typedef struct stack Stack;
Stack *stack_init(void);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
int stack_size(Stack *stack);
#endif
