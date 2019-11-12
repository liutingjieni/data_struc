/*************************************************************************
	> File Name: temp3.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 20时27分48秒
 ************************************************************************/

#include<stdio.h>

int main()
{
    double d = 3.25;
    float f = d;
    if((double)f == d) {
        printf("hello ");
    }
    else {
        printf("world\n");
    }
}
