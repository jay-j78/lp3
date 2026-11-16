#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left,*right;

    // Initialize character, frequency and child pointers
    Node(char c,int f){
        ch=c;
        freq=f;
        left=right=NULL;
    }
};

// Min Priority Queue: smallest frequency comes first
struct compare{
    bool operator()(Node *a,Node *b){
        return a->freq>b->freq;
    }
};

// Generate Huffman codes: left = 0, right = 1
void printCodes(Node *root,string str){
    if(root==NULL){
        return;
    }

    // Leaf node contains the character and its Huffman code
    if(root->left==NULL && root->right==NULL){
        cout<<root->ch<<":"<<str<<endl;
    }

    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}

void huffmancode(char ch[],int freq[],int n){

    // Create a Min Priority Queue
    priority_queue<Node*,vector<Node*>,compare> pq;

    // Insert all characters with their frequencies
    for(int i=0;i<n;i++){
        pq.push(new Node(ch[i],freq[i]));
    }

    // Repeat until only one node (root) remains
    while(pq.size()>1){

        // Remove two nodes with minimum frequencies
        Node *left=pq.top();
        pq.pop();

        Node *right=pq.top();
        pq.pop();

        // Create a parent node with the sum of both frequencies
        Node *newNode=new Node('$',left->freq+right->freq);

        newNode->left=left;
        newNode->right=right;

        // Insert the new parent node into the priority queue
        pq.push(newNode);
    }

    // Remaining node becomes the root of Huffman Tree
    Node *root=pq.top();

    // Generate and print Huffman codes
    printCodes(root,"");
}

int main(){

    char ch[]={'a','b','c','d','e','f'};
    int freq[]={5,9,12,13,16,45};

    int n=sizeof(ch)/sizeof(ch[0]);

    huffmancode(ch,freq,n);

    return 0;
}
