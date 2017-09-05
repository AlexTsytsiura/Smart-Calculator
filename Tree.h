#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Calculator.h"
#include <vector>

class Tree{
  protected:
    PNode root;
    PNode isNE(PNode);
    double calc(PNode);
    void convert(PNode, std::vector<PNode> *);
  public:
    Tree(PNode);
    Buffer* ParsingToBuffer();
};

#endif // TREE_H_INCLUDED
