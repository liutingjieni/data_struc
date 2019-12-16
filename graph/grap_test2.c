/*************************************************************************
	> File Name: grap_test2.c
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月16日 星期一 12时52分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
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

int print(Graph *graph)
{
    int temp = 0, t = 0;
    while(t < graph->vexnum) {
        if (visited[t] == 0) {
            temp++;
        visited[t] = 1;
        for (int j = 0; j < graph->vexnum; j++) {
            
            if (graph->graph[t][j] == 1) {
                  visited[j] = 1;  
            }
         }
        for(int i = 0; i < graph->vexnum; i++) {
            if (visited[i] == 1) {
                for (int j = 0; j < graph->vexnum; j++) {
                    if (graph->graph[i][j] == 1) {
                        visited[j] = 1;
                    }
                }
            }
        }
      
    }
        t++;
    }
    return temp;
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
            graph->graph[y][x] = 1;       
        }
       
        printf("%d\n", print(graph));
}
