/*************************************************************************
	> File Name: huff.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月27日 星期五 12时30分34秒
 ************************************************************************/
#include "HUffman.h"

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
    }
    
}

void HUffman::file_out(ifstream &in, ofstream &out)
{
    in.clear(std::ios::goodbit);
    in.seekg(std::ios::beg);
    
    static int j = 0;
    unsigned char bit[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    unsigned char Bchar = 0;
    string line;
    while (getline(in, line)) {
        line = line + '\n';
        int k = 0;
        while (line[k]) {
        int i = 0;
        string str =word_value[line[k]];
        while (str[i] != '\0') {
            if (str[i] == '1') {
                Bchar = Bchar | bit[j];
            }
            j++;
            if (j == 8) {
                out << Bchar;
                Bchar = 0;
                j = 0;
            }
            i++;
        }
        k++;
    }
    }
}

void HUffman::file_code(ofstream &out)
{
    out << count << " ";
    out << n << " ";
    for (int i = 0; i < 2 * count - 1; i++) {
        out << node[i].ch << " "<< node[i].parent << " "<< node[i].Rchild << " "<< node[i].Lchild << " ";
    }
}
int Get_bit(ifstream &in)
{
    static int i  = 7;
    static unsigned char Bchar;
    unsigned char bit[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    i++;
    if (i == 8) {
        Bchar = in.get();
        i = 0;
    }
    return(Bchar&bit[i]);
}

void HUffman::Huff_decode(ifstream &in, ofstream &out) 
{
    for (int i = 0; i < n - 1; i++) {
        int c = count * 2 - 2;
        while (c >= count) {
            if(Get_bit(in)) {
                c = node[c].Rchild;
            }
            else {
                c = node[c].Lchild;
            }
        }
        out << node[c].ch;
    } 
    out << "\n";
}


