/*************************************************************************
	> File Name: list.c
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 15时13分55秒
 ************************************************************************/


#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct List {
    Node *phead;
    Node *pend;
    size_t size;
} List;

List *list_init(void)
{
    List *list = (List *)malloc(sizeof(List));
    Node *phead = (Node *)malloc(sizeof(Node));
    list->phead->next = NULL;
    list->pend = list->phead;
    list->size = 0;
    return list;
}

void list_end_add(List *list, void *data)    //传进来的链表必须保证有一个头结点，如果他传进来的是空节点
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    list->pend->next = temp;
    list->pend = temp;
    list->size++;
}

void list_head_add(List *list, void *data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = list->phead->next;
    list->phead->next = temp;
    list->size++;
}

int list_insert(List *list, void *data, int num)
{
    if (list->size <= num) {
        return -1;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    Node *p = list->phead;
    for (int i = 1; i < num && p; i++) {
        p = p->next;     
    }
    temp->next = p->next;
    p->next = temp;
    list->size++;
}

int list_head_delete(List *list)
{
    if (list->phead->next == NULL) {
        return -1;
    }
    Node *temp = list->phead->next;
    list->phead->next = temp->next;
    free(temp);
    list->size--;
}

int list_end_delete(List *list)
{
    if (list->phead->next == NULL) {
        return -1;
    }
    Node *temp = list->phead;
    Node *p;
    while (temp->next != NULL) {
        p = temp;
        temp = temp->next;
    }
    free(temp);
    p->next = NULL;
    list->pend = p;
    list->size--;
    
}

int list_delete(List *list, void *data)
{
    if (list->phead->next == NULL) {
        return -1;
    }
    int flag = -1;
    Node *pre = list->phead;
    Node *temp = list->phead->next;
    while (temp) {
        if(memcmp(temp->data, data, sizeof(data)) == 0) {
            pre = temp->next;
            free(temp);
            list->size--;
            flag = 0;
            break;
        }
        pre = pre->next;
        temp = temp->next;
    } 
    if (flag == -1) {
        return -1;
    }
}

void *list_find(List *list, void *data)
{
    Node *temp = list->phead->next;
    while (temp) {
        if(memcmp(temp->data, data, sizeof(data)) == 0) {
            return data;      
        }
        temp = temp->next;
    }
}

size_t list_size(List *list)
{
    return list->size;
}

void list_destory(List *list, void (*data_destory)(void *))
{
    Node *node = list->phead;
    while (node->next != NULL) {
        Node *temp = node->next;
        node = temp->next;
        free(temp);
    } 
    free(node);
}
