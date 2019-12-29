/*************************************************************************
	> File Name: huff_encode.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月29日 星期日 20时36分28秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "HUffman.h"
using namespace std;
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
