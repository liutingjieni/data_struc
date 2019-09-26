/*************************************************************************
	> File Name: duoxiang.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月25日 星期三 22时06分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int a;
    int n;
    struct node *next; 
}NODE;

NODE* list_creat(int n)
{
    getchar();
    NODE *phead = NULL, *pend = NULL;
    char a,b;
    while (n--) {
        if (!phead) {
            phead = (NODE *)malloc(sizeof(NODE));
            scanf("%c%d,%d%c", &a, &(phead->a), &(phead->n), &b);
            pend = phead;
            continue;
        }
        NODE *node;
        node = (NODE *)malloc(sizeof(NODE));
        scanf("%c%d,%d%c",&a, &(node->a), &(node->n),&b);
        pend->next = node;
        pend = node;
    }
    pend->next = NULL;
    return phead;
}

/*void list_insert(int n) 
{
    getchar();
    char a,b;
    NODE *tmp = phead;
    while (n--) {
        NODE *node = (NODE *)malloc(sizeof(NODE));
        scanf("%c%d,%d%c", &a, &(node->a), &(node->n), &b);
        while (1) {
            if (tmp->n == node->n) {
                tmp->a += node->a;
                free(node);
                break;
            } 
            else if (phead->n > node->n) {
                node->next = phead;
                phead = node;
                break;
            }
            else if(tmp->next->n > node->n) {
                node->next = tmp->next;
                tmp->next = node;
                tmp = tmp->next;
                break;
            }
            tmp = tmp->next;
        }

    }
}*/

void list_print(NODE *phead)
{
    NODE *tmp = phead;
    while (tmp) {
        if(tmp->a == 0) {
            tmp = tmp->next;
            continue;
        }
        if (tmp == phead) {
        }
        else if (tmp->a < 0) {
        }
        else {
            printf("+");
        }      
        if (tmp->n == 0) {
            printf("%d",tmp->a);
        }
        else if (tmp->n == 1) {
            printf("%dX",tmp->a);
        }
        else {
            printf("%dX^%d",tmp->a,tmp->n);
        }
        
        tmp = tmp->next;
    }
    printf("\n");
}

NODE* list_reverse(NODE *phead)
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
    phead->next =  NULL;
    return tmp;
}
//A链表i从0开始，第i个元素之后开始到len元素，全部删除

void list_insert2(NODE *ahead, NODE *bhead, int i, int len, int j)
{
    NODE *tmp1 = ahead;
    while (i--) {
        tmp1 = tmp1->next;
    }
    NODE *insert = tmp1->next;  // 要插入到B链表尾部的链表的头指针  
    NODE *tmp2 = tmp1;
    while (len--) {
        tmp2 = tmp2->next;
    }
    tmp1->next = tmp2->next; 
    
    //tmp2为要插入B链表尾部的链表的尾指针

    NODE *tmp3 = bhead;
    while (j--) {
        tmp3 = tmp3->next;
    }
    if (tmp3->next == NULL) {
        tmp3->next = insert;
        tmp2->next = NULL;
    }
    else {
        tmp2->next = tmp3->next;
        tmp3->next = insert;
    }
}
int main()
{
    int n, n2;
    scanf("%d",&n);
    NODE *phead1 = list_creat(n);
    //scanf("%d",&n2);
    //list_insert(n2);
    //NODE *head = list_reverse(phead1);
    scanf("%d",&n2);
    NODE *phead2 = list_creat(n2);
    list_insert2(phead1, phead2, 2,2,1);
    list_print(phead2);
}
