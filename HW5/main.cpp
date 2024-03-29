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

            tree.readLISP(tree.root, infile);
            cout << "Path in tree ";

            if (tree.evaluate(tree.root, 0, targetSum, path)) {
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

            tree.destroyTree(tree.root);
        }

        infile.close();
        break; // Exit loop after processing the input file
    }

    return 0;
}
