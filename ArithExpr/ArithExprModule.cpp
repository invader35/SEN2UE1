///////////////////////////////////////
// Workfile    : ArithExprModule.cpp
// Author      : Matthias Schett
// Date        : 14-03-2013
// Description : Binary Search Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////
#include "ArithExprModule.h"
#include <iostream>

void doErrorHandling(std::string errorMessage){
    std::cout << "Es wurde ein ungueltiges Zeichen in der Eingabe erkannt. Ergebnis wird trotz Fehlers ausgegeben: " << errorMessage << " ";
}

bool isTbAddOp(scanner &scan){
    return scan.symbol_is_plus() || scan.symbol_is_minus();
}

bool isTbMulOp(scanner &scan){
    return scan.symbol_is_multiply() || scan.symbol_is_division();
}

bool isTbExpression(scanner &scan){
    return isTbAddOp(scan) || isTbTerm(scan);
}

bool isTbTerm(scanner &scan){
    return isTbFactor(scan);
}

bool isTbFactor(scanner &scan){
    return scan.symbol_is_integer() || scan.symbol_is_lpar();
}

int scanAddOp(scanner &scan){
    int sign = 0;

    if(scan.symbol_is_plus()){
        sign = +1;
    } else if(scan.symbol_is_minus()){
        sign = -1;
    } else {
        doErrorHandling("Es wurde ein + oder ein - erwartet");
    }

    scan.next_symbol();

    return sign;
}

int scanFactor(scanner &scan){
    int val = 0;

    if(scan.symbol_is_integer()){
        val = scan.get_integer();
    } else if(isTbExpression(scan)){
        if(scan.symbol_is_lpar()){
            scan.next_symbol();
        }
        val = scanExpression(scan);
    } else {
        doErrorHandling("Es wurde ein weiterer Ausdruck oder eine Zahl erwartet!");
    }

    scan.next_symbol();

    return val;
}

int scanTerm(scanner &scan){

    int val = scanFactor(scan);

    while(isTbMulOp(scan)){
        if(scan.symbol_is_multiply()){
            scan.next_symbol();
            val *= scanFactor(scan);
        } else if(scan.symbol_is_division()){
            scan.next_symbol();
            int factor = scanFactor(scan);
            if(factor != 0){
                val /= factor;
            } else {
                doErrorHandling("Division durch 0 ist nicht erlaubt");
            }
        } else {
            doErrorHandling("Es wurde ein * oder / erwartet!");
        }

    }
    
    return val;
}

int scanExpression(scanner &scan){

    int sign = 1;
    int value = 0;

    if(isTbAddOp(scan)){
        sign = scanAddOp(scan);
    }

    value = sign * scanTerm(scan);

    while(isTbAddOp(scan)){
        sign = scanAddOp(scan);
        value += sign * scanTerm(scan);
    }
    
    return value;
}