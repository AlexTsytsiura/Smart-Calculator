#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#include "Calculator.h"
#include <vector>

using namespace std;

class Buffer{
  protected:
    vector<PNode>::iterator it;
    vector<PNode>::iterator iteratorEnd;
  public:
    Buffer(vector<PNode>*);
    PNode getNext();
};

#endif // BUFFER_H_INCLUDED
