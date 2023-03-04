#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iterator>
#include <map>

using namespace std;

// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/

// A Huffman tree node
class MinHeapNode {
public:
    // One of the input characters
    char data;
    // Frequency of the character
    int freq;
    // Left and right child
    MinHeapNode *left, *right;
  
    MinHeapNode(char d, int f)
    {
        left = right = NULL;
        data = d;
        freq = f;
    }
};
  
// For comparison of
// two heap nodes (needed in min heap)
class ComparatorForHeap {
public:
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};


// Prints huffman codes from
// the root of Huffman Tree.

// Global Maps
map<char, string> mapOfEncoding;
map<string, char> mapOfDecoding;

void printCodes(class MinHeapNode* root, string str)
{
    if (!root) // root == null
        return;
  
    if (root->data != '$'){ // checking whether it is a leaf node
        cout << root->data << ": " << str << "\n";
        char character = root->data;
        string value = str;
        mapOfEncoding.insert(pair<char, string> (character, value));
        mapOfDecoding.insert(pair<string, char> (value, character));
    }

    printCodes(root->left, str + "0");  // recursive
    printCodes(root->right, str + "1"); // recursive
}
  
// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
MinHeapNode* buildHuffmanCodes(char data[], int freq[], int size)
{
    class MinHeapNode *left, *right, *top;
  
    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, ComparatorForHeap> minHeap;
  
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
  
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
  
        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();
  
        right = minHeap.top();
        minHeap.pop();
  
        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);
  
        top->left = left;
        top->right = right;
  
        minHeap.push(top);
    }
  
    // return the priority queue/minHeap root
    return minHeap.top();
}

string encode(MinHeapNode *root, string s){
    string res = "";

    for(int i=0; i<s.size(); i++){
        cout << s[i] << endl;
    }

    return res;
}
// Polymorphism
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
// aaaaaaaaaabbbbbccddddddddddddddeeeeeeeeeeeeeee
    char arr[] = {'a','b','c','d','e'};
    int freq[] = {50,5,2,14,15};
    int n = sizeof(arr)/sizeof(char);


    MinHeapNode* root = buildHuffmanCodes(arr, freq, n);


    // Global Maps 
    // mapOfEncoding, mapOfDecoding
    string initialCode = "";
    printCodes(root, initialCode);

    printMap(mapOfEncoding);
    printMap(mapOfDecoding);


    // Encode/Decode
    string s = "aabaedc";
    string enc = encode(s); // maps are available globally
    cout << "encoded string = " << enc << endl;
} 
/*
a a b    a e  d   c
1 1 0101 1 00 011 0100
// prefix

*/