#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>


using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void IntoPost(string infixExpression){
	    string postfixExpression = "";
    stack<char> operators;

    for (int i = 0; i < infixExpression.length(); i++) {
        if (isalnum(token)) {
            postfixExpression += token;
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfixExpression += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfixExpression += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
}

int main(){
	string infixExpression = "a+b";
	string postfixExpression = IntoPost(infixExpression);
	cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << postfixExpression << endl;
    return 0;
}
