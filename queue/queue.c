/************************:w
 * *************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 15时01分09秒
 **********************************************************************/
#include"queue.h"
typedef struct node {
    void *data;
    struct node *next;
}Node;

typedef struct queue {
    Node *head;
    Node *end;
    size_t size;
}Queue;

Queue *queue_init()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = 0;
    queue->head = NULL;
    return queue;
}

void queue_push(Queue *queue, void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data =  data;
    if (queue->size!= 0) {
        queue->end->next = node;
        queue->end = node;
    }
    else {
        queue->head = node;
        queue->end = queue->head;
    }
    queue->end->next = NULL;
    queue->size++;
}

void *queue_pop(Queue *queue)
{
    if (queue->size > 0) {
        void *data = queue->head->data;
        free(queue->head);
        queue->head =  queue->head->next;
        queue->size--;
        return data;
    }
}

int queue_size(Queue *queue)
{
    return queue->size;
}
