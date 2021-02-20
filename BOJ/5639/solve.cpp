#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(const int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
    void setLeft(Node* newLeft) {
        left = newLeft;
    }
    void setRight(Node* newRight) {
        right = newRight;
    }
};

Node* insert(Node* root, Node* node) {
    if (root == NULL) return node;
    
    if (node->value < root->value) {
        root->setLeft(insert(root->left, node));
    } else {
        root->setRight(insert(root->right, node));
    }
    return root;
}

void printPostOrder(Node* node) {
    if (node == NULL) return;
        
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->value << "\n";
}

int main(void) {
    int temp;
    Node* root = NULL;
    while(scanf("%d", &temp) != EOF) {
       root = insert(root, new Node(temp));
    }
    printPostOrder(root);
    return 0;
}