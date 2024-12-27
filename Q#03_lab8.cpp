#include <iostream>
using namespace std;
class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
void input(Node*& root) {
    int data;
    cout << "Enter value : ";
    cin >> data;
    while (data != -1) {
        root = insert(root, data);
        cout << "Enter value (-1 to stop): ";
        cin >> data;
    }
}
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node* search(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == val) {
        return root;
    }
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
int getlevel(Node* root, int val, int level) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == val) {
        return level; 
    }
    int left = getlevel(root->left, val, level + 1);
    if (left != -1) {
        return left;
    }
    return getlevel(root->right, val, level + 1); 
}
void getposition(Node*& root, int val) {
    Node* node = search(root, val);
    if (node) {
        cout << "Value " << val << " exists in the tree" << endl;
        int level = getlevel(root, val, 0);
        cout << "Level: " << level << endl;
        if (level == 0) {
            cout << "Type: Root" << endl;
        } else {
            Node* parent = root;
            int currentLevel = 0;
            while (currentLevel < level - 1) {
                if (val < parent->data) {
                    parent = parent->left;
                } else {
                    parent = parent->right;
                }
                currentLevel++;
            }
            if (parent->left != NULL && parent->left->data == val) {
                cout << "Type: Left Child" << endl;
            } else {
                cout << "Type: Right Child" << endl;
            }
        }
    } else {
        cout << "Value " << val << " does not exist." << endl;
        cout << "----- Inserting -----" << endl;
        root = insert(root, val);
        int level = getlevel(root, val, 0);
        cout << "Inserted at Level: " << level << endl;
        if (level == 0) {
            cout << "Type: Root" << endl;
        } else {
            Node* parent = root;
            int currentLevel = 0;
            while (currentLevel < level - 1) {
                if (val < parent->data) {
                    parent = parent->left;
                } else {
                    parent = parent->right;
                }
                currentLevel++;
            }
            if (parent->left != NULL && parent->left->data == val) {
                cout << "Type: Left Child" << endl;
            } else {
                cout << "Type: Right Child" << endl;
            }
        }
    }
}

int main() {
    Node* root = NULL;
    input(root);
    cout << "Inorder Traversal:" << endl;
    inorder(root);
    cout << endl;
    int valueToSearch;
    cout << "Enter a value to search or insert: ";
    cin >> valueToSearch;
    getposition(root, valueToSearch);
}

