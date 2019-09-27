/*************************************************************************
	> File Name: radix_sort.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月27日 星期五 18时52分10秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

typedef struct node 
{
    int data;
    struct node *next;
}Node;

Node RADIX[10];
struct list
{
    Node *head;
    Node *end;
    size_t size;
}
int arr_sort(int *a,int num, int max)
{
    for (int i = 0; i < num; i++) {
        int t = a[i] % 10;
        RADIX[t]->data = a[i]; 
    }
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

int main()
{
    int a[10] = {0,32,76,98,32};
    int max = arr_max(a, 10);
    printf("%d\n", max);
    //arr_sort(a, 10, sizeof(double), max);

}
