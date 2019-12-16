/*************************************************************************
	> File Name: creat.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月06日 星期五 10时35分31秒
 ************************************************************************/

#include<stdlib.h>
#include"Graph.h"
typedef struct node {
    void  * data;
}Node;

typedef struct graph {
    int vexnum;
    int arcnum;
    char data[20];
    char graph[20][20];
}Graph;

Graph *graph_init(int vexnum, int arcnum)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vexnum = vexnum;
    graph->arcnum = arcnum;
    for(int i =0; i < graph->vexnum; i++) {
        for (int j = 0; j < graph->vexnum; j++) {
            graph->graph[i][j] = 0;
        }
    }
    return graph;
}


