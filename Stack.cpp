#include <iostream>
#include <stdlib.h>
using namespace std;

struct Data{
	int value;
	struct Data* next;
}* top = NULL;

void insert_Top(){
	struct Data* temp = (struct Data*)malloc(sizeof(struct Data));
   	cout << "Enter Value: ";
    cin >> temp -> value;
    temp->next = NULL;
    if(top == NULL){
    	top = temp;
	}else{
		struct Data* current = top;
		while (current -> next != NULL){
			current = current -> next;
		}
		current -> next = temp;
	}
}

int main(){
	while(true){
		int choice;
		cout << "Enter 1: Insert, 2: Exit";
		cin >> choice;
		switch(choice){
			case 1:
				insert_Top();
				break;
			case 2:
				return -1;
			default:
				cout << "Invalid choice";
				break;
		}
	}
	return 0;
}
