/**************************mZ
	> Mail: 
	> Created Time: 2019年11月08日 星期五 15时33分46秒
 ************************************************************************/
#include"queue.h"
#include<stdio.h>


int main()
{
    Queue *queue = queue_init();
    int i;
    int a[i];
    for(i = 0; i < 10; i++) {
        a[i] = i;
        queue_push(queue, a+i);
        printf("%d ", queue_size(queue));
    }

    for(int i = 0; i < 10; i++) {
        printf("%d ",*(int *)queue_pop(queue));
    }


}
