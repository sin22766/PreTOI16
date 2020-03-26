#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node *left, *right;

    Node(int data) {
        left = right = nullptr;
        value = data;
    }
};

Node *insertNode(Node *root, int data) {
    if (!root) {
        return new Node(data);
    } else {
        if (data >= root->value) {
            root->right = insertNode(root->right, data);
        } else {
            root->left = insertNode(root->left, data);
        }
    }
}

void searchNode(Node *root, int data) {
    if (!root) {
        cout << 0 << "\n";
    } else {
        cout << root->value << " ";
        if (data == root->value) {
            if (root->right && root->right->value == data) {
                searchNode(root->right, data);
            } else {
                cout << "\n";
            }
        } else if (data > root->value) {
            searchNode(root->right, data);
        } else if (data < root->value) {
            searchNode(root->left, data);
        }
    }
}

int main() {
    Node *root = nullptr;
    int n, m, temp;
    cin >> n >> temp;
    root = insertNode(root, temp);
    for (int i = 0; i < n - 1; ++i) {
        cin >> temp;
        insertNode(root, temp);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        searchNode(root, temp);
    }
    return 0;
}
