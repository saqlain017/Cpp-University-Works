#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char c) {
    if (c == '=')
    {
        return 1;
    }
    if (c == '|') //or
    {
        return 2;
    }
    if (c == '&') // and
    {
        return 3;
    }
    if (c == '\'' || c == '!') // == is represented as '' and != as '!'
    {
        return 4;
    }
    if (c == '<' || c == '>' || c == ',' || c == '.') //<= is represented as ',' and >= as '.'
    {
        return 5;
    }
    if (c == '+' || c == '-')
    {
        return 6;
    }
    if (c == '*' || c == '/')
    {
        return 7;
    }
    if (c == '^')
    {
        return 8;
    }
    return 0;
}

void InfixToPostfix(string w) {
    stack<char> stack3; //stack for operator
    string postfix = ""; // to store postfix 
    // as String refers to node sequence of characters represented as node single data type and acts like an array
    for (size_t i = 0; i < w.length(); i++) {
        char character = w[i];
        if (isalnum(character)) {// for both alphabets and  number returns true if yes
            postfix += character;
        }
        else if (character == '(') {
            stack3.push(character);
        }
        else if (character == ')') {
            while (!stack3.empty() && stack3.top() != '(') {
                postfix += stack3.top();
                stack3.pop();
            }
            // this if-else checks if there is an opening bracket '(' or not because we encountered node closing bracket ')'
            if (!stack3.empty() && stack3.top() == '(') {
                stack3.pop(); // Pop the '('
            }
            else
            {
                cout << "invalid infix expression. \n";
                return;
            }
        }
        else
        {
            // checks precedence of the current char with the top of stack
            while (!stack3.empty() && precedence(character) <= precedence(stack3.top())) {
                postfix += stack3.top();
                stack3.pop();
            }
            stack3.push(character);
        }
    }

    while (!stack3.empty()) {
        postfix += stack3.top();
        stack3.pop();
    }
    cout << "Postfix is : " << postfix << "\n"; //it will print postfix conversion
}

int main() {
    int choice;
    while (true)
    { 
        cout << "(1: Infix to Postfix, 2: Exit): ";
        cin >> choice;
        if (choice == 1)
        {
            string exp;
            cout << "Infix to postfix is selected." << "\n" << "Enter your Infix expression: ";
            cin >> exp;
            InfixToPostfix(exp);
        }
        else if (choice == 2)
        {
            cout << "Exiting";
            break;
        }
        else {
            cout << "Wrong input !!" << endl;
        }
    }
    return 0;
}

