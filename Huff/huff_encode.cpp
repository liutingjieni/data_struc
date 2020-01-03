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

int main(int argc, char *argv[])
{
    if (argc < 4) {
        throw runtime_error("argc < 3, please input again!");
    }

    ifstream in(argv[1], ios::out | ios::binary);
    ofstream out(argv[2], ios::out | ios::binary);
    ofstream out1(argv[3], ios::out | ios::binary);

    map<char, size_t> word_count;
    char word;
    int n = 0;
    int count = 0;
    string line;
    while(getline(in, line)) {
        int i = 0;
        line = line + '\n';
            while (line[i]) {
            count++;
            n++;
            auto ret = word_count.insert({line[i], 1});
            if (!ret.second) {
                ++ret.first->second;
                count--;
            }
            i++;
            }
    }

    HUffman huffman(count, n);
    huffman.Huff_init(word_count);
    huffman.Huff_creat();
    huffman.Huff_encode();
    huffman.file_out(in, out);
    huffman.file_code(out1);
}
