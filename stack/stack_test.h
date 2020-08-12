/*************************************************************************
	> File Name: stack_test.h
	> Author: 
	> Mail: 
	> Created Time: 2019年12月06日 星期五 22时23分25秒
 ************************************************************************/
#include "HUffman.h"

<<<<<<< HEAD:stack/stack_test.h
#ifndef _STACK_TEST_H
#define _STACK_TEST_H
#endif
=======
using namespace std;

void HUffman::filein_node(ifstream &in)
{
    int i =0;
    while(i < 2 * count -1) {
        in >> node[i].ch;
        in >> node[i].parent;
        in >> node[i].Rchild;
        in >> node[i].Lchild;
        i++;
    }
    node[18].ch = '\t';
    node[19].ch = '\n';
    node[20].ch = ' ';
}
int main(int argc, char *argv[])
{
    if (argc < 3) {
        throw runtime_error("argc < 3, please input again!");
    }

    ifstream in(argv[1], ios::out | ios::binary);
    ifstream in1(argv[2], ios::out | ios::binary);
    ofstream out(argv[3], ios::out | ios::binary);
   
    int count ,n;
    in >> count; 
    in >> n;
    HUffman huff(count, n);
    huff.filein_node(in);
    huff.Huff_decode(in1, out);
}

>>>>>>> 14f000dc31af0caaa7bade147f2034097d7618c8:Huff/huff_decode.cpp
