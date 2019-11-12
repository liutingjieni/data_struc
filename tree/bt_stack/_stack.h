/*************************************************************************
	> File Name: _stack.h
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 20时46分41秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
typedef struct stack Stack;
Stack *stack_init(void);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
int stack_size(Stack *stack);
void *stack_top(Stack *stack);
#endif
