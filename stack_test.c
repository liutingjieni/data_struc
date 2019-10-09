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
 
    int stu[10] = {1,2,3,4,5,6,7,8,9,0};
    int *stu1= stu; 
    Stack *stack = stack_init();
    for (int i = 0; i < 10; i++) {
        stack_push(stack, &stu1[i]);
    }
    printf("%d\n",stack_size(stack));
    for (int i = 0; i < 9; i++) {
        int *stu2 = stack_pop(stack);
        if (stu2 == NULL) {
            printf("stack_pop error\n");
            return -1;
        }
        printf("%d\n",*stu2);
    }
    printf("%d\n",stack_size(stack));

}
