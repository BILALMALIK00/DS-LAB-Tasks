#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* leftChild;
    Node* rightChild;
    int height;

    Node(int value) {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
        height = 1;
    }
};

int calculateHeight(Node* node) {
    if (node == NULL) {
        return 0; 
    }
    int leftHeight = calculateHeight(node->leftChild);
    int rightHeight = calculateHeight(node->rightChild);
    return 1 + max(leftHeight, rightHeight);
}


int calculateBalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = calculateHeight(node->leftChild);
    int rightHeight = calculateHeight(node->rightChild);
    return leftHeight - rightHeight;
}


Node* performLLRotation(Node* node) {
    Node* leftSubtreeRoot = node->leftChild;
    Node* leftRightSubtree = leftSubtreeRoot->rightChild;
    leftSubtreeRoot->rightChild = node;
    node->leftChild = leftRightSubtree;
    node->height = calculateHeight(node);
    leftSubtreeRoot->height = calculateHeight(leftSubtreeRoot);
    return leftSubtreeRoot;
}


Node* performRRRotation(Node* node) {
    Node* rightSubtreeRoot = node->rightChild;
    Node* rightLeftSubtree = rightSubtreeRoot->leftChild;
    rightSubtreeRoot->leftChild = node;
    node->rightChild = rightLeftSubtree;
    node->height = calculateHeight(node);
    rightSubtreeRoot->height = calculateHeight(rightSubtreeRoot);
    return rightSubtreeRoot;
}

Node* performLRRotation(Node* node) {
    node->leftChild = performRRRotation(node->leftChild);
    return performLLRotation(node);
}

Node* performRLRotation(Node* node) {
    node->rightChild = performLLRotation(node->rightChild);
    return performRRRotation(node);
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->leftChild = insertNode(root->leftChild, value);
    } else if (value > root->data) {
        root->rightChild = insertNode(root->rightChild, value);
    } else {
        return root;  
    }

    root->height = calculateHeight(root);
    int balance = calculateBalanceFactor(root);

    if (balance > 1 && value < root->leftChild->data) {
        return performLLRotation(root);
    }
    if (balance < -1 && value > root->rightChild->data) {
        return performRRRotation(root);
    }
    if (balance > 1 && value > root->leftChild->data) {
        return performLRRotation(root);
    }
    if (balance < -1 && value < root->rightChild->data) {
        return performRLRotation(root);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->leftChild);
    cout << root->data << " ";
    inorderTraversal(root->rightChild);
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 6);
    root = insertNode(root, 7);

    cout << "AVL Tree created successfully!" << endl;
    cout << "Inorder Traversal: " << endl;
    inorderTraversal(root);
}

