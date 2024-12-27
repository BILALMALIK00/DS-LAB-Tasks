//working on binary tree
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

class LNode {
public:
    Node* treeNode;
    LNode* next;

    LNode(Node* node) {
        treeNode = node;
        next = NULL;
    }
};

// Custom queue class using linked list nodes
class Queue {
private:
    LNode* front;
    LNode* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        while (front != NULL) {
            LNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isempty() {
        return front == NULL;
    }

    void enqueue(Node* node) {
        LNode* newNode = new LNode(node);
        if (isempty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Node* dequeue() {
        if (!isempty()) {
            LNode* temp = front;
            Node* dequeuedNode = front->treeNode;
            front = front->next;
            delete temp;
            return dequeuedNode;
        }
        return NULL;
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

bool isFull(Node* node) {
    if (node == NULL) {
        return true;
    }
    if (node->left == NULL && node->right == NULL) {
        return true; 
    }
    if (node->left != NULL && node->right != NULL) {
        return (isFull(node->left) && isFull(node->right));
    }
    return false; 
}

bool isComplete(Node* root) {
    if (root == NULL){
    	return true;
	}
    
    Queue q;
    q.enqueue(root);
    bool found = false;

    while (!q.isempty()) {
        Node* temp = q.dequeue();

        if (temp->left != NULL) {
            if (found) {
                return false; 
            }
            q.enqueue(temp->left);
        } else {
            found = true; 
        }

        if (temp->right != NULL) {
            if (found) {
                return false; 
            }
            q.enqueue(temp->right);
        } else {
            found = true; 
        }
    }
    return true;
}

void makingfull_tree(Node*& root) {
    if (root == NULL) return;

    makingfull_tree(root->left);
    makingfull_tree(root->right);

    if (root->left == NULL && root->right != NULL) {
        delete root->right;
        root->right = NULL; 
    }
    if (root->right == NULL && root->left != NULL) {
        delete root->left;
        root->left = NULL; 
    }

    if (root->left != NULL && root->right == NULL) {
        return; 
    }
}
int main() {
    Node* root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    root = insert(root, arr, n, 0);

    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;
    if (isFull(root)) {
        cout << "Binary tree is a full binary tree" << endl;
    } else {
        cout << "Binary tree is not a full binary tree" << endl;
    }
    if (isComplete(root)) {
        cout << "Binary tree is a complete binary tree" << endl;
    } else {
        cout << "Binary tree is not a complete binary tree" << endl;
    }
    if (!isFull(root)) {
        cout << "Making the tree full" << endl;
        makingfull_tree(root);
    }
    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;


}

