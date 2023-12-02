#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int ID;
    int marks;
    struct Node* next;
};

struct Node* start = NULL;

void insertNode() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    cout << "Enter ID: ";
    cin >> temp->ID;
    cout << "Enter marks: ";
    cin >> temp->marks;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
        temp->next = start; //if null so insert and point self
    } else {
        struct Node* current = start;
        while (current->next != start) {
            current = current->next;
        }
        current->next = temp;
        temp->next = start; //set last element to point start
    }
}

void deleteAll() {
    struct Node* current = start;
    if (current == NULL) {
        cout << "Linked List is empty";
    } else {
        struct Node* temporary;

        while (current->next != start) {
            temporary = current;
            current = current->next;
            free(temporary);
        }
        free(current); // Free the last node
        start = NULL;
    }
}

void searchNode() {
    int toSearchID;
    cout << "Enter ID to search: ";
    cin >> toSearchID;
    struct Node* current = start;

    while (current != NULL) {
        if (toSearchID == current->ID) {
            cout << "Node found: ID = " << current->ID << ", Marks = " << current->marks << "\n";
            return;
        }
        current = current->next;
        if (current == start) {
            // We have gone through the entire circular list
            break;
        }
    }

    cout << "Node not found.\n";
}

void printNode() {
    struct Node* current = start;
    if (current == NULL) {
        cout << "Linked List is empty";
    } else {
        while (current != NULL) {
            cout << "ID: " << current->ID << "\nMarks: " << current->marks << "\n";
            current = current->next;
            if (current == start) {
                // We have gone through the entire circular list
                break;
            }
        }
    }
}

void deleteNode() {
    int toDeleteID;
    cout << "Enter ID to delete: ";
    cin >> toDeleteID;

    if (start == NULL) {
        cout << "Node not found.\n";
        return;
    }

    struct Node* current = start;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (toDeleteID == current->ID) {
            if (current == start) {
                start = current->next;
            }
            if (prev != NULL) {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
        if (current == start) {
            // We have gone through the entire circular list
            break;
        }
    }

    cout << "Node not found.\n";
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

