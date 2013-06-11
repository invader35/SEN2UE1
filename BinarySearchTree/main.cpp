///////////////////////////////////////
// Workfile    : main.cpp
// Author      : Matthias Schett
// Date        : 11-03-2013
// Description : Binary Search Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main(){


    TTreeNode *pTree = 0;

    InsertSorted(pTree, 5);
    InsertSorted(pTree, 3);
    InsertSorted(pTree, 4);
    InsertSorted(pTree, 2);
    InsertSorted(pTree, 7);
    InsertSorted(pTree, 6);
    InsertSorted(pTree, 8);

    cout << "Tree contains a 3 " << (Contains(pTree, 3) ? "yes" : "no") << endl; 

    cout << "Tree contains a 10 " << (Contains(pTree, 10) ? "yes" : "no") << endl;

    cout << "The height of the tree is " << Height(pTree) << endl << "Pre Order" << endl;

    PrintPreOrder(pTree);

    cout << endl << endl << "In Order" << endl;

    PrintInOrder(pTree);

    cout << endl << endl << "Post Order" << endl;

    PrintPostOrder(pTree);

    cout << endl << endl << "Print Tree" << endl;

    PrintTree(pTree, 3);

    // TODO: Delete And Print

    cout << endl << endl << "Delete and print Tree" << endl;

    Delete(pTree, 3);

    PrintInOrder(pTree);

    cout << endl << endl << "Flush and print Tree" << endl;
    Flush(pTree);

    PrintInOrder(pTree);

    cin.get();
    return 0;
}