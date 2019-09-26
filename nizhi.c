/*************************************************************************
	> File Name: nizhi.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月26日 星期四 18时55分51秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

/*
NODE *list_reverse(NODE *phead)
{
    NODE * tmp = phead;
    NODE * p = phead->next;
    NODE * q = NULL;
    while (p) {
        q = p;
        p = p->next;
        q->next = tmp;
        tmp = q;
    }
    phead->next = NULL;
    return tmp;
}
*/

void arr_reverse(void *a, int num, int s_a)
{

    void *tmp;
    for (int i = 0; i < num/2; i++) {
        memcpy(&tmp, ((char *)a) + (num -i -1) * s_a, s_a);
        memcpy((char *)a +(num-i-1) * s_a, (char*)a + i * s_a, s_a);
        memcpy((char *)a + i*s_a, &tmp, s_a);
    }
}

int main()
{
    double a[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i<10; i++) {
        printf("%lf\n", a[i]);
    }
    arr_reverse(a, 10, sizeof(int));
    for (int i = 0; i< 10; i++) {
        printf("%lf\n", a[i]);
    }
}
