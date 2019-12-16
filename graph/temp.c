/*************************************************************************
	> File Name: temp.c
	> Author: 
	> Mail: 
	> Created Time: 2019年12月06日 星期五 17时33分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
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

int visited[20];

int FirstAdjVex(Graph *graph, int v){
    for (int j = 0; j < graph->vexnum; j++) {
        if (graph->graph[v][j] == 1 && visited[j] != 1) {
                        return j;
                    
        }
            
    }
        return -1;

}

void dfs(Graph *graph, int v) 
{
        printf("%c", graph->data[v]);
        visited[v] = 1;
        int w = FirstAdjVex(graph, v);
    while (w != -1) {
        if(!visited[w]) {
                        dfs(graph, w);
                        w = FirstAdjVex(graph, v);
                    
        }
            
    }
       

}

int visited2[20];
int NextAdjVex(Graph *graph, int v)
{
    for (int j = 0; j < graph->vexnum; j++) {
        if (graph->graph[v][j] == 1 && visited2[j] != 1) {
                        return j;        
                    
        }
            
    }
        return -1;

}

void bfs(Graph *graph, int v)
{
        int wt[20];
    for (int i =0; i < 20; i++) {
                wt[i] = i;
            
    }
        printf("%c", graph->data[v]);
        visited2[v] = 1;
        Queue *queue = queue_init();
        queue_push(queue, &v);
    while (queue_size(queue) != 0) {
                int v = *(int *)queue_pop(queue);
                int w = NextAdjVex(graph, v);
        while (w != -1) {
            if(!visited2[w]) {
                                printf("%c", graph->data[w]);
                                visited2[w] = 1;
                                queue_push(queue, &wt[w]);
                            
            }
                        w = NextAdjVex(graph, v);
                    
        }
            
    }

}
int main()
{
        int vex, arc;
        scanf("%d %d", &vex, &arc);
        char arcs[arc][2];
        Graph *graph = graph_init(vex, arc);
        getchar();
    for (int i = 0; i < vex; i++) {
                scanf("%c", &(graph->data[i]));
            
    }

    for (int i = 0; i < arc; i++) {
                getchar();
                scanf("%c %c", &arcs[i][0], &arcs[i][1]);
                int x, y;
        for (int j = 0; j < vex; j++) {
            if (arcs[i][0] == graph->data[j]) {
                                x = j;
                            
            }
            if (arcs[i][1] == graph->data[j]) {
                                y = j;
                            
            }
                    
        }
                    graph->graph[x][y] = 1;
                    
            
    }
    for (int i = 0; i < vex; i++) {
                printf("%c ",graph->data[i]);
                int temp1 = 0;
                int temp2 = 0;
        for(int j = 0; j < vex; j++) {
            if (graph->graph[i][j] == 1) {
                                temp1++;
                            
            }
            if (graph->graph[j][i] == 1) {
                                temp2++;
                            
            }
                    
        }
                printf("%d %d %d\n", temp1, temp2, temp1 + temp2);
            
    }

        dfs(graph, 0);
        printf("\n");
    bfs(graph, 0);
        printf("\n");

}
