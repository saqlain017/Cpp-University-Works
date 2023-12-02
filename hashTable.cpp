#include <iostream>
#include <stdlib.h>
using namespace std;

int array[50];
int hashFn(int keyValue){
	return (keyValue % 50);
}
int insertValue(){
	cout << "Inserting Number \n";
	int keyValue;
	cout << "Insert Number you want to map \n";
	cin >> keyValue;
	int index = hashFn(keyValue);
	if (array[index]==-1){
		array[index] = keyValue;
		return 0;
	}
	for(int i = 0;i<50;i++){
		int newIndex = (index+1)%50;
		if (array[newIndex]==-1){
			array[newIndex] = keyValue;
			return 0;
		}
	}
	cout << "Array is full \n";
}

int searchValue(){
	cout << "Searching Number \n";
	int reqValue;
	int reqValuePlace;
	cout << "Enter Required Value: ";
	cin >> reqValue;
	int index = hashFn(reqValue);
	if (array[index]==reqValue){
		reqValuePlace = index;
		cout << "Value Found at: " << reqValuePlace << endl;		
		return index;
	}
	for (int i=0; i<50; i++){
		int newIndex = (index+1)%50;
		if(array[newIndex]==reqValue){
			reqValuePlace = newIndex;
			cout << "Value Found at: " << reqValuePlace << endl;		
			return newIndex;
		}
	}
	cout << "Value Not Found \n";
}

int main(){
	for (int i=0;i<50;i++){
		array[i]=-1;
	}
	while(true){
		int value;
		cout << "Enter Number 1:Insert, 2:Search , 3:Exit \n";
		cin >> value;
		switch(value){
			case 1:
				insertValue();
				break;
			case 2:
				searchValue();
				break;
			case 3:
				cout << "Exiting ....\n";
				return 0;
			default:
				cout << "Invalid value \n";
				break;
		}
	}
}
