#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue>
using namespace std;

// Define the structure for node binary tree node
struct BSTNode {
    string data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode* root, string value) {
    if (root == NULL) {
        BSTNode* newNode = new BSTNode;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    queue<BSTNode*> q;
    q.push(root);

    while (!q.empty()) {
        BSTNode* current = q.front();
        q.pop();

        if (current->left == NULL) {
            current->left = new BSTNode;
            current->left->data = value;
            current->left->left = NULL;
            current->left->right = NULL;
            return root;
        } else if (current->right == NULL) {
            current->right = new BSTNode;
            current->right->data = value;
            current->right->left = NULL;
            current->right->right = NULL;
            return root;
        } else {
            q.push(current->left);
            q.push(current->right);
        }
    }

    return root;
}


// Function to check if two binary trees are equal (have the same data at the same nodes)
bool areEqual(BSTNode* root1, BSTNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) && areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
    }

    return false;
}

// Function to check if two binary trees have the same structure
bool haveSameStructure(BSTNode* root1, BSTNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 != NULL && root2 != NULL) {
        return haveSameStructure(root1->left, root2->left) && haveSameStructure(root1->right, root2->right);
    }

    return false;
}

// Function to check if two binary trees are mirror images of each other
bool areMirror(BSTNode* root1, BSTNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) && areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);
    }
    return false;
}
void printt(const string& prefix, BSTNode* parent, bool isLeft, bool isRoot) {
    if (parent == NULL)
        return;

    if (isRoot) {
        cout << "RT----";
    }
    else {
        cout << prefix <<
            (isLeft ? "(L)|----" : "(R)L----");
    }
    // print the value of the node
    cout << parent->data << endl;

    // enter the next tree level - left and right branch
    printt(prefix + (isLeft ? "   | " : "    "),
        parent->left, true, false);
    printt(prefix + (isLeft ? "   | " : "    "),
        parent->right, false, false);
}

 //pass the root node of your binary tree
void printBT(BSTNode* node) {
    printt("", node, false, true);
}


int main() {
    // Create and populate binary tree T1 and T2 using your insert function

    BSTNode* root1 = NULL;
    BSTNode* root2 = NULL;

    // Example of inserting values into T1 and T2
    root1 = insert(root1, "AB");
    root1 = insert(root1, "ABC");
    root1 = insert(root1, "CD");
    root1 = insert(root1, "NCS");
    root1 = insert(root1, "ABCD");
    root1 = insert(root1, "CDA");
    root1 = insert(root1, "NCSA");
    root1 = insert(root1, "ANCS");
    root1 = insert(root1, "AABCD");
    root1 = insert(root1, "ACDA");
    root1 = insert(root1, "ANCSA");
    root2 = insert(root2, "AB");
    root2 = insert(root2, "ABC");
    root2 = insert(root2, "NCS");
    root1 = insert(root2, "NCSA");
    root1 = insert(root2, "ABCD");
    root1 = insert(root2, "CDA");
    root1 = insert(root2, "ANCS");
    root1 = insert(root2, "AABCD");
    root1 = insert(root2, "ACDA");
    root1 = insert(root2, "ANCSA");
	printBT(root1);
	cout << " tree 1 : " << endl;
	printBT(root2);
    // Check if T1 and T2 are equal
    if (areEqual(root1, root2)) {
        cout << "T1 and T2 are equal." << endl;
    }
    else {
        cout << "T1 and T2 are not equal." << endl;
    }

    // Check if T1 and T2 have the same structure
    if (haveSameStructure(root1, root2)) {
        cout << "T1 and T2 have the same structure." << endl;
    }
    else {
        cout << "T1 and T2 do not have the same structure." << endl;
    }

    // Check if T1 and T2 are mirror images of each other
    if (areMirror(root1, root2)) {
        cout << "T1 and T2 are mirror images of each other." << endl;
    }
    else {
        cout << "T1 and T2 are not mirror images of each other." << endl;
    }

    return 0;
}


