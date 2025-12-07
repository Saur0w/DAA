#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int f;
    Node *l, *r;
    Node(char c, int f): ch(c), f(f), l(NULL), r(NULL) {}
};

struct Cmp {
    bool operator()(Node *a, Node *b) { return a->f > b->f; }
};

void buildCodes(Node *root, string s, map<char,string> &code) {
    if (!root) return;
    if (!root->l && !root->r) code[root->ch] = s;
    buildCodes(root->l, s + "0", code);
    buildCodes(root->r, s + "1", code);
}

int main() {
    string text = "huffman_example";
    map<char,int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (auto &p : freq) pq.push(new Node(p.first, p.second));
    while (pq.size() > 1) {
        Node *a = pq.top(); pq.pop();
        Node *b = pq.top(); pq.pop();
        Node *c = new Node('$', a->f + b->f);
        c->l = a; c->r = b;
        pq.push(c);
    }
    Node *root = pq.top();

    map<char,string> code;
    buildCodes(root, "", code);

    cout << "Codes:\n";
    for (auto &p : code) cout << p.first << " " << p.second << "\n";

    string enc;
    for (char c : text) enc += code[c];
    cout << "Encoded: " << enc << "\n";

    map<string,char> rev;
    for (auto &p : code) rev[p.second] = p.first;
    string cur, dec;
    for (char b : enc) {
        cur += b;
        if (rev.count(cur)) {
            dec += rev[cur];
            cur.clear();
        }
    }
    cout << "Decoded: " << dec << "\n";
}
