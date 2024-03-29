#include <iostream>
#include <fstream>
#include "binaryTree.h"

using namespace std;

int main() {
    ifstream infile;
    string filename;

    // Prompt user for input file until a valid one is provided
    while (true) {
        cout << "Enter LISP file (All those parenthesis...): ";
        cin >> filename;
        infile.open(filename);

        if (!infile) {
            cerr << "Unable to open file. Please try again." << endl;
            continue;
        }

        int targetSum;
        while (infile >> targetSum) {
            BinaryTree<int> tree;
            myStack<int> path;

            // Use public member functions to operate on the binary tree
            binTreeNode<int>* root = nullptr;  // Declare a pointer to store the root
            tree.readLISP(root, infile);  // Read LISP expression into the tree
            cout << "Path in tree ";

            if (tree.evaluate(root, 0, targetSum, path)) {  // Evaluate the tree
                cout << "exists" << endl;
                cout << path.top();
                path.pop();
                while (!path.isEmpty()) {
                    cout << " + " << path.top();
                    path.pop();
                }
                cout << " = " << targetSum << endl;
            } else {
                cout << "does not exist" << endl;
            }

            tree.destroyTree(root);  // Destroy the tree
        }

        infile.close();
        break; // Exit loop after processing the input file
    }

    return 0;
}
