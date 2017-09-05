#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include "Lex.h"

typedef struct Node{
  TypeLex tVar;
  union {
    double number;
    char* var;
  };
  Node* pLeft;
  Node* pRight;
} *PNode;

#include "HashTable.h"
#include "Stream.h"
#include "RPN.h"
#include "Buffer.h"
#include "Tree.h"
#include "BuilderTree.h"

#endif // FILE_H_INCLUDED
