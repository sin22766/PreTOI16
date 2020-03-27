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

void searchNode(Node *root, int data, vector<int> result, vector<int> result_0) {
    if (root) {
        result.push_back(root->value);
        if (data >= root->value) {
            searchNode(root->right, data, result, result_0);
        } else if (data < root->value) {
            searchNode(root->left, data, result, result_0);
        }
    } else {
        result_0 = result;
        while (!result.empty() && result.back() != data) {
            result.pop_back();
        }
        if (result.empty()) {
            for (auto i:result_0) {
                cout << i << " ";
            }
            cout << "0\n";
        } else {
            for (auto i:result) {
                cout << i << " ";
            }
            cout << "\n";
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
        vector<int> result, result_0;
        searchNode(root, temp, result, result_0);
    }
    return 0;
}
