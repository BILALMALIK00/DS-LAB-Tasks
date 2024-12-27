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

int calculateNodeHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

void updateNodeHeight(Node* node) {
    if (node) {
        int leftHeight = calculateNodeHeight(node->leftChild);
        int rightHeight = calculateNodeHeight(node->rightChild);
        node->height = 1 + max(leftHeight, rightHeight);
    }
}

int calculateBalanceFactor(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return calculateNodeHeight(node->leftChild) - calculateNodeHeight(node->rightChild);
}

Node* rotateLeft(Node* node) {
    Node* newRoot = node->leftChild;
    Node* newRightSubtree = newRoot->rightChild;
    newRoot->rightChild = node;
    node->leftChild = newRightSubtree;
    updateNodeHeight(node);
    updateNodeHeight(newRoot);
    return newRoot;
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->rightChild;
    Node* newLeftSubtree = newRoot->leftChild;
    newRoot->leftChild = node;
    node->rightChild = newLeftSubtree;
    updateNodeHeight(node);
    updateNodeHeight(newRoot);
    return newRoot;
}

Node* rotateLeftRight(Node* node) {
    node->leftChild = rotateRight(node->leftChild);
    return rotateLeft(node);
}

Node* rotateRightLeft(Node* node) {
    node->rightChild = rotateLeft(node->rightChild);
    return rotateRight(node);
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

    updateNodeHeight(root);
    int balance = calculateBalanceFactor(root);

    if (balance > 1 && value < root->leftChild->data) {
        return rotateLeft(root);
    }
    if (balance < -1 && value > root->rightChild->data) {
        return rotateRight(root);
    }
    if (balance > 1 && value > root->leftChild->data) {
        return rotateLeftRight(root);
    }
    if (balance < -1 && value < root->rightChild->data) {
        return rotateRightLeft(root);
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
void kthSmallest(Node* root, int& count, int k, int& kthsmallest_value) {
    if (root == NULL || count >= k) {
        return;
    }
    kthSmallest(root->leftChild, count, k, kthsmallest_value);

    count++;
    if (count == k) {
        kthsmallest_value = root->data;
    }

    kthSmallest(root->rightChild, count, k, kthsmallest_value);
}

void kthLargest(Node* root, int& count, int k, int& kthLargestValue) {
    if (root == NULL || count >= k) {
        return;
    }
    kthLargest(root->rightChild, count, k, kthLargestValue);

    count++;
    if (count == k) {
        kthLargestValue = root->data;
    }
    kthLargest(root->leftChild, count, k, kthLargestValue);
}
void printTreeheights(Node* root) {
    int leftHeight = calculateNodeHeight(root->leftChild);
    int rightHeight = calculateNodeHeight(root->rightChild);

    cout << "Left side height: " << leftHeight << endl;
    cout << "Right side height: " << rightHeight << endl;
}

int main() {
    Node* root = NULL;
    int value, k;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 9);
    root = insertNode(root, 23);
    root = insertNode(root, 20);
    root = insertNode(root, 90);
    root = insertNode(root, 15);
    root = insertNode(root, 8);
    cout << "Enter the value of k: ";
    cin >> k;

    int count = 0, kthSmallest_value = -1;

    kthSmallest(root, count, k, kthSmallest_value);
    if (kthSmallest_value != -1) {
        cout << "The " << k << "-th smallest element is: " << kthSmallest_value << endl;
    } else {
        cout << "There are less than " << k << " elements in the tree" << endl;
    }

    count = 0;
    int kthLargestValue = -1;
    kthLargest(root, count, k, kthLargestValue);
    if (kthLargestValue != -1) {
        cout << "The " << k << "-th largest element is: " << kthLargestValue << endl;
    } else {
        cout << "There are less than " << k << " elements in the tree." << endl;
    }
    printTreeheights(root);
    cout << "In-order traversal of the tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

