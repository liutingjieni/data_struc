/*************************************************************************
	> File Name: stack_symbol.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 14时28分54秒
 ************************************************************************/

#include "_stack.h"
#include <stdio.h>

int main()
{
    char s[100];
    int flag = 0;
    Stack *stack = stack_init();
    scanf("%s",s);
    char *t = s;
    while (*t) {
        if (*t == '(' || *t == '[' || *t =='{') {
            stack_push(stack, t);
        }
        else if (*t == ')' || *t == ']' || *t == '}') {
            if (stack_size(stack) == 0) {
                flag = 1;
                printf("不匹配\n");
                return 0;
            }
            else if (*t == ')'){
                char *c = stack_pop(stack);
                if (*c != '(') {
                    flag = 1;
                    printf("不匹配！\n");
                    return 0;
                }
            }
            else if (*t == ']'){
                char *c = stack_pop(stack);
                if (*c != '[') {
                    flag = 1;
                    printf("不匹配！\n");
                    return 0;
                }
            }

            else if (*t == '}'){
                char *c = stack_pop(stack);
                if (*c != '{') {
                    flag = 1;
                    printf("不匹配！\n");
                    return 0;
                }
            }
        }
        t++;
    }
    if(flag == 0) {
        printf("匹配\n");
    }
}
