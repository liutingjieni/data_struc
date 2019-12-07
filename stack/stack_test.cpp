/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月06日 星期五 18时24分02秒
 ************************************************************************/
#include<iostream>
using namespace std;
class Stack{
public:
    Stack() {  };
    void stack_push(void *data);
    void *stack_pop();
    const int stack_size() const {return size;}
private:
    typedef struct node {
        void *data;
        struct node *next;
    }Node;

    Node *head;
    Node *top;
    size_t size = 0;
};

void Stack::stack_push(void *data)
{
    if (size == 0) {
        head = new Node;
        head->data = data;
        top = head;
            
    }
    else {
        Node *temp = new Node;
        temp->data = data;
        top->next = temp;
        top = temp;
            
    }
        size++;
        top->next = NULL;
}

void *Stack::stack_pop()
{
    void *data = top->data;
    Node *temp = head;
    if (size > 1) {
        while (temp->next != top) {
            temp = temp->next; 
                    
        }
        delete(top);
        top = temp;
        size--;
        return data;
            
    }
    else if (size == 1){
        delete(temp);
        size--;
        return data;
            
    }
    return NULL;
}

int main()
{
    int stu[10];
    Stack test;
    for (int i = 0; i != 10; i++) {
        stu[i] = i;
        test.stack_push(&stu[i]);            
    }
    cout << test.stack_size() << endl;

    for (int i = 0; i < 9; i++) {
        int *stu2 = (int *)test.stack_pop();
        if (stu == NULL) {
            cout << "stack_pop error!" << endl;
            return -1;                    
        }
        cout << *stu2 << endl;        
    }
}
