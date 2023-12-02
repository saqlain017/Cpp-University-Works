#include <iostream>
#include <stdlib.h>
using namespace std;

struct Course{
	int ID;
	struct Course* course;
	struct Course* students;
};

struct Course* start = NULL;


void insertCourse() {
    struct Course* temp = (struct Course*)malloc(sizeof(struct Course));
    cout << "Enter Course ID: ";
    cin >> temp -> ID;
    temp->course = NULL;
    temp->students = NULL;
    if(start == NULL){
    	start = temp;
	}else{
		struct Course* current = start;
		while (current -> course != NULL){
			current = current -> course;
		}
		current -> course = temp;
	}
}

void insertStudent(){
    struct Course* temp = (struct Course*)malloc(sizeof(struct Course));
    cout << "Enter Course ID you want to enroll in : ";
    cin >> temp -> ID;
    temp->course =NULL;
    temp->students =NULL;
    struct Course* current1 = start;
    while (current1 != NULL)
    {
        if (temp->ID == current1->ID)
        {
            struct Course* temp2 = (struct Course*)malloc(sizeof(struct Course));
            cout << "Enter Student ID: ";
            cin >> temp2 -> ID;
            temp2->course = NULL;
            temp2->students = NULL;
            struct Course* current = current1;
	        while (current -> students != NULL){
		        current = current -> students;
	        }
	        current -> students = temp2;
            cout << "Student enrolled." << endl;
            break;
        }
        
        current1 = current1->course;
    }
    if (current1 == NULL){
		cout << "Course not found " << endl;
	}
}

void printCourse(){
	struct Course* current = start;
	if(current == NULL){
		cout << "Linked List is empty";
	}else{
		while(current != NULL ){
			cout << "Course ID : " << current ->ID << endl;
            struct Course* StuCurr = current->students;
            while (StuCurr != NULL)
            {
                cout << "Student ID: " << StuCurr->ID << endl;
                StuCurr = StuCurr->students;
            }
            
			current = current ->course;
		}
	}
}

void delete_Student(int C_id, int S_id){
    struct Course* current1 = start;
    while (current1->course != NULL)
    {
        if (C_id == current1 -> ID)
        {
            break;
        }
        current1 = current1->course;
    }
    cout << current1->course;
    // while (current1->student != NULL)
    // {
    //     if (S_id == current1->ID)
    //     {
    //         break;
    //     }
        
    // }
    
    
    if (current1 == NULL)
    {
        cout << "Course not found!";
    }
    
}

void delete_Course(int C_id){
    Course* current = start;
    while (C_id != current->ID)
    {
        current = current->course;
    }
    cout << current->ID << endl;
    cout << "ok 1";
    Course* temp = current;
	while (current->students != NULL)
    {
        cout << "ok 2";
        while (current->students != NULL){
            current = current -> students;
            cout << current->ID << endl;
        }
        free(current);
        current = temp;
    } 
}


int main(){
	    while (true) {
        int choice;
        cout << "Enter your choice (1: Insert Course, 2: Insert Student, 3: Print, 4: Exit ): ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertCourse();
                break;
            case 2:
                insertStudent();
                break;
            case 3:
                printCourse();
                break;
            case 4:
                delete_Course(102);
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid choice.\n";
                break;
        }
    }
    return 0;
}