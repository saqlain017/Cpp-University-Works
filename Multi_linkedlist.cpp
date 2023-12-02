#include <iostream>
#include <stdlib.h>
using namespace std;

struct Course{
	int courseno;
	Course* next;
	struct Student* Sstart;
};
Course* Cstart = NULL;

struct Student{
	int SID;
	Student* next;
};

void InsertC(int b) {
	Course* temp = (Course*)malloc(sizeof(Course));
	temp->courseno = b;
	temp->next = NULL;
	temp->Sstart = NULL;
	if (Cstart == NULL) {
		Cstart = temp;
	}
	else {
		struct Course* current = Cstart;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = temp;
	}
}

void InsertS(int b) {
	int courseno;
	cout <<"Enter the course in which student wants to enroll: ";
	cin >> courseno;
	Course* current = Cstart;
	while (current != NULL) {
		if (current->courseno == courseno) {
			Student* temp = (Student*)malloc(sizeof(Student));
			temp->SID = b;
			temp->next = NULL;
			if (current->Sstart == NULL) {
				current->Sstart = temp;
				cout << "student is successfully enrolled in course" << endl;
				return;
			}
			else {
				struct Student* curren = current->Sstart;
				while (curren->next != NULL) {
					curren = curren->next;
				}
				curren->next = temp;
				cout << "student is successfully enrolled in course" << endl;
				return;
			}
		}
		current = current->next;
	}
	if (current == NULL)cout << "invalid course number" << endl;
	
}
void PrintCourse() {
	Course* ptr = Cstart;
	if (ptr == NULL) cout << "empty" << endl;
	cout << "The courses are listed below : \n";
	while (ptr != NULL) {
		cout << ptr->courseno << endl;
		ptr = ptr->next;
	}
}
void PrintStudent() {
	int courseno;
	cout << "Enter the course number: ";
	cin >> courseno;
	Course* current = Cstart;
	if (current == NULL) {
		cout << "course does not exist" << endl;
	}
	while (current != NULL) {
		if (current->courseno == courseno) {
			Student* ptr = current->Sstart;
			if (ptr == NULL) {
				cout << "empty" << endl;
				return;
			}
			while (ptr != NULL) {
				cout << ptr->SID << endl;
				ptr = ptr->next;
			}
			return;
		}
		current = current->next;
		if (current == NULL)cout << "course does not exist" << endl;
	}
}
void DeleteC(int b) {
    Course* current = Cstart;
    Course* previous = NULL;

    while (current != NULL) {
        if (current->courseno == b) {
            if (previous == NULL) {
                // The course to delete is the first one in the list.
                Cstart = current->next;
            } else {
                // The course to delete is not the first one.
                previous->next = current->next;
            }
            free(current);
            return; // Course found and deleted.
        }
        previous = current;
        current = current->next;
    }

    cout << "Course not found" << endl;
}
void DeleteS(int b) {
    int courseno;
    cout << "Enter the course no: ";
    cin >> courseno;
    Course* current = Cstart;
    while (current != NULL) {
        if (current->courseno == courseno) { // Course found
            Student* curr = current->Sstart;
            Student* prev = NULL;
            
            while (curr != NULL) {
                if (curr->SID == b) { // Student found
                    if (prev == NULL) {
                        // The student to delete is the first one in the list.
                        current->Sstart = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    free(curr);
                    cout << "Student deleted successfully" << endl;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
            cout << "Student not found in this course" << endl;
            return;
        }
        current = current->next;
    }
    cout << "Course not found" << endl;
}

int main(){
	int a = 0, c = 0;
	while (a != 6) {
		cout << "press 1 for inserting a course, 2 for enrolling a student, 3 for printing course list, 4 for printing student list of a course, 5 for deleting a student from a specific code, 6 for exit" << endl;
		cin >> a;
		if (a == 1) {
			cout << "Enter the course Number : ";
			cin >> c;
			InsertC(c);
		}
		if (a == 2) {
			cout << "Enter the Student with the required course Number : ";
			cin >> c;
			InsertS(c);
		}
		if (a == 3) {
			PrintCourse();
		}
		if (a == 4) {
			PrintStudent();
		}
		if (a == 5) {
			cout << "Enter student ID that you wants to delete : ";
			cin >> c;
			DeleteS(c);
		}
	}
}
