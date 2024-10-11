#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath> // For sqrt function
using namespace std;

struct Stack {
    static const int MAX_SIZE = 100;
    int top;
    int data[MAX_SIZE];
};

static void initStack(Stack &s) {
    s.top = -1;
}

static bool isEmpty(const Stack& s) {
    return s.top == -1;
}

static bool isFull(const Stack& s) {
    return s.top + 1 == s.MAX_SIZE;
}

static void push(Stack &s, int item) {
    if (isFull(s)) {
        cout << "Full stack; Cannot push " << item << endl;
    } else {
        s.data[++(s.top)] = item;
        cout << item << " pushed on top of the stack." << endl;
    }
}

static int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Empty stack; nothing to pop." << endl;
        return -1;
    } else {
        int item = s.data[(s.top)--];
        return item;
    }
}

static int peek(const Stack &s) {
    if (isEmpty(s)) {
        cerr << "Empty stack." << endl;
        return -1;
    } else {
        return s.data[(s.top)];
    }
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

int doOperation(int operand1, int operand2, char op) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                cout << "Error: Division by zero\n";
                exit(1);
            }
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        case '%':
            return operand1 % operand2;
        default:
            cerr << "Error: Unknown operator\n";
            exit(1);
    }
}

int evaluate(const string& expression) {
    Stack operands;
    initStack(operands);
    for (char c : expression) {
        if (isdigit(c)) {
            push(operands, c - '0'); // Convert char to int
        } else if (c != ' ') { // Ignore whitespace
            if (!isOperator(c)) {
                cout << "Error: Invalid character in expression\n";
                exit(1);
            }
            if (operands.top < 1) {
                cout << "Error: Not enough operands for operator\n";
                exit(1);
            }
            int operand2 = pop(operands);
            int operand1 = pop(operands);
            int result = doOperation(operand1, operand2, c);
            push(operands, result);
        }
    }
    if (operands.top != 0) {
        cout << "Error: Invalid expression\n";
        exit(1);
    }
    return pop(operands);
}

int main() {
    string expression;
    cout << "Enter postfix expression: ";
    getline(cin, expression);
    int result = evaluate(expression);
    cout << "Result: " << result << endl;
    return 0;
}
