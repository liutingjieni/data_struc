/*************************************************************************
	> File Name: HUffman.h
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 20时39分34秒
 ************************************************************************/

#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class Node {
public:
    char ch;
    int weight = 0;
    int parent = 0;
    int Lchild = 0;
    int Rchild = 0;


};
class HUffman {
public:
    HUffman(size_t c, int t) { node = new Node[2 * c - 1];
                               count = c; 
                               n = t;  }
    ~HUffman() { delete[] node;  }
    void Huff_init(map<char, size_t> );
    void select(int, int &, int &);
    void Huff_creat();
    void Huff_encode();
    void Huff_decode(ifstream &, ofstream &);
    void file_out(ifstream &in, ofstream &out);
    void file_code(ofstream &);
    void filein_node(ifstream &);
private:
    Node* node;
    int count;
    map<char, string> word_value;
    int n;
};
#endif
