///////////////////////////////////////
// Workfile    : ArithExprModule.h
// Author      : Matthias Schett
// Date        : 14-03-2013
// Description : Binary Search Tree
// Remarks     : -
// Revision    : 0
///////////////////////////////////////
#include "scanner.h"

// Pruefung auf Terminalen Anfang fuer den AddOp
bool isTbAddOp(scanner &scan);

// Pruefung auf Terminalen Anfang fuer MulOp
bool isTbMulOp(scanner &scan);

// Pruefung auf Terminalen Anfang fuer Expression
bool isTbExpression(scanner &scan);

// Pruefung auf Terminalen Anfang fuer Term
bool isTbTerm(scanner &scan);

// Pruefung auf Terminalen Anfang fuer Factor
bool isTbFactor(scanner &scan);

// Scannt den Additionsoperator und liefert das Vorzeichen
int scanAddOp(scanner &scan);

// Erkenne einen Faktor
int scanFactor(scanner &scan);

//Erkennen einen Term
int scanTerm(scanner &scan);

// Erkenne einen Arithmetischen Ausdruck
int scanExpression(scanner &scan);