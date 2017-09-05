#ifndef BUILDERTREE_H_INCLUDED
#define BUILDERTREE_H_INCLUDED

#include "Calculator.h"

class Tree;
class Stream;

class BuildTree{
  protected:
    Stream *stream;
    PNode mkNode( TypeLex, PNode, PNode );
    PNode mkNode( double, PNode, PNode );
    PNode mkNode( char* , PNode, PNode );
    PNode mkTree();
    PNode mkLogic();
    PNode mkAdditive();
    PNode mkMultiplicative();
    PNode mkPower();
    PNode mkAtom();
  public:
    BuildTree( Stream* );
    Tree* makeTree();
};

#endif // BUILDERTREE_H_INCLUDED
