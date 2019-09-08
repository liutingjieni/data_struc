/*************************************************************************
	> File Name: list_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月06日 星期五 15时10分52秒
 ************************************************************************/

#define CATCH_CONFIG_MAIN
#include "deps/catch.hpp"

#include <list.h>

TEST_CASE("List_API") {

    List *list = list_init();
    REQUIRE(list != NULL);

    SECTION("链表 size 为 0") {
        REQUIRE(list_size(list) == 0);
    }

    SECTION("链表 end_add 1 个, size 为 1") {
        list_end_add(list, (void *)1);
        REQUIRE(list_size(list) == 1);
    }
    SECITION("链表 head_add 1个, size 为 1") {
        list_head_add(list, (void *)1);
        REQUIRE(list_size(list));
}

    SECTION("空队列 push 5 个, size 为 5, pop 3 个, 剩余 2 个; 再 pop 2 个, 队列为空") {
        QueuePush(queue, (void *)1);
        QueuePush(queue, (void *)2);
        QueuePush(queue, (void *)3);
        QueuePush(queue, (void *)4);
        QueuePush(queue, (void *)5);
        REQUIRE(QueueSize(queue) == 5);
        REQUIRE(QueuePop(queue) == (void *)1);
        REQUIRE(QueuePop(queue) == (void *)2);
        REQUIRE(QueuePop(queue) == (void *)3);
        REQUIRE(QueueSize(queue) == 2);
        REQUIRE(QueuePop(queue) == (void *)4);
        REQUIRE(QueuePop(queue) == (void *)5);
        REQUIRE(QueueSize(queue) == 0);
    }

    SECTION("空队列 pop 结果为 NULL, 剩余 0 个") {
        REQUIRE(QueuePop(queue) == NULL);
        REQUIRE(QueuePop(queue) == NULL);
        REQUIRE(QueuePop(queue) == NULL);
        REQUIRE(QueueSize(queue) == 0);
    }

    QueueDestroy(queue, NULL);
}
