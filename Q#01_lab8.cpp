#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* insert(Node* root, int arr[], int size, int i) {
    if (i >= size) {
        return NULL;
    }
    root = new Node(arr[i]);
    root->left = insert(root->left, arr, size, 2 * i + 1);
    root->right = insert(root->right, arr, size, 2 * i + 2);

    return root;
}

void inorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    root = insert(root, arr, n, 0);

    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;

}

