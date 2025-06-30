#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
struct Node {
    char data;
    unsigned freq;
    Node *left, *right;
    Node(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};
void printCodes(Node* root, string str) {
    if (!root) return;
    if (root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void HuffmanCodes(vector<char>& data, vector<int>& freq, int size) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for (int i = 0; i < size; ++i) {
        minHeap.push(new Node(data[i], freq[i]));
    }
    while (minHeap.size() != 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    HuffmanCodes(data, freq, data.size());
    return 0;
}