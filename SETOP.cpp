#include <iostream>
#include <string>
using namespace std;

struct Node {
	int ID;
	Node* next;
};

Node* start = NULL;
Node* start1 = NULL;//for Ll
Node* start2 = NULL;
int c1 = 0;
int c2 = 0;

Node* insert(Node* start, int b) {
	Node* temp = new Node;
	temp->ID = b;
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
		return start;
	}
	else {
		Node* current = start;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
	return start;
}
void intersection(Node* start, Node* start1) {
	int* arr1 = new int[c1 + c2];
	int n = 0;
	Node* ss = start1;
	while (start != NULL) {

		while (start1 != NULL) {
			if (start->ID == start1->ID) {
				arr1[n] = start->ID;
				n = n + 1;
			}
			start1 = start1->next;
		}
		start = start->next;
		start1 = ss; //2nd list ka pointer shuru sai shuru hoga
	}
	int* arrFinal1 = new int[n];
	for (int s = 0; s < n; s++) {
		arrFinal1[s] = arr1[s];
	}
	for (int x = 0; x < n; x++) {
		cout << arrFinal1[x] << " ";
	}
}

void diffop(Node* start, Node* start1) {
	int* arr2 = new int[c1 + c2];
	int n = 0;
	Node* sss = start1;
	int check = 0;
	while (start != NULL) {

		while (start1 != NULL) {
			if (start->ID == start1->ID) {
				check = 1;
			}
				start1 = start1->next;
		}
		if (check == 0) {
			arr2[n] = start->ID;
			n = n + 1;
		}
		check = 0;
		start = start->next;
		start1 = sss;
	}
	int* arrFinal2 = new int[n];
	for (int s = 0; s < n; s++) {
		arrFinal2[s] = arr2[s];
	}
	for (int x = 0; x < n; x++) {
		cout << arrFinal2[x] << " ";
	}
}

void merop(Node* start, Node* start1) {
	int* arr = new int[c1 + c2];
	int n = 0;
	while (start != NULL) { //1st list copied to arr
		arr[n] = start->ID;
		start = start->next;
		n = n + 1;
	}
	while (start1 != NULL) { //2st list copied to arr
		arr[n] = start1->ID;
		start1 = start1->next;
		n = n + 1;
	}
	//sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}

		}
	}
	for (int z = 0; z < n; z++) {
		cout << arr[z] << " ";
	}

}

void cinput(Node* start,int d,int e) {
	Node* ssss = start;
	int same = 0;
	while (start != NULL) {
		if (start->ID==d) {
			same = same + 1;
		}
		start = start->next;
	}
	start = ssss;
	int* arr = new int[c1+same];
	int n = 0;
	while (start != NULL) { //1st list copied to arr
		arr[n] = start->ID;
		n = n + 1;
		if (start->ID == d) {
			arr[n] = e;
			n = n + 1;
		}
		start = start->next;
	}
	for (int z = 0; z < n; z++) {
		cout << arr[z] << " ";
	}

}

void Union(Node* start, Node* start1) {
	int* arr = new int[c1 + c2];
	int n = 0;
	while (start != NULL) { //1st list copied to arr
		arr[n] = start->ID;
		start = start->next;
		n = n + 1;
	}
	int check = 0;
	while (start1 != NULL) {
		check = 0;
		for (int i = 0; i < n; i++) {    //agr check=1, mtlb pehle se value exists to don't include in arr 
			if (arr[i] == start1->ID) {
				check = 1;
				break;
			}
		}
		if (check == 0) {              //agr check=0, mtlb pehle se value exists to don't include in arr 
			arr[n] = start1->ID;
			n = n + 1;
		}
		start1 = start1->next;
	}

	int* arrFinal = new int[n];
	for (int s = 0; s < n; s++) {
		arrFinal[s] = arr[s];
	}

	//sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arrFinal[j] > arrFinal[j + 1]) {
				swap(arrFinal[j], arrFinal[j + 1]);
			}

		}
	}

	for (int z = 0; z < n; z++) {
		cout << arrFinal[z] << " ";
	}
}

void Print(Node* nodePtr) {
	if (nodePtr == NULL) {
		cout << "it is empty" << endl;
	}
	while (nodePtr != NULL) {
		cout << nodePtr->ID << " ";
		nodePtr = nodePtr->next;
	}
}


int main() {

	int a = 0;
	int b = 0;
	while (a != 15) {
		cout << "1: insert list 1, 2: print list 1,3: insert list 2,4: print list 2,5:union" << endl;
		cin >> a;
		if (a == 1) {
			cout << "enter value in the 1st list: ";
			cin >> b;
			c1 = c1 + 1;
			start = insert(start, b);// Update nodePtr after modifying the list
		}
		if (a == 2) {
			Print(start);
			//			cout << "len: " << c1 << endl;
		}
		if (a == 3) {
			cout << "enter value in the 2nd list: ";
			cin >> b;
			c2 = c2 + 1;
			start1 = insert(start1, b);// Update nodePtr1 after modifying the list
		}
		if (a == 4) {
			Print(start1);
			//		cout << "len: " << c2 << endl;
		}
		if (a == 5) {
			Union(start, start1);
		}
		if (a == 6) {
			intersection(start, start1);
		}
		if (a == 7) {
			diffop(start, start1);
		}
		if (a == 8) {
			merop(start, start1);
		}
		if (a == 9) {
			int d;
			int e;
			cout << "enter value after insert";
			cin >> d;
			cout << "enter value before insert";
			cin >> e;

			cinput(start,d,e);
		}
	}
}
