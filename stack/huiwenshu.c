/*************************************************************************
	> File Name: huiwenshu.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月25日 星期五 20时27分45秒
 ************************************************************************/
#include "_stack.h"
#include<stdio.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s", s);
    Stack *stack = stack_init();
    int n = strlen(s);
    int i;
    for (i = 0; i < n / 2; i++) {
        stack_push(stack, &s[i]);
    }

    int flag = 0;
    while(i--) {
        char ch = *(char *)stack_pop(stack);
        if (ch != s[--n]) {
            printf("不是回文数！！！\n");
            break;
        }
        else {
            flag = 1;
        }
    }
    if (flag) {
        printf("回文数\n");
    }
}
