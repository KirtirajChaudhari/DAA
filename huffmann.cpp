#include <bits/stdc++.h>
using namespace std;

// Node class for Huffman Tree
class Node {
public:
    char ch;       // Character
    int freq;      // Frequency
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Min-heap based on frequency
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string> &huffmanCode) {
    if (root== NULL)
        return;

    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

void huffmanEncoding(vector<char> &chars, vector<int> &freq, int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create leaf nodes for all characters
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    // Step 2: Build the Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); 
        pq.pop();
        Node* right = pq.top(); 
        pq.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Step 3: Generate Huffman Codes
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Step 4: Display the Huffman Codes
    cout << "\nCharacter\tFrequency\tHuffman Code\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << chars[i] << "\t\t   " << freq[i]
             << "\t\t   " << huffmanCode[chars[i]] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);
    
    cout << "Enter character and frequency (separated by space):\n";
    for (int i = 0; i < n; i++) {
        cin >> chars[i] >> freq[i];
    }
    
    huffmanEncoding(chars, freq, n);
    return 0;
}
