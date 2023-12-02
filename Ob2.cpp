#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

// Define a structure to represent a digit in a big integer
struct BigIntNode {
    int digit;
    struct BigIntNode* next;
};

// Initialize pointers for the two big integers and the result
struct BigIntNode* num1 = NULL;
struct BigIntNode* num2 = NULL;
struct BigIntNode* result = NULL;

// Function to insert a digit into a big integer
void insertDigit(struct BigIntNode** num, int digit) {
    struct BigIntNode* temp = (struct BigIntNode*)malloc(sizeof(struct BigIntNode));
    temp->digit = digit;
    temp->next = *num;
    *num = temp;
}

// Function to add two big integers
void addBigInts(struct BigIntNode* num1, struct BigIntNode* num2, struct BigIntNode** result) {
    int carry = 0;
    struct BigIntNode* current1 = num1;
    struct BigIntNode* current2 = num2;

    while (current1 != NULL || current2 != NULL) {
        int sum = carry;

        if (current1 != NULL) {
            sum += current1->digit;
            current1 = current1->next;
        }

        if (current2 != NULL) {
            sum += current2->digit;
            current2 = current2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        insertDigit(result, sum);
    }

    if (carry > 0) {
        insertDigit(result, carry);
    }
}

// Function to subtract two big integers
void subtractBigInts(struct BigIntNode* num1, struct BigIntNode* num2, struct BigIntNode** result) {
    int borrow = 0;
    int diff = 0;
    struct BigIntNode* current1 = num1;
    struct BigIntNode* current2 = num2;

    while (current1 != NULL || current2 != NULL) {
        int value1 = (current1 != NULL) ? current1->digit : 0;
        int value2 = (current2 != NULL) ? current2->digit : 0;

        diff = value1 - value2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        insertDigit(result, diff);

        if (current1 != NULL) {
            current1 = current1->next;
        }
        if (current2 != NULL) {
            current2 = current2->next;
        }
    }

    while (*result != NULL && (*result)->digit == 0) {
        struct BigIntNode* temp = *result;
        *result = (*result)->next;
        free(temp);
    }
}

// Function to multiply two big integers
void multiplyBigInts(struct BigIntNode* num1, struct BigIntNode* num2, struct BigIntNode** result) {
    *result = NULL;
    struct BigIntNode* current2 = num2;

    while (current2 != NULL) {
        struct BigIntNode* product = NULL;
        int carry = 0;
        int shift = 0;

        struct BigIntNode* current1 = num1;

        while (current1 != NULL) {
            int multiplication = carry;

            if (current1) {
                multiplication += current1->digit * current2->digit;
                current1 = current1->next;
            }

            carry = multiplication / 10;
            multiplication %= 10;

            insertDigit(&product, multiplication);
            shift++;
        }

        while (carry > 0) {
            insertDigit(&product, carry % 10);
            carry /= 10;
        }

        // Add trailing zeros for each shift
        for (int i = 0; i < shift; i++) {
            insertDigit(&product, 0);
        }

        addBigInts(*result, product, result);

        while (product != NULL) {
            struct BigIntNode* temp = product;
            product = product->next;
            free(temp);
        }

        current2 = current2->next;
    }
}

// Function to print a big integer
void printBigInt(struct BigIntNode* num) {
    struct BigIntNode* current = num;
    while (current != NULL) {
        cout << current->digit;
        current = current->next;
    }
    cout << endl;
}

void freeLinkedList(struct BigIntNode* num) {
    while (num != NULL) {
        struct BigIntNode* temp = num;
        num = num->next;
        free(temp);
    }
}

int main() {
    // Input the first big integer (one digit per line, -1 to end)
    cout << "Enter the first big integer (one digit per line, -1 to end):" << endl;
    int digit;
    while (true) {
        cin >> digit;
        if (digit == -1) {
            break;
        }
        insertDigit(&num1, digit);
    }

    // Input the second big integer (one digit per line, -1 to end)
    cout << "Enter the second big integer (one digit per line, -1 to end):" << endl;
    while (true) {
        cin >> digit;
        if (digit == -1) {
            break;
        }
        insertDigit(&num2, digit);
    }

    // Choose an operation (1: Addition, 2: Subtraction, 3: Multiplication, 4: Exit)
    cout << "Choose operation (1: Addition, 2: Subtraction, 3: Multiplication, 4: Exit): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            // Perform addition
            addBigInts(num1, num2, &result);
            cout << "Result of Addition: ";
            break;
        case 2:
            // Perform subtraction
            subtractBigInts(num1, num2, &result);
            cout << "Result of Subtraction: ";
            break;
        case 3:
            // Perform multiplication
            multiplyBigInts(num1, num2, &result);
            cout << "Result of Multiplication: ";
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid choice." << endl;
            return 1;
    }

    // Print the result
    printBigInt(result);

    // Free memory used by linked lists
    freeLinkedList(num1);
    freeLinkedList(num2);
    freeLinkedList(result);

    return 0;
}

