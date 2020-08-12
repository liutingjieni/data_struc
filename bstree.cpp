/*************************************************************************
	> File Name: bstree.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年08月12日 星期三 22时11分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

template <typename T>
class BsTree {
public:
    void add(T value)
    {
        Node *node = new Node;
        node->value = value;
        if (!root) {
            root = node;
        } else {
            root->add(node);
        }

    }

    void printNode()
    {
       root->print();
    }
    void deleNode(T value);

    class Node {
    public:
        T value;
        Node *left;
        Node *right;
        
        void add(Node *node)
        {
            if (node->value > this->value) {
                if (this->right == NULL) {
                    this->right = node;
                } else {
                    this->right->add(node);
                }
            } else {
                if (this->left == NULL) {
                    this->left = node;
                } else {
                    this->left->add(node);
                }
            }
        }
        void print()
        {
            if(left != NULL) {
                left->print();
            }
            cout << value <<" ";
            if (right != NULL) {
                right->print();
            }
        }

    };
private:
    Node *root;
};


int main()
{
    BsTree<int> tree;
            tree.add(7);
            tree.add(3);
            tree.add(10);
            tree.add(12);
            tree.add(5);
            tree.add(1);
            tree.add(9);
            tree.add(2);
    tree.printNode();
}
