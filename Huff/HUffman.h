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
class Node {
    public:
        char ch;
        int weight;
        int parent;
        int Lchild;
        int Rchild;

};
class HUffman {
    public:
        HUffman(size_t n) { node = new Node[2 * n - 1]; count = n;  } 
        ~HUffman() { delete[] node; }
        void Huff_init(map<char, size_t> );
        void select(int, int &, int &);
        void Huff_creat();
        void Huff_encode();
        void Huff_decode();
        void file_out(ifstream &in, ofstream &out);
    private:
        Node* node;
        int count;
        map<char, string> word_value;

};


#endif
