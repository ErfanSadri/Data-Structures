//Erfan Sadri

#include <iostream>
#include <stack>
using namespace std;

struct VarValPair {
    char var;
    int v;
};

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* buildExpTree(const string& exp) {
    stack<Node*> stack;
    for (char c : exp) {
        if (!isOp(c))
            stack.push(new Node(c));
        else {
            Node* rightOp = stack.top();
            stack.pop();
            Node* leftOp = stack.top();
            stack.pop();
            Node* newNode = new Node(c);
            newNode->left = leftOp;
            newNode->right = rightOp;
            stack.push(newNode);
        }
    }
    return stack.top();
}

int evalWithVars(Node* root, const VarValPair vars[], int size) {
    if (!root)
        return 0;
    if (root->data >= '0' && root->data <= '9')
        return root->data - '0';
    for (int i = 0; i < size; ++i) {
        if (vars[i].var == root->data)
            return vars[i].v;
    }
    int lValue = evalWithVars(root->left, vars, size);
    int rValue = evalWithVars(root->right, vars, size);
    switch (root->data) {
        case '+': return lValue + rValue;
        case '-': return lValue - rValue;
        case '*': return lValue * rValue;
        case '/': return lValue / rValue;
        default: cerr << "Wrong op: " << root->data << endl;
    }
    return 0;
}

Node* copyExpTree(Node* root) {
    if (!root)
        return nullptr;
    Node* newNode = new Node(root->data);
    newNode->left = copyExpTree(root->left);
    newNode->right = copyExpTree(root->right);
    return newNode;
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    // Build an exp tree: ((x+y)*z)
    Node* root = new Node('*');
    root->left = new Node('+');
    root->left->left = new Node('x');
    root->left->right = new Node('y');
    root->right = new Node('z');

    // Define variables
    VarValPair vars[] = {
        {'x', 10},
        {'y', 20},
        {'z', 30}
    };
    int size = sizeof(vars) / sizeof(vars[0]);

    cout << "size = " << size << endl;

    // Evaluate exp tree with vars
    int result = evalWithVars(root, vars, size);
    cout << "Result with vars: " << result << endl;

    // Copy the tree
    Node* newTree = copyExpTree(root);

    // Evaluate the copied tree
    result = evalWithVars(newTree, vars, size);
    cout << "Result from new tree: " << result << endl;  // Expected: (x+y)*z = (10+20)*30 = 900

    // Clean up
    deleteTree(root);
    deleteTree(newTree);

    return 0;
}
