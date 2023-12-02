#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
	int ID;
	int marks;
	struct Node* next;
};
struct Node* start = NULL;
void insertNode() {
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
   cout << "Enter ID: ";
    cin >> temp -> ID;
    cout << "Enter marks: ";
    cin >> temp -> marks;
    temp->next = NULL;
    if(start == NULL){
    	start = temp;
	}else{
		struct Node* current = start;
		while (current -> next != NULL){
			current = current -> next;
		}
		current -> next = temp;
	}
}
void deleteAll(){
	struct Node* current = start;
	if(current == NULL){
		cout << "Linked List is empty";
	}else{
		struct Node* temporary = current;
		while(current != NULL){
			temporary = current;
			current = current -> next;
			free(temporary);
		}
	}	
}
void searchNode(){
	int toSearchID;
	cout << "Enter to search ID";
	cin >> toSearchID;
	struct Node* current = start;
	while (current!=NULL){
		if(toSearchID==current->ID){
			cout << "Node found: ID = " << current -> ID<< ", Marks = " << current->marks << "\n";
			return;
		}
		current = current -> next;
	}
	if (current == NULL){
		cout << "Node not found .\n";
	}
}
void printNode(){
	struct Node* current = start;
	if(current == NULL){
		cout << "Linked List is empty";
	}else{
		while(current != NULL){
			cout << "ID : " << current ->ID << "\n Marks : " << current-> marks << "\n";
			current = current ->next;
		}
	}
}
void deleteNode(){
	int toDeleteID;
	cout << "Enter to Delete ID : ";
	cin >> toDeleteID;
	struct Node* current = start;
	if(toDeleteID == start->ID){
		start = start->next;
		free(current);
	}else{
		struct Node* prev = start;
		current = start->next;
	while (current!=NULL){
		if(toDeleteID==current->ID){
                prev->next = current->next;
                free(current);
                break;
            }
        prev = current;
        current = current -> next;
		}
	if (current == NULL){
		cout << "Node not found. \n";
	}
	}
}

int main() {
    while (true) {
        int choice;
        cout << "Enter your choice (1: Insert, 2: Search, 3: Delete, 4: Print, 5: Delete All, 6: Exit): ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertNode();
                break;
            case 2:
                searchNode();
                break;
            case 3:
                deleteNode();
                break;
            case 4:
            	printNode();
            	break;
            case 5:
            	deleteAll();
				break;
			case 6:
                cout << "Exiting...\n";
                return 0;				
            default:
                cout << "Invalid choice. Please enter node valid choice.\n";
                break;
        }
    }

    return 0;
}
