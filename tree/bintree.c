/*************************************************************************
	> File Name: bintree.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月04日 星期一 15时00分51秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

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

void a_print_tree(BiTree *T)
{
    if (T == NULL) {
        return;
    }
    printf("%c", T->ch);
    a_print_tree(T->lchild);
    a_print_tree(T->rchild);
}

void b_print_tree(BiTree *T)
{
    if (T == NULL) {
        return;
    }
    b_print_tree(T->lchild);
    printf("%c", T->ch);
    b_print_tree(T->rchild);
}

void c_print_tree(BiTree *T)
{
    if (T == NULL) {
        return;
    }
    c_print_tree(T->lchild);
    c_print_tree(T->rchild);
    printf("%c", T->ch);
}

int main()
{
    BiTree *T;
    creat_tree(&T);
    a_print_tree(T);
    printf("\n");
    b_print_tree(T);
    printf("\n");
    c_print_tree(T);
    printf("\n");
}
