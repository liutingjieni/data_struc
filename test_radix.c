/*************************************************************************
	> File Name: test_radix.c
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月19日 星期四 17时28分39秒
 ************************************************************************/

#include <stdio.h>
#include "radix_sort.h"
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    int t = arr_max(a, 10);
    int *b = arr_sort(a, 10, t);
    print(b, 10);
}
