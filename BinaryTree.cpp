#include <queue>
#include <iostream>
using namespace std;

struct HeapTree {
	string data;
	HeapTree* left;
	HeapTree* right;
	int height;
};

HeapTree* insert(HeapTree* root, string value) {
	if (root == NULL) {
		HeapTree* newNode = new HeapTree;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	queue <HeapTree*> q;
	q.push(root);

	while (!q.empty()) {
		HeapTree* current = q.front();
		q.pop();

		if (current->left == NULL) {
			current->left = new HeapTree;
			current->left->data = value;
			current->left->left = NULL;
			current->left->right = NULL;
			return root;
		}
		else if (current->right == NULL) {
			current->right = new HeapTree;
			current->right->data = value;
			current->right->left = NULL;
			current->right->right = NULL;
			return root;
		}
		else {
			q.push(current->left);
			q.push(current->right);
		}
	}

	return root;
}

void Mirror(HeapTree* a) {
	if (a == NULL) {
		return;
	}
	else {
		HeapTree* temp = new HeapTree;
		Mirror(a->left);
		Mirror(a->right);
		temp = a->left;
		a->left = a->right;
		a->right = temp;
	}
}

HeapTree* PreAndSuc(HeapTree* node, string d, HeapTree*& pre) {
	if (node == NULL) {
		return node;
	}
	if (node->data == d) {
		if (pre != NULL) {
			cout << pre->data << endl;
		}
		else {
			cout << "no predecessor exists!" << endl;
		}
		if (node->left != NULL) {
			cout << node->left->data << endl;
		}
		else {
			cout << "no left successor exists!" << endl;
		}
		if (node->right != NULL) {
			cout << node->right->data << endl;
		}
		else {
			cout << "no right successor exists!" << endl;
		}
		return node;
	}
	pre = node;
	node->left = PreAndSuc(node->left, d, pre);
	pre = node;
	node->right = PreAndSuc(node->right, d, pre);
	return node;
}

int heightDe(HeapTree* node, int height) {
	if (node != NULL) {
		height = heightDe(node->left, height);
		node->height = height;
		height = 0;
		height = heightDe(node->right, height);

		if (height >= node->height) {
			node->height = height;
			height++;
			return height;
		}
		return(node->height + 1);
	}
	return(height);
}

int level(HeapTree* node, string d) {
	if (node == NULL) {
		return -1;  // Assuming level is 0-based
	}

	if (node->data == d) {
		// If you want a 0-based level, return 0 here; otherwise, return 1.
		return 0;
	}

	int llevel = level(node->left, d);
	if (llevel >= 0) {
		return llevel + 1;  // Add 1 for the current node.
	}

	int rlevel = level(node->right, d);
	if (rlevel >= 0) {
		return rlevel + 1;  // Add 1 for the current node.
	}

	return -1;  // Data value not found in the tree.
}

HeapTree* height(HeapTree* node, string d) {
	if (node == NULL) {
		return node;
	}
	if (node->data == d) {
		cout << node->height << endl;
	}
	node->left=height(node->left, d);
	node->right=height(node->right, d);
	return node;
}

void printt(const string& prefix, HeapTree* parent, bool isLeft, bool isRoot) {
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
void printBT(HeapTree* node) {
	printt("", node, false, true);
}

void inorder(HeapTree* node) {
	if (node != NULL) {
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}
}

int main() {

	HeapTree* Root = NULL;
	int a;
	while (true) {
		cout << "(1: Insert, 2: print tree,3: inorder,4: mirror tree,5: predecessor and successor, 6:complete height,7: specific level, 8:specific height): ";
		cin >> a;
		if (a == 1) {
			string val;
			cout << "enter value: ";
			cin >> val;
			Root = insert(Root, val);
		}
		if (a == 2) {
			printBT(Root);
		}
		if (a == 3) {
			inorder(Root);
		}
		if (a == 4) {
			Mirror(Root);
		}
		if (a == 5) {
			string val;
			cout << "enter value: ";
			cin >> val;
			HeapTree* predecessor = NULL;
			HeapTree* successor = NULL;
			PreAndSuc(Root, val, predecessor);
		}
		if (a == 6) {
			int h = 0;
			heightDe(Root,h);
		}
		if (a == 7) {
			string val;
			cout << "enter value: ";
			cin >> val;
			int Level = level(Root, val);
			if (Level >= 0) {
				cout << "level of node with data '" << val << "': " << Level << endl;
			}
			else {
				cout << "Node with data '" << val << "' not found in the tree." << endl;
			}
		}
		if (a == 8) {
			string val;
			cout << "enter value: ";
			cin >> val;
			height(Root,val);
		}
	}
}
