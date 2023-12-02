#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int hashFn(char c){
	int asciiValue = (int)c-65;
	return asciiValue;
};
struct StrNode{
	string Value;
	StrNode* next;
};

StrNode STable[26];

void AddStr(){
	string Name;
	cout << "Enter Name \n";
	cin >> Name;
	char a = Name[0];
	int index = hashFn(a);
	cout << "OK 1 \n";
	struct StrNode* temp = (struct StrNode*)malloc(sizeof(struct StrNode));
	cout << "OK 2 \n";
	temp->Value = Name;
	temp->next = NULL;
	if (STable[index].next==NULL){
		STable[index].next = temp;
	}
	else
	{
		StrNode* current = STable[index].next;
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = temp;
	}
};

void DelStr(){
	
};
void FindStr(){
	
};

int main() {
	for (int i=0; i<26;i++){
	STable[i].Value = char(65+i);
	STable[i].next = NULL;
}
    while (true) {
        int choice;
        cout << "Enter your choice (1: Insert, 2: Search, 3: Delete, 4: Exit): \n";
        cin >> choice;

        switch (choice) {
            case 1:
                AddStr();
                break;
            case 2:
                FindStr();
                break;
            case 3:
                for (int i=0;i<26;i++){
                	cout << STable[i].Value << endl;
				}
                break;
			case 4:
				cout << "Exiting ...\n";
				return 0;
            default:
                cout << "Invalid choice. Please enter a valid choice.\n";
                break;
        }
    }

    return 0;
}

