/*************************************************************************
	> File Name: stack_test.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月08日 星期二 22时53分59秒
 ************************************************************************/
#include <stdio.h>
#include "_stack.h"

struct node{
        int n;
        char s[100];
};

int main()
{
    
    struct node stu;
    Stack *stack = stack_init();
    stack_push(stack, stu);
    struct node *stu2 = stack_pop(stack);
    printf("%d\n",stu2.n);
    printf("%s\n",stu2.s);
}
