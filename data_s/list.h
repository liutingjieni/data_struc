/*************************************************************************
	> File Name: list.h
	> Author: 
	> Mail: 
	> Created Time: 2019年09月04日 星期三 20时33分13秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H
typedef struct List List;
//int类型返回值为-1表示函数执行错误


//初始化一个有表头的链表
List *list_init(void);
//在链表尾部添加节点
void list_end_add(List *list, void *data);
//在链表头部添加节点
void list_head_add(List *list, void *data);
//在链表指定位置插入
int list_insert(List *list, void *data, int num);
//删除第一个节点
int list_head_delete(List *list);
//删除最后节点
int list_end_delete(List *list);
//删除指定数据的节点
int list_delete(List *list, void *data);
//在链表中查找
void *list_find(List *list, void *data);
//销毁链表
void list_destory(List *list, void (*data_destory)(void *));
//链表的节点数量
size_t list_size(List *list);
#endif
