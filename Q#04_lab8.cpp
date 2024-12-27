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
//since question ask to find muliple occurences so i modify insert function so that user can input duplicates as well
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else { // Insert duplicates on the right
        root->right = insert(root->right, val);
    }
    return root;
}

void input(Node*& root) {
    cout << "Enter value (-1 to stop): ";
    int data;
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
int countOccurrences(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    
    int count = 0; 
    if (root->data == value) {
        count = 1;
    }
    count += countOccurrences(root->left, value);
    count += countOccurrences(root->right, value);
    
    return count;
}

void find_closest_floor_value(Node* root, int x, int& closest_value, bool& found) {
    if (root == NULL) {
        return;
    }

    find_closest_floor_value(root->left, x, closest_value, found);
    if (root->data <= x) {
        if (!found || (closest_value < root->data)) {
            closest_value = root->data;
            found = true; 
        }
    }
    find_closest_floor_value(root->right, x, closest_value, found);
}

void find_closest_ceiling_value(Node* root, int x, int& closest_value, bool& found) {
    if (root == NULL) {
        return;
    }

    find_closest_ceiling_value(root->left, x, closest_value, found);
    if (root->data >= x) {
        if (!found || (closest_value > root->data)) {
            closest_value = root->data; 
            found = true; 
        }
    }
    find_closest_ceiling_value(root->right, x, closest_value, found);
}

int main() {
    Node* root = NULL;
    input(root);

    cout << "Inorder Traversal:" << endl;
    inorder(root);
    cout << endl;

    int x;
    char choice;
    cout << "Enter a value X: ";
    cin >> x;
    cout << "Do you want to find floor (f) or ceiling (c)? ";
    cin >> choice;

    int closestValue = -1;
    bool found = false; 

    if (choice == 'f' || choice == 'F') {
        find_closest_floor_value(root, x - 1, closestValue, found);
        if (found) {
            int occurrences = countOccurrences(root, closestValue);
            cout << "Closest floor value found: " << closestValue << " (Occurrences: " << occurrences << ")" << endl;
        } else {
            cout << "No floor value found." << endl;
        }
    } else if (choice == 'c' || choice == 'C') {
        find_closest_ceiling_value(root, x + 1, closestValue, found);
        if (found) {
            int occurrences = countOccurrences(root, closestValue);
            cout << "Closest ceiling value found: " << closestValue << " (Occurrences: " << occurrences << ")" << endl;
        } else {
            cout << "No ceiling value found." << endl;
        }
    } else {
        cout << "Invalid choice!" << endl;
    }
}

