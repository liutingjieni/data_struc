/*************************************************************************
	> File Name: huff.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月27日 星期五 12时30分34秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include "HUffman.h"
using namespace std;


void HUffman::Huff_init(map<char, size_t> word_count)
{
    auto map_it = word_count.cbegin();
    int i = 0;
    while(map_it != word_count.cend()) {
        node[i].ch = map_it->first;
        node[i].weight = map_it->second;
        ++map_it;
        i++;
    }
}

void HUffman::select(int n, int &a, int &b)
{
    int min_weight;
    for(int i = 0; i < n; i++) {
        if (node[i].parent == 0) {
            a = i;
            min_weight = node[i].weight;
            break;
        }
    }

    for (int i = a + 1; i < n; i++) {
        if (node[i].parent == 0 && min_weight > node[i].weight) {
            min_weight = node[i].weight;
            a = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (node[i].parent == 0 && i != a) {
            b = i;
            min_weight = node[i].weight;
            break;
        }
    }
    for (int i = b; i < n; i++) {
        if (node[i].parent == 0 && min_weight > node[i].weight && i !=a) {
            min_weight = node[i].weight;
            b = i;
        }
    }
}


void HUffman::Huff_creat()
{
    for (int i = count; i < count * 2 -1; i++) {
        int a = 0, b = 0;
        select(i, a, b);
        node[i].weight = node[a].weight + node[b].weight;
        node[i].Lchild = a;
        node[i].Rchild = b;
        node[a].parent = i;
        node[b].parent = i;
    }
}

void HUffman::Huff_encode()
{
    for (int i = 0; i < count; i++) {
        int t = i;
        string str;
        while (t != count * 2 - 2) {
            int temp = t;
            t = node[t].parent;
            if (temp == node[t].Lchild) {
                str = '0' + str;
            }
            else {
                str = '1' + str;;
            }
        }
        word_value.insert({node[i].ch, str});
        cout << node[i].ch << str << endl;
    }
    
}



void HUffman::file_out(ifstream &in, ofstream &out)
{
    char ch;
    in.clear(std::ios::goodbit);
    in.seekg(std::ios::beg);
    
    char t = 0;
    int j = 7;
    while (in >> ch) {
        int i = 0;
        string str =word_value[ch];
        while (str[i] != '\0') {
            if (str[i] = 0) {
                *(&t + j) = 0;
                j--;
            }
            else {
                *(&t + j) = 1;
                j--;
            }
            if (j == -1) {
                out << ch;
                j = 7;
            }
            i++;
        }

    }
}

void HUffman::huff_decode() 
{

}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        throw runtime_error("argc < 3, please input again!");
    }

    ifstream in(argv[1]);
    ofstream out(argv[2]);
    

    map<char, size_t> word_count;
    char word;
    int count = 0; 
    while (in >> word) {
        count++;
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {
            ++ret.first->second;
            count--;
        }
    }

    HUffman huffman(count);
    huffman.Huff_init(word_count);
    huffman.Huff_creat();
    huffman.Huff_encode();
    huffman.file_out(in, out);

}
