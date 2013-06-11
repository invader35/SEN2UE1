///////////////////////////////////////
// Workfile    : BinaryTree.h
// Author      : Matthias Schett
// Date        : 11-03-2013
// Description : Binary Search Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

struct TTreeNode {
    int Data;
    TTreeNode * pLeft;
    TTreeNode * pRight;
};

bool Contains (TTreeNode const * const pRoot, int const Data);
void Delete (TTreeNode * & pRoot, int const Data);
void Flush (TTreeNode * & pRoot);
int Height (TTreeNode const * const pRoot);
void InsertSorted (TTreeNode * & pRoot, int const Data);

void PrintInOrder (TTreeNode const * const pRoot);
void PrintPostOrder (TTreeNode const * const pRoot);
void PrintPreOrder (TTreeNode const * const pRoot);
void PrintTree (TTreeNode const * const pRoot, size_t const Indent);