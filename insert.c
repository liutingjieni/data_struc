/*************************************************************************
	> File Name: insert.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月26日 星期四 19时26分16秒
 ************************************************************************/

#include<stdio.h>

//A链表i从0开始，第i个元素之后开始到len元素，全部删除
list_insert(NODE *ahead, NODE *bhead, int i, int len, int j)
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
        continue;
    }
    tmp2->next = tmp3->next;
    tmp3->next = insert;

}
