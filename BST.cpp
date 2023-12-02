#include <iostream>
#include <stdlib.h>
using namespace std;

int c1 = 0; //Assigning depth top to bottom
int c2 = 0; // Subtracting to calculate from bottom to top

struct BSTNode{
	int data;
	int h;
	BSTNode* left;
	BSTNode* right;
};

void height(BSTNode* node){
//	Assigning height considering traversal
	if (node!=NULL){
		if (node->left != NULL){
//			If left exists
			c1++;
			height(node->left);
		}
		if (node->right != NULL){
//			If right exists
			c1++;
			height(node->right);
		}
		node -> h = c1-c2;
		c2++;
		cout << node->data << " : " << node -> h << endl;
	}
}

BSTNode* insert(BSTNode* node,int value){
	if(node == NULL){
		BSTNode* temp = (BSTNode*)malloc(sizeof(BSTNode));
		temp -> data = value;
		temp->left = NULL;
		temp-> right = NULL;
		temp -> h = 0;
		return temp;
	}
	if(value>node->data){
		node->right = insert(node->right,value);
	}else if(value<node->data){
		node->left = insert(node->left,value);
	}
	return node;
}
void search(BSTNode* node, int value){
	if(value == node->data){
		cout << "value found \n";
		return;
	}
	if(value > node->data){
		if(node->right==NULL){
			cout << "Value not found \n";
			return;
		}
		search(node->right,value);
	}else{
		if(node->left==NULL){
			cout << "Value not found \n";
			return;
		}
		search(node->left,value);
	}	
}

BSTNode* smallest(BSTNode* node){
	while(node->left != NULL){
		node= node->left;
	}
	return node;
}

BSTNode* deleteNode(BSTNode* node,int toDelete){
	if(node==NULL){
		cout << "Value Not Found \n";
		return node;
	}
	if(toDelete<node->data){
		node->left = deleteNode(node->left,toDelete);
	}else if(toDelete>node->data){
		node->right = deleteNode(node->right,toDelete);
	}else{
		if(node->left==NULL){
			BSTNode* temp = node->right;
			free(node);
			return temp;
		}else if(node->right==NULL){
			BSTNode* temp = node->left;
			free(node);
			return temp;
		}
		BSTNode* temp = smallest(node->right);
		node->data = temp->data;
		node->right = deleteNode(node->right,temp->data);	
	}
	return node;
}
void InOrder(BSTNode* node){
	if(node!=NULL){
		InOrder(node->left);
		cout << node->data << endl;
		InOrder(node->right);
	}
}
void PostOrder(BSTNode* node){
	if(node!=NULL){
		PostOrder(node->left);
		PostOrder(node->right);
		cout << node->data << endl;
	}
}
void PreOrder(BSTNode*node){
	if(node!=NULL){
		cout << node->data << endl;
		PreOrder(node->left);
		PreOrder(node->right);
	}
}
main(){
	BSTNode* Root= NULL;
	int Value;
	int choice;
	while (true){
		cout << "Choose 1: Insert, 2: Search, 3:InOrder, 4:PreOrder, 5:PostOrder, 6:Delete, 7:Height, 8:Exit \n";
		cin >>choice;
		switch(choice){
			case 1:
				cout << "Enter Value to perform operation : ";
				cin >> Value;				
				Root = insert(Root,Value);
				break;
			case 2:
				cout << "Enter Value to perform operation : ";
				cin >> Value;
				search(Root,Value);
				break;
			case 3:
				cout << "\n performing in order traversing \n";
				InOrder(Root);
				break;
			case 4:
				cout << "\n performing Pre Order traversing \n";
				PreOrder(Root);
				break;
			case 5:
				cout << "\n performing PostOrder order traversing \n";
				PostOrder(Root);
				break;
			case 6:
				cout << "Enter Value to perform operation : ";
				cin >> Value;
				deleteNode(Root,Value);
				break;
			case 7:
				cout << "Height function is called \n";
				height(Root);
				break;				
			case 8:
				cout << "Exiting \n ";
				return 0;
			default:
				cout << "Invalid Choice, choose again \n";
				break;	
		}
	}
}
