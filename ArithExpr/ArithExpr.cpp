///////////////////////////////////////
// Workfile    : ArithExpr.cpp
// Author      : Matthias Schett
// Date        : 14-03-2013
// Description : Binary Search Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////
#include <iostream>
#include <fstream>
#include "scanner.h"
#include "ArithExprModule.h"

int main (){

    std::ifstream file("Input.txt");
    scanner scan(file);

    while(!scan.eof()){
        std::cout << scanExpression(scan) << std::endl;
    }
    std::cin.get();
    return 0;
}