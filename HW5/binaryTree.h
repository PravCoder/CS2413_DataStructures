#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <fstream>
#include "myStack.h"

template <class Type>
struct binTreeNode {
    Type item;
    binTreeNode<Type> *left;
    binTreeNode<Type> *right;
};

template <class Type>
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    void readLISP(binTreeNode<Type> *&r, std::ifstream &infile);
    bool evaluate(binTreeNode<Type> *r, int runningSum, int targetSum, myStack<Type> &path);
    void destroyTree(binTreeNode<Type> *r);

private:
    void destroyHelper(binTreeNode<Type> *r);
};

template <class Type>
BinaryTree<Type>::BinaryTree() {
    root = nullptr;
}

template <class Type>
BinaryTree<Type>::~BinaryTree() {
    destroyTree(root);
}

template <class Type>
void BinaryTree<Type>::readLISP(binTreeNode<Type> *&r, std::ifstream &infile) {
    char ch;
    infile >> ch; // Read '('

    if (ch == '(') {
        r = new binTreeNode<Type>;
        infile >> r->item; // Read number

        readLISP(r->left, infile); // Read left subtree
        readLISP(r->right, infile); // Read right subtree

        infile >> ch; // Read ')'
    } else {
        r = nullptr;
    }
}

template <class Type>
bool BinaryTree<Type>::evaluate(binTreeNode<Type> *r, int runningSum, int targetSum, myStack<Type> &path) {
    if (r == nullptr)
        return false;

    runningSum += r->item;
    path.push(r->item);

    if (r->left == nullptr && r->right == nullptr) {
        if (runningSum == targetSum)
            return true;
    }

    bool leftResult = evaluate(r->left, runningSum, targetSum, path);
    bool rightResult = evaluate(r->right, runningSum, targetSum, path);

    if (!leftResult && !rightResult) {
        path.pop();
        return false;
    }

    return true;
}

template <class Type>
void BinaryTree<Type>::destroyTree(binTreeNode<Type> *r) {
    if (r != nullptr) {
        destroyHelper(r->left);
        destroyHelper(r->right);
        delete r;
    }
}

template <class Type>
void BinaryTree<Type>::destroyHelper(binTreeNode<Type> *r) {
    if (r != nullptr) {
        destroyHelper(r->left);
        destroyHelper(r->right);
        delete r;
    }
}

#endif // BINARY_TREE_H
