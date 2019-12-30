/*************************************************************************
	> File Name: huff_decode.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 20时47分09秒
 ************************************************************************/
#include "HUffman.h"

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

