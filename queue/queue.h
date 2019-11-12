/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: 2019年11月08日 星期五 15时01分01秒
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdlib.h>
typedef struct queue Queue;
Queue *queue_init();
void queue_push(Queue *, void *);
void *queue_pop(Queue *);
int queue_size(Queue *);
#endif
