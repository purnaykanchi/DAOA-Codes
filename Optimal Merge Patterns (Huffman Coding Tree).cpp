#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};
void printCodes(Node* root, string code = "") {
    if (!root) return;
    if (!root->left && !root->right)
        cout << root->ch << ": " << code << endl;
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}
void huffmanCoding(unordered_map<char, int> freq_map) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto& [ch, freq] : freq_map)
        pq.push(new Node(ch, freq));
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    printCodes(pq.top());
}int main() {
    unordered_map<char, int> freq = {
        {'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}
    };
    cout << "Huffman Codes:\n";
    huffmanCoding(freq);
    return 0;
}