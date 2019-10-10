/*************************************************************************
	> File Name: horse.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 22时07分30秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "_stack.h"
#define MAXSIZE 8

typedef struct {
    int x;
    int y;
}NODE;
int map[MAXSIZE][MAXSIZE];

    int a[8] = {-2,-1, 1, 2, 2, 1,-1,-2};
    int b[8] = { 1, 2, 2, 1,-1,-2,-2,-1};

int node_test(int x, int y)
{
    if (x >= 0 && x < MAXSIZE && y>= 0 && y < MAXSIZE && !map[x][y]) {
        return 1;
    }
    return 0;
}

/*int value(NODE *node)
{
    int value[MAXSIZE];
    for (int i = 0, value[i] = 0; i < MAXSIZE; i++) {
        if (node_test(a[i]+node->x, b[i]+node->y)) {
            for (int j = 0; j < MAXSIZE; j++) {
                if (node_test(a[j]+node->x), b[j]+node->y) {
                   value[i]++; 
                }
            }
        }
        else {
            value[i] = MAXSIZE;
        }

    }
}
*/
void sort(Stack * stack, NODE *node)
{
    int flag = 1;
    //value(node)

    for (int i = 0; i < MAXSIZE; i++) {
        if (node_test(a[i] + node->x, b[i] + node->y)) {
            flag = 0;
            NODE * t = (NODE *)malloc(sizeof(NODE));
            t->x = a[i] + node->x;
            t->y = b[i] + node->y;
            map[t->x][t->y] = stack_size(stack)+1;
            stack_push(stack,t);
            sort(stack, t);
            flag = 1;
        }
    }
    if (flag) {
        if (stack_size(stack) == 64) {
            return;
        }
        NODE *t = stack_pop(stack);
        map[t->x][t->y] = 0;
        free(t);
    }
   
}

void print(Stack *stack)
{
    for (int i =0 ;i < MAXSIZE; i++) {
        for(int j =0; j < MAXSIZE; j++) {
            printf(" %2d ",map[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    NODE *s;
    Stack *stack = stack_init();
    scanf("%d",&(s->x));
    scanf("%d",&(s->y));
    if (!node_test(s->x, s->y)) {
        printf("输入坐标错误，请重新输入！！\n");
        return -1;
    }
    map[s->x][s->y] = 1;
    stack_push(stack, s);
    sort(stack, s);
    print(stack);
    return 0;
}

