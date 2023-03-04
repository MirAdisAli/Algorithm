#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iterator>
#include <map>

using namespace std;

class MinHeapNode {
public:

    char data;
    int freq;
    MinHeapNode *left, *right;
  
    MinHeapNode(char d, int f)
    {
        left = right = NULL;
        data = d;
        freq = f;
    }
};
  
class ComparatorForHeap {
public:
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

map<char, string> mapOfEncoding;
map<string, char> mapOfDecoding;

void printCodes(class MinHeapNode* root, string str)
{
    if (!root) 
        return;
  
    if (root->data != '$'){ 
        cout << root->data << ": " << str << "\n";
        char character = root->data;
        string value = str;
        mapOfEncoding.insert(pair<char, string> (character, value));
        mapOfDecoding.insert(pair<string, char> (value, character));
    }

    printCodes(root->left, str + "1"); //Edited by 182014015
    printCodes(root->right, str + "0"); //Edited by 182014015
}
  
MinHeapNode* buildHuffmanCodes(char data[], int freq[], int size)
{
    class MinHeapNode *left, *right, *top;
  
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, ComparatorForHeap> minHeap;
  
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
  
    while (minHeap.size() != 1) {
  
        left = minHeap.top();
        minHeap.pop();
  
        right = minHeap.top();
        minHeap.pop();
  
        top = new MinHeapNode('$', left->freq + right->freq);
  
        top->left = left;
        top->right = right;
  
        minHeap.push(top);
    }
  
    return minHeap.top();
}

string encode(MinHeapNode *root, string s){
    string res = "";

    for(int i=0; i<s.size(); i++){
        cout << s[i] << endl;
    }

    return res;
}

void printMap(map<char, string> mapEncoding){
    map<char, string>::iterator itr;
    for (itr = mapEncoding.begin(); itr != mapEncoding.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
}
void printMap(map<string, char> mapDecoding){
    map<string, char>::iterator itr;
    for (itr = mapDecoding.begin(); itr != mapDecoding.end(); ++itr) {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;
}

string encode(string str){
    string res = "";
    for(int i=0; i<str.size(); i++){
        char c = str[i];
        auto itr = mapOfEncoding.find(c);
        string val = itr->second;
        res = res + val;
    }
    return res;
}

int main() {

    char arr[] = {'a','b','c','d','e'};
    int freq[] = {50,5,2,14,15};
    int n = sizeof(arr)/sizeof(char);


    MinHeapNode* root = buildHuffmanCodes(arr, freq, n);

    string initialCode = "";
    printCodes(root, initialCode);

    printMap(mapOfEncoding);
    printMap(mapOfDecoding);

    string s = "aabaedc";
    string enc = encode(s); 
    cout << "encoded string = " << enc << endl;
}