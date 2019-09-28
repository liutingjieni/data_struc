/*************************************************************************
	> File Name: radix_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月27日 星期五 18时52分10秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define base 10

typedef struct node 
{
    int data;
    struct node *next;
}Node;

typedef struct list
{
    Node *head;
    Node *end;
    size_t size;
}List;

List *list[base];

int *arr_sort_radix(int *a,int num, int max, int n)
{
    for (int i = 0; i < base ; i++) {
        list[i] = (List *)malloc(sizeof(List));
    }
    for (int i = 0; i < num; i++) {
        int t = a[i] % (int) pow(base,n) / (int)pow (base, n-1);
        if (list[t]->size == 0) {
            list[t]->head = (Node *)malloc(sizeof(Node));
            list[t]->head->data = a[i];
            list[t]->end = list[t]->head;
            list[t]->size++;
        }
        else {
            Node *node = (Node *)malloc(sizeof(Node)); 
            node->data = a[i];
            list[t]->end->next = node;
            list[t]->end = node;
            list[t]->size++;
        }
        list[t]->end->next = NULL;
    }
    int j = 0;
    for (int i = 0; i < base; i++) {
        if (list[i]->size != 0) {
            Node *tmp;
            while (list[i]->size) {
                tmp = list[i]->head;
                list[i]->head =list[i]->head->next;
                a[j++] = tmp->data;
                free(tmp);
                --list[i]->size;
            }
        }
    }
    for (int i = 0; i < base; i++) {
        free(list[i]);
    }
    return a;
}

int arr_max(int *a, int num)
{
    int max = a[0];
    for (int i = 0; i < num; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

void arr_print(int *a, int num)
{
    for (int i = 0; i < num; i++) {
        printf("%d\n", a[i]);
    }

}
int *arr_sort(int *a, int num, int max)
{
    int n = 0;
    while (max) {
        ++n;
        a = arr_sort_radix(a, 10, max, n);
        max = max/base;
    }
    return a;

}
int main()
{
    int a[10] = {64,8,216,512,27,729,0,1,343,125};
    int max = arr_max(a, 10);
    int *b = arr_sort(a, 10, max);
    arr_print(b, 10);
}
