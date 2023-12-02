#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

int precedence(char c) {
    if (c == '=') {
        return 1;
    }
    if (c == '|') {
        return 2;
    }
    if (c == '&') {
        return 3;
    }
    if (c == '_' || c == '!') {
        return 4;
    }
    if (c == '<' || c == '>' || c == ',' || c == '.') {
        return 5;
    }
    if (c == '+' || c == '-') {
        return 6;
    }
    if (c == '*' || c == '/') {
        return 7;
    }
    if (c == '^') {
        return 8;
    }
    return 0;
}

int values[26];

void value() {
    for (int i = 0; i < 26; i++) {
        char ch = char(i + 97);
        cout << "Enter value of " << ch << " : ";
        cin >> values[i];
    }
}

int AlphaIndex(char c) {
    int ascii = (int)c - 97;
    return ascii;
}

int val(int v1, int v2, string op) {
    int value;
    int temp;
    int node = v1;
    int b = v2;

    if (op == "+") {
        value = node + b;
        return value;
    }
    if (op == "-") {
        value = node - b;
        return value;
    }
    if (op == "*") {
        value = node * b;
        return value;
    }
    if (op == "/") {
        value = node / b;
        return value;
    }
    if (op == "&") {
        value = node && b;
        return value;
    }
    if (op == "|") {
        value = node || b;
        return value;
    }
    if (op == "!") {
        value = node != b;
        return value;
    }
    if (op == ">") {
        value = node > b;
        return value;
    }
    if (op == "<") {
        value = node < b;
        return value;
    }
    if (op == ",") {
        value = node <= b;
        return value;
    }
    if (op == ".") {
        value = node >= b;
        return value;
    }
    return 0;
}

int Evaluation(string exp) {
    stack<int> stack1;
    string ch = "";
    value(); //initialize values
    int valf; // final value
    int val1, val2; // two initial value to perform operation
    int temp;
    size_t size = exp.length();
    for (size_t i = 0; i < size; i++) {
        while (i < size && !isspace(exp[i])) {
            ch += exp[i];
            i++;
        }

        if (isalpha(ch[0])) {
            temp = values[AlphaIndex(ch[0])];
            stack1.push(temp);
            ch = "";
        } else if (isdigit(ch[0])) {
            temp = atoi(ch.c_str());  //It stands for string to an integer and if there is any number in integer it sets its corresponding values
            stack1.push(temp);
            ch = "";
        } else {
            val2 = stack1.top();
            stack1.pop();
            val1 = stack1.top();
            stack1.pop();
            valf = val(val1, val2, ch); // call value performing function
            stack1.push(valf);
            ch = "";
        }
    }

    cout << "Answer is: " << stack1.top() << endl;
    stack1.pop();
    return 0;
}

int main() {
    string exp;
    string post;

    cout << "Enter postfix: ";
    getline(cin, post); //allow spacing
    Evaluation(post);

    return 0;
}

