/*************************************************************************
	> File Name: bstree.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年08月12日 星期三 22时11分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

template <typename T>
class Node;

template <typename T>
class BsTree ;

template <typename T>
class Node {
public:
    T value;
    Node *left;
    Node *right;
    
    void add(Node*);
    void print();
    Node<T> *searchNode(T);
    Node<T> *searchParentNode(T);
    Node<T> *min();
};

template <typename T>
class BsTree {
public:
    void add(T);

    void printNode();
    void deleNode(T);
    Node<T>* search(T value);

private:
    Node<T> *root;
};

template <typename T>
void BsTree<T>::add(T value)
{
    Node<T> *node = new Node<T>;
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    if (!root) {
        root = node;
    } else {
        root->add(node);
    }
}

template <typename T>
void BsTree<T>::printNode()
{
    if(!root) return;
   root->print();
}

template <typename T>
Node<T>* BsTree<T>::search(T value)
{
    if(!root) {
        return NULL;
    } 
    return root->search(value);
}

template <typename T>
void BsTree<T>::deleNode(T value)
{
    Node<T> *node = root->searchNode(value);
    if (!node) {
        return;
    }
    Node<T> *parent = root->searchParentNode(value);
    if (!parent) {
        if(root->left == NULL && root->right == NULL) {
            delete []node;
            root = NULL;
            return;
        }
    }
    if (node->left == NULL && node->right == NULL) {
        if (parent->left == node) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        delete []node;
    } else if (node ->left == NULL || node->right == NULL) {
        if(node->left == NULL) {
            if (parent->left == node) {
                parent->left = node->right;
                delete []node;
            } else if (parent->right == node) {
                parent->right = node->right;
                delete []node;
            }
        } else{
            if (parent->left == node) {
                parent->left = node->left;
                delete []node;
            } else if (parent->right == node) {
                parent->right = node->left;
                delete []node;
            }
        }
    }else {
        Node<T> *min = node->right->min();
        node->value = min->value;
        Node<T> *parent_min = node->right->searchParentNode(min->value);
        if (parent_min->left == min) {
            parent_min->left = NULL;
        } else {
            parent_min->right = NULL;
        }
        delete []min;
    }   
}

template <typename T>
void Node<T>::add(Node *node)
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

template <typename T>
void Node<T>::print()
{
    if(left != NULL) {
        left->print();
    }
    cout << value <<" ";
    if (right != NULL) {
        right->print();
    }
}

template <typename T>
Node<T>* Node<T>::searchNode(T t)
{
    if (t == this->value) {
        return this;
    }else if(t > this->value) {
        if (this->right)
            return this->right->searchNode(t);        
    } else {
        if (this->left)
            return this->left->searchNode(t);
    } 
    return NULL;
}

template <typename T>
Node<T>* Node<T>::searchParentNode(T t)
{
    if ((this->left && t == this->left->value) || (this->right && t == this->right->value)) {
        return this;
    } else if (this->right && t > this->value) {
        this->right->searchParentNode(t);
    } else if (this->left && t <= this->value) {
        this->left->searchParentNode(t);
    }
}

template <typename T>
Node<T>* Node<T>::min()
{
    if (this->left == NULL) {
        return this;
    }
    this->left->min();
}

int main()
{
    BsTree<int> tree;
    tree.add(7);
    tree.printNode();
    cout << endl;
    tree.deleNode(7);
    tree.printNode();
    cout << endl;
    tree.add(7);
    tree.add(3);
    tree.add(10);
    tree.add(12);
    tree.add(5);
    tree.add(1);
    tree.add(9);
    tree.add(2);
    tree.printNode();
    cout << endl;
    tree.deleNode(7);
    tree.printNode();
    cout << endl;
    tree.deleNode(2);
    tree.printNode();
    cout << endl;
    tree.deleNode(5);
    tree.printNode();
    cout << endl;
    tree.deleNode(9);
    tree.printNode();
    cout << endl;
    tree.deleNode(12);
    tree.printNode();
    cout << endl;
    tree.deleNode(3);
    tree.printNode();
    cout << endl;
    tree.deleNode(10);
    tree.printNode();
    cout << endl;
    tree.deleNode(1);
    tree.printNode();
    cout << endl;
}
