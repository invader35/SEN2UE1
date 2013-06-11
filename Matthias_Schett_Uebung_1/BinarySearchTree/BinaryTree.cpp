///////////////////////////////////////
// Workfile    : BinaryTree.cpp
// Author      : Matthias Schett
// Date        : 11-03-2013
// Description : Binary Search Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include "BinaryTree.h"
#include <iostream>
#include <string>

// ---------- PRIVATE SECTION  --------

// Not in Header
TTreeNode * MakeNode (int const Data){
    TTreeNode* const pNewNode = new TTreeNode;
    
    pNewNode->Data = Data;
    pNewNode->pLeft = 0;
    pNewNode->pRight = 0;

    return pNewNode;
}

void PrintNodeData(TTreeNode const * const pNode){
    std::cout << "(" << pNode->Data << ") "; 
}


// ---------- PRIVATE SECTION  --------

bool Contains (TTreeNode const * const pRoot, int const Data){
    if(pRoot != 0){

        if( ( pRoot->Data == Data ) ){
            return true;
        } else {
            if(Data < pRoot->Data){
                return Contains(pRoot->pLeft, Data);
            } else {
                return Contains(pRoot->pRight, Data);
            }
        }
    }

    return false;
}

void Delete (TTreeNode * & pRoot, int const Data){
    TTreeNode *pNodeToDelete = 0;
    TTreeNode *pTemp = 0;
    TTreeNode *pPrevious = 0;

    if(pRoot != 0 && Contains(pRoot, Data)){
        if(Data < pRoot->Data){
            Delete(pRoot->pLeft, Data);
        } else if(Data > pRoot->Data){
            Delete(pRoot->pRight, Data);
        } else {
            pNodeToDelete = pRoot;
            if(pNodeToDelete->pRight == 0){
                pRoot = pNodeToDelete->pLeft;
            } else if(pNodeToDelete->pLeft == 0){
                pRoot = pNodeToDelete->pRight;
            } else {
                pTemp = pNodeToDelete->pLeft;

                while(pTemp->pRight != 0){
                    pPrevious = pTemp;
                    pTemp = pTemp->pRight;
                }

                pNodeToDelete->Data = pTemp->Data;

                if(pPrevious != 0){
                    pPrevious->pRight = pTemp->pLeft;
                } else {
                    pNodeToDelete->pLeft = pTemp->pLeft;
                }

                pNodeToDelete = pTemp;
            }

            delete pNodeToDelete;
            pNodeToDelete = 0;
        }
    } 
}

void Flush (TTreeNode * & pRoot){
    if (pRoot != 0)
    {
        Flush (pRoot->pLeft);
        Flush (pRoot->pRight);
        delete pRoot;
        pRoot = 0;
    }
}

int Height (TTreeNode const * const pRoot){
    if(pRoot == 0){
        return -1;
    }

    int lefth = Height(pRoot->pLeft);
    int righth = Height(pRoot->pRight);

    if(lefth > righth){
        return lefth + 1;
    } else {
        return righth + 1;
    }
}

void InsertSorted (TTreeNode * & pRoot, int const Data){
    if(pRoot != 0){
        if(Data < pRoot->Data){
            InsertSorted(pRoot->pLeft, Data);
        } else {
            InsertSorted(pRoot->pRight, Data);
        }
    } else {
        pRoot = MakeNode(Data);
    }
}

void PrintInOrder (TTreeNode const * const pRoot){
    if(pRoot != 0){
        if(pRoot->pLeft != 0){
            PrintInOrder(pRoot->pLeft);
        }

        PrintNodeData(pRoot);

        if(pRoot->pRight != 0){
            PrintInOrder(pRoot->pRight);
        }
    }
}

void PrintPostOrder (TTreeNode const * const pRoot){
    if(pRoot != 0){
        if(pRoot->pLeft != 0){
            PrintPostOrder(pRoot->pLeft);
        }

        if(pRoot->pRight != 0){
            PrintPostOrder(pRoot->pRight);
        }

        PrintNodeData(pRoot);
    }
}

void PrintPreOrder (TTreeNode const * const pRoot){
    if(pRoot != 0){
        PrintNodeData(pRoot);

        if(pRoot->pLeft != 0){
            PrintPreOrder(pRoot->pLeft);
        }

        if (pRoot->pRight != 0) {
            PrintPreOrder(pRoot->pRight);
        }
    }
}

void PrintTree (TTreeNode const * const pRoot, size_t const Indent){
    if(pRoot != 0){
        std::string s(Indent, ' ');
        PrintTree(pRoot->pRight, Indent + 3);
        std::cout << s;
        PrintNodeData(pRoot);
        std::cout << std::endl;
        PrintTree(pRoot->pLeft, Indent + 3);
    }

}
