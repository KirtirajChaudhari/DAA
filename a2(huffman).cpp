//-------------------------------------------------------------
//Huffman Encoding
//-------------------------------------------------------------

#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f){
        ch = c; freq = f;
        left = right = NULL;
    }
};

// Min-heap comparator
struct cmp {
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

void printCode(Node* root, string s){
    if(!root) return;

    // Leaf node → actual character
    if(!root->left && !root->right){
        cout << root->ch << " : " << s << endl;
        return;
    }
    printCode(root->left,  s + "0");
    printCode(root->right, s + "1");
}

int main(){
    int n;
    cout<<"Enter number of symbols: ";
    cin>>n;

    priority_queue<Node*, vector<Node*>, cmp> pq;
    
    cout<<"Enter <char> <freq>:\n";
    for(int i=0;i<n;i++){
        char c; int f;
        cin>>c>>f;
        pq.push(new Node(c,f));
    }

    // Greedy merging
    while(pq.size()>1){
        Node *a = pq.top(); pq.pop();
        Node *b = pq.top(); pq.pop();
        Node *parent = new Node('#', a->freq + b->freq);
        parent->left = a;
        parent->right = b;
        pq.push(parent);
    }

    cout<<"\nHuffman Codes:\n";
    printCode(pq.top(), "");
}
