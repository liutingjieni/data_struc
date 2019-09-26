/*************************************************************************
	> File Name: homework.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月26日 星期四 21时11分38秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

void *arr_find(void *a,void *data, int num, int s_n)
{
    int flag = 0;
    for (int i = 0; i < num; i++) {
        if (memcmp(&data, a+i*s_n, s_n) == 0) {
            flag = 1;
            return data;
        }
    }
    if (flag == 0) {
        return 0;
    }
}

void *arr_find_max(void *a, int num, int s_n)
{
    void *max1 = a;
    for (int i =0; i < num; i++) {
        if (memcmp(max1, a+i*s_n, s_n) < 0) {
            max1 = a+i*s_n;
        }
    }    
    return max1;
}

void *arr_find_max2(void *a, int num, int s_n, void *max1)
{
    void *max2 = a;
    for (int i =0; i < num; i++) {
        if (memcmp(max1, a, s_n) == 0) {
            max2 = a + s_n;
        }
        if (memcmp(max2, a+i*s_n, s_n) < 0 && a+i*s_n != max1) {
            max2 = a+i*s_n;
        }
    }
    return max2;
}
int main()
{
    int a[10];

    for (int i = 0; i < 10; i++) {
        a[i] = 2*(10 - i);
    }
    //void *data = arr_find(a, (void *)10, 10, sizeof(int));
    void *data = arr_find_max(a, 10, sizeof(int));
    void *data1 = arr_find_max2(a, 10, sizeof(int), data);
    printf("%d %d\n", *(int *)data, *(int *)data1);
}
