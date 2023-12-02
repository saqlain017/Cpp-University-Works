#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};

Node* start = NULL;


void insert(int b) {
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->ID = b;
	temp->next = NULL;
	if (start == NULL) {   //for start
		start = temp;
		start->previous = NULL;
	}
	else {
		Node* current = start;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
	}
}

void print() {
	// print same hai
	Node* ptr = start;
	if (ptr == NULL) cout << "empty" << endl;
	while (ptr != NULL) {
		cout << ptr->ID << endl;
		ptr = ptr->next;
	}
}

void printreverse() {

	if (start == NULL) {
		cout << "list is empty" << endl;
		return;
	}
	Node* end = start;
	if (end == NULL) cout << "empty" << endl;
	while (end->next != NULL) { // ye full end tak jayega  jab tak next null na hojaye
		end = end->next;
	}
	while (end != NULL) { // ye reverse mai print karega starting from the last element till the first element
		cout << end->ID << endl;
		end = end->previous;
	}
}

void Delete() {
	if (start == NULL) {
		cout << "list is empty" << endl;
		return;
	}
	int todel;
	cout << "enter the id to be deleted:" << endl;
	cin >> todel;
	Node* curr = start;
	if (todel == start->ID) {    // for deleting first value
		start = start->next;
		free(curr);
		cout << "start deleted" << endl;
	}
	else {
		Node* prev = start;
		Node* curr = start->next;
		while (curr != NULL) {
			if (todel == curr->ID && curr->next == NULL) {  // for deleting last value
				prev->next = curr->next;  // last value ko delete karne ka alag se banaya hai because iske previous ko maintain karne ki zaroorat nhi
				free(curr);
				cout << "deleted the last value" << endl;
				break;
			}
			else if (todel == curr->ID && curr->next != NULL) { //for deleting middle values
				prev->next = curr->next;
				free(curr);
				curr = prev->next;
				curr->previous = prev;
				cout << "deleted the value" << endl;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}
}

void DeleteAll() {
	if (start == NULL) {
		cout << "list is empty" << endl;
		return;
	}
	Node* curr = start;
	Node* nextn = start->next;
	while (curr != NULL) {
		cout << "deleting:" << curr->ID << endl;
		free(curr);
		if (nextn == NULL)break;
		curr = nextn;
		nextn = nextn->next;

	}
	start = NULL;
}

int main() {
	int node = 0, b = 0;
	while (node != 6) {
		cout << "press 1 for insert,2 for print, 3 for delete,4 for delete all, 5 for reverse print and 6 for exit" << endl;
		cin >> node;
		if (node == 1) {
			cin >> b;
			insert(b);
		}
		if (node == 2) {
			print();
		}
		if (node == 3) {
			Delete();
		}
		if (node == 4) {
			DeleteAll();
		}
		if (node == 5)printreverse();
	}
}
