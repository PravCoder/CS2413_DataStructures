#include <iostream>
#include <fstream>
// #include "myStack.h"
// #include "binaryTree.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

struct binTreeNode {
    int data;
    binTreeNode* left;
    binTreeNode* right;
}; 

// STACK CLASS
class myStack {
    public:
        myStack(); 
        ~myStack();
        void push(int);
        void pop();
        int top() const;
        bool isEmpty() const;
    private:
        struct Node {
            int data;
            Node* next;
        };
        Node* topPtr;
};

myStack::myStack() :  topPtr(nullptr) {}

myStack::~myStack() {
    while (!isEmpty()) {
        pop();
    }
}

void myStack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = topPtr;
    topPtr = newNode;
}

void myStack::pop() {
    if (!isEmpty()) {
        Node* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

int myStack::top() const {
    if (!isEmpty()) {
        return topPtr->data;
    } else {
        return 0;
    }
}

bool myStack::isEmpty() const {
    return topPtr == nullptr;
}

bool evaluate(binTreeNode* root, int runningSum, int targetSum, myStack& path) {
    if (root == nullptr) {
        return false;
    }

    runningSum += root->data;
    path.push(root->data);

    if (root->left == nullptr && root->right == nullptr) {
        if (runningSum == targetSum) {
            return true;
        }
    }

    if (evaluate(root->left, runningSum, targetSum, path) ||
        evaluate(root->right, runningSum, targetSum, path)) {
        return true;
    }

    path.pop();
    return false;
}


// BINARY TREE CLASS
class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();
        void readLISP(ifstream& infile);
        void destroyTree();
        bool evaluate(int targetSum, myStack& path);
    private:
        binTreeNode* root;
        void readLISPHelper(binTreeNode*& node, ifstream& infile);
        void destroyTreeHelper(binTreeNode* node);
};

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    destroyTree();
}

void BinaryTree::readLISP(ifstream& infile) {
    readLISPHelper(root, infile);
}

void BinaryTree::readLISPHelper(binTreeNode*& node, ifstream& infile) {
    char ch;
    infile >> ch;

    if (ch == '(') {
        node = new binTreeNode;
        infile >> node->data;
        readLISPHelper(node->left, infile);
        readLISPHelper(node->right, infile);
        infile >> ch; // Read closing parenthesis
    } else if (ch == ')') {
        node = nullptr;
    }
}

void BinaryTree::destroyTree() {
    destroyTreeHelper(root);
    root = nullptr;
}

void BinaryTree::destroyTreeHelper(binTreeNode* node) {
    if (node != nullptr) {
        destroyTreeHelper(node->left);
        destroyTreeHelper(node->right);
        delete node;
    }
}

bool BinaryTree::evaluate(binTreeNode* root, int runningSum, int targetSum, myStack& path) {
    if (root == nullptr) {
        return false;
    }

    runningSum += root->data;
    path.push(root->data);

    if (root->left == nullptr && root->right == nullptr) {
        if (runningSum == targetSum) {
            return true;
        }
    }

    if (evaluate(root->left, runningSum, targetSum, path) ||
        evaluate(root->right, runningSum, targetSum, path)) {
        return true;
    }

    path.pop();
    return false;
}


int main() {
    myStack stack;
    stack.push(5);
    stack.push(10);
    cout << "Top of the stack: " << stack.top() << endl;
    stack.pop();
    cout << "Top of the stack after pop: " << stack.top() << endl;

    binTreeNode* root = new binTreeNode;
    root->data = 5;
    root->left = new binTreeNode;
    root->left->data = 3;
    root->left->left = root->left->right = nullptr;
    root->right = new binTreeNode;
    root->right->data = 7;
    root->right->left = root->right->right = nullptr;

    cout << "Binary Tree evaluation result: " << evaluate(root, 0, 10, stack) << endl;

    return 0;
}
