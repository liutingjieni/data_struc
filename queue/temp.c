/*************************************************************************
	> File Name: temp.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 19时14分01秒
 ************************************************************************/

#include<stdio.h>
int main()
{
    int number;
    unsigned mask;
    mask = 1u << 4;
    scanf("%d", &number);
    while (mask) {
        printf("%d", (number & mask) ? 1 : 0);
        mask >>= 1;
    }
    return 0;
}
