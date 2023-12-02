#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    Node* children[4];

    Node(int value) {
        this->value = value;

        for (int i = 0; i < 4; i++) {
            children[i] = NULL;
        }
    }
};

// Function to insert nodes into the tree
void insertNode(Node* root, vector<int>& S, int level, int& height, vector<vector<int> >& subSets) {
    if (S.empty()) {
        return;
    }

    int medianIndex = S.size() / 2;
    int median = S[medianIndex];

    root->value = median;

    // Output the level and height of this node
    cout << "Level: " << level << ", Height: " << height << ", Value: " << root->value << endl;

    vector<int> S1, S2, S3, S4;

    for (int i = 0; i < S.size(); i++) {
        if (i < medianIndex) {
            if (S1.size() < 3) {
                S1.push_back(S[i]);
            }
            else {
                S2.push_back(S[i]);
            }
        }
        else if (i == medianIndex) {
            continue;  // Skip the median value
        }
        else if (i < medianIndex + medianIndex / 3) {
            if (S3.size() < 3) {
                S3.push_back(S[i]);
            }
            else {
                S2.push_back(S[i]);
            }
        }
        else if (i < medianIndex + medianIndex * 2 / 3) {
            if (S3.size() < 3) {
                S3.push_back(S[i]);
            }
            else {
                S4.push_back(S[i]);
            }
        }
        else {
            S4.push_back(S[i]);
        }
    }

    // Store the subSets
    subSets.push_back(S1);
    subSets.push_back(S2);
    subSets.push_back(S3);
    subSets.push_back(S4);

    height = level + 1;

    for (int i = 0; i < 4; i++) {
        vector<int>* childSet = NULL;

        switch (i) {
        case 0:
            childSet = &S1;
            break;
        case 1:
            childSet = &S2;
            break;
        case 2:
            childSet = &S3;
            break;
        case 3:
            childSet = &S4;
            break;
        }

        if (!childSet->empty()) {
            root->children[i] = new Node(0);
            insertNode(root->children[i], *childSet, level + 1, height, subSets);
        }
    }
}

// Function to print the tree
void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    cout << "Level: " << level << ", Value: " << root->value << endl;

    for (int i = 0; i < 4; i++) {
        printTree(root->children[i], level + 1);
    }
}

int main() {
    vector<int> S;
    S.push_back(22);
    S.push_back(44);
    S.push_back(75);
    S.push_back(90);
    S.push_back(92);
    S.push_back(99);
    S.push_back(110);
    S.push_back(112);
    S.push_back(125);
    S.push_back(130);
    S.push_back(131);
    int height = 0;
    vector<vector<int> > subSets;

    Node* root = new Node(0);
    insertNode(root, S, 0, height, subSets);

    for (int i = 0; i < 4; i++) {
        sort(subSets[i].begin(), subSets[i].end());
    }

    for (int i = 0; i < 4; i++) {
        cout << "S" << i + 1 << ": ";

        for (int j = 0; j < subSets[i].size(); j++) {
            cout << subSets[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

