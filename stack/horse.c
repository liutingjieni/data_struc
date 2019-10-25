/*************************************************************************
	> File Name: horse.c
	> Author: 
	> Mail: 
	> Created Time: 2019年10月09日 星期三 22时07分30秒
 ************************************************************************/

#include <stdio.h>
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

typedef struct dire { 
    int a;
    int b;
    int value;
}DIR;
DIR dir[MAXSIZE];

int node_test(int x, int y)
{
    if (x >= 0 && x < MAXSIZE && y>= 0 && y < MAXSIZE && !map[x][y]) {
        return 1;
    }
    return 0;
}

void value_init()
{
    for (int i = 0; i < MAXSIZE; i++) {
        dir[i].a = a[i];
        dir[i].b = b[i];
        dir[i].value = 0;
    }
}

int cmp(const void *a, const void *b)
{
    return (*(DIR *)a).value > (*(DIR *)b).value ? 1 : -1;
}
int value(NODE *node)
{
    for (int i = 0; i < MAXSIZE; i++) {
        dir[i].value = 0;
        if (node_test(dir[i].a+node->x, dir[i].b+node->y)) {
            for (int j = 0; j < MAXSIZE; j++) {
                if (node_test(dir[j].a + node->x, dir[j].b+node->y)) {
                   dir[i].value++; 
                }
            }
        }
        else {
            dir[i].value = MAXSIZE;
        }
       
    }
    qsort(dir, MAXSIZE, sizeof(DIR), cmp);
    
}

void sort(Stack * stack, NODE *node)
{
    int flag = 1;
    value(node);
    DIR dir_t[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++) {
        dir_t[i].a = dir[i].a;
        dir_t[i].b = dir[i].b;
        dir_t[i].value = dir[i].value;
    }
    for (int i = 0; dir_t[i].value < MAXSIZE; i++) {
            flag = 0;
            NODE * t = (NODE *)malloc(sizeof(NODE));
            t->x = dir_t[i].a + node->x;
            t->y = dir_t[i].b + node->y;
            map[t->x][t->y] = stack_size(stack)+1;
            printf("&&&&&&&&&&&%d\n", map[t->x][t->y]);
            stack_push(stack,t);
            sort(stack, t);
            flag = 1;
    }
    if (stack_size(stack) == 64) {
        return;
    }
    if (flag) {
        printf("*************\n");
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
    value_init();
    stack_push(stack, s);
    sort(stack, s);
    print(stack);
    return 0;
}

