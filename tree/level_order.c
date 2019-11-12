/*************************************************************************
	> File Name: level_order.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 14时58分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char ch;
    struct node *lchild;
    struct node *rchild;
}BiTree;

void creat_tree(BiTree **T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *T = NULL;
    }
    else {
        *T = (BiTree *)malloc(sizeof(BiTree));
        (*T)->ch = ch;
        creat_tree(&(*T)->lchild);
        creat_tree(&(*T)->rchild);
    }
}
int main()
{
    BiTree *T;
    creat_tree(&T);
}
