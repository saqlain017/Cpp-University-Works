#include <iostream>
using namespace std;

struct Node {
    int ID;
    struct Node* right;
    struct Node* left;
    int h;
    int balance;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->h;
}

int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* leftRotate(Node* y) {
    Node* x = y->right;
    Node* T2 = x->left;

    // Perform rotation
    x->left = y;
    y->right = T2;

    // Update heights
    y->h = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->h = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}
Node* rightRotate(Node* x) {
    Node* y = x->left;
    Node* T2 = y->right;

    // Perform rotation
    y->right = x;
    x->left = T2;

    // Update heights
    x->h = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->h = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* newNode(int value) {
    Node* temp = new Node;
    temp->ID = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->h = 1;  // New node is initially added at leaf level
    return temp;
}

Node* insert(Node* node, int value) {
    if (node == NULL) {
        return newNode(value);
    }

    if (value < node->ID) {
        node->left = insert(node->left, value);
    } else if (value > node->ID) {
        node->right = insert(node->right, value);
    } else {
        return node;
    }

    // Update height
    node->h = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Get balance factor
    int balance = getBalance(node);

    // Perform rotations if needed
    if (balance > 1) {
        if (value < node->left->ID) {
            // Left-Left case
            return rightRotate(node);
        } else {
            // Left-Right case
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balance < -1) {
        if (value > node->right->ID) {
            // Right-Right case
            return leftRotate(node);
        } else {
            // Right-Left case
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

void PreOrder(Node* node) {
    if (node != NULL) {
        cout << node->ID << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

bool search(Node* node, int value) {
    if (node == NULL) {
        cout << "Value not found" << endl;
        return false;
    }

    if (value == node->ID) {
        cout << "Value found" << endl;
        return true;
    } else if (value < node->ID) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

int main() {
    Node* Root = NULL;
    int Value;
    int choice;
    while (true) {
        cout << "Choose 1: Insert, 2: Search, 3: PreOrder, 4: Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Value to perform operation: ";
                cin >> Value;
                Root = insert(Root, Value);
                break;
            case 2:
                cout << "Enter Value to perform operation: ";
                cin >> Value;
                search(Root, Value);
                break;
            case 3:
                cout << "\nPerforming PreOrder traversal:" << endl;
                PreOrder(Root);
                cout << endl;
                break;
            case 4:
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid Choice, choose again" << endl;
                break;
        }
    }

    return 0;
}

