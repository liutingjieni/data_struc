/*************************************************************************
	> File Name: huffman.c
	> Author:jieni 
	> Mail: 
	> Created Time: 2019年12月21日 星期六 16时24分43秒
 ************************************************************************/

#include <stdio.h>
#define N 6
#define M 11

typedef struct Huffman{
    char word;
    int weight;
    int parent;
    int Lchild;
    int Rchild;
}Node;

Node HuffmanTree[M];

void Huff_init()
{
    for (int i = 0; i < N; i++) {
        HuffmanTree[i].word = 'A' + i;
        scanf("%d", &HuffmanTree[i].weight);
        HuffmanTree[i].parent = 0;
        HuffmanTree[i].Lchild = 0;
        HuffmanTree[i].Rchild = 0;
    }
}


void select(Node *HuffmanTree, int n, int *a, int *b)
{
    int min_weight;
    for (int i = 0; i < n; i++) {
        if (HuffmanTree[i].parent == 0) {
            *a = i;
            min_weight = HuffmanTree[i].weight;
            break;
        }
    }
    for (int i = *a + 1; i < n; i++) {
        if (HuffmanTree[i].parent == 0 &&min_weight > HuffmanTree[i].weight) {
            min_weight = HuffmanTree[i].weight;            
            *a = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (HuffmanTree[i].parent == 0 && i != *a) {
            *b = i;
            min_weight = HuffmanTree[i].weight;
            break;
        } 
            
    }
    for (int i = *b; i < n; i++) {
        if (HuffmanTree[i].parent == 0 && min_weight > HuffmanTree[i].weight && i != *a) {
            min_weight = HuffmanTree[i].weight;          
            *b = i;
        }
            
    }
}
void Huff_creat()
{
    for (int i = N; i < M; i++) {
        int a, b;
        select(HuffmanTree, i, &a, &b);
        HuffmanTree[i].weight = HuffmanTree[a].weight + HuffmanTree[b].weight;
        HuffmanTree[i].Lchild = a;
        HuffmanTree[i].Rchild = b;
        HuffmanTree[a].parent = i;
        HuffmanTree[b].parent = i;
    }
}

void Huff_code(int i)
{
    char c[N][10];
    int t = i;
    int j = 0;
    while (t != M-1) {
    int tmp = t;
    t = HuffmanTree[t].parent;
    if (tmp == HuffmanTree[t].Lchild) {
        c[i][j] = '0';
    }
    else {
        c[i][j] = '1';
    }
        j++;
    }
    c[i][j] = '\0';
    while (j--) {
        printf("%c", c[i][j]);
    }

}
void Huff_code_str()
{
    char s[100];
    scanf("%s", s);
    int t;
    int j = 0;
    while (s[j]) {
        for (int i = 0; i < N; i++) {
            if (HuffmanTree[i].word == s[j]) {
                t = i;
                break;
            }
        }
        Huff_code(t);
        j++;
    }
}

void Huff_decode()
{
    char s[100];
    scanf("%s", s);
    int i = 0;
    while (s[i]) {
        int t = M - 1;
        while (t > N - 1) {
            if (s[i] == '0') {
                t = HuffmanTree[t].Lchild; 
            }
            else {
                t = HuffmanTree[t].Rchild;
            }
            i++;
        }
        printf ("%c", HuffmanTree[t].word);
    }
    printf("\n");
}

int main()
{
    Huff_init();    
    Huff_creat();
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%c:",HuffmanTree[i].word);
        Huff_code(i);
        printf("\n");
    }
    Huff_code_str();
    Huff_decode();

}
