//
// Created by sthap on 06-11-2025.
//

#include <iostream>
#include <list>
using namespace std;

class HashTable {
    list<int> *t;
    int size;
    int hash(int k) { return k % size; }
public:
    HashTable(int s=10) { size=s; t = new list<int>[size]; }
    void insert(int k) { t[hash(k)].push_back(k); }
    bool search(int k) {
        for(int x : t[hash(k)])
            if(x == k) return true;
        return false;
    }
    void display() {
        for(int i=0; i<size; i++) {
            cout << i << ": ";
            for(int x : t[i]) cout << x << " ";
            cout << endl;
        }
    }
};

struct Node {
    int k, h;
    Node *l, *r;
    Node(int x) : k(x), h(1), l(NULL), r(NULL) {}
};

class AVL {
    Node* root;
    int ht(Node* n) { return n ? n->h : 0; }
    int bf(Node* n) { return n ? ht(n->l) - ht(n->r) : 0; }

    Node* rRotate(Node* y) {
        Node* x = y->l;
        y->l = x->r;
        x->r = y;
        y->h = max(ht(y->l), ht(y->r)) + 1;
        x->h = max(ht(x->l), ht(x->r)) + 1;
        return x;
    }

    Node* lRotate(Node* x) {
        Node* y = x->r;
        x->r = y->l;
        y->l = x;
        x->h = max(ht(x->l), ht(x->r)) + 1;
        y->h = max(ht(y->l), ht(y->r)) + 1;
        return y;
    }

    Node* insert(Node* n, int k) {
        if(!n) return new Node(k);
        if(k < n->k) n->l = insert(n->l, k);
        else if(k > n->k) n->r = insert(n->r, k);
        else return n;

        n->h = 1 + max(ht(n->l), ht(n->r));
        int b = bf(n);

        if(b > 1 && k < n->l->k) return rRotate(n);
        if(b < -1 && k > n->r->k) return lRotate(n);
        if(b > 1 && k > n->l->k) { n->l = lRotate(n->l); return rRotate(n); }
        if(b < -1 && k < n->r->k) { n->r = rRotate(n->r); return lRotate(n); }
        return n;
    }

    void inorder(Node* n) {
        if(n) { inorder(n->l); cout << n->k << " "; inorder(n->r); }
    }

public:
    AVL() : root(NULL) {}
    void insert(int k) { root = insert(root, k); }
    void display() { inorder(root); cout << endl; }
};

int main() {
    cout << "=== Hash Table ===\n";
    HashTable ht(7);
    ht.insert(10); ht.insert(20); ht.insert(15); ht.insert(7);
    ht.display();
    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n\n";

    cout << "=== AVL Tree ===\n";
    AVL avl;
    avl.insert(10); avl.insert(20); avl.insert(30); avl.insert(40); avl.insert(50);
    cout << "Inorder: "; avl.display();

    return 0;
}
