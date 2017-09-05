#ifndef RPN_H_INCLUDED
#define RPN_H_INCLUDED

#include "Calculator.h"

class Buffer;

class RPN{
  public:
    double compute(Buffer*);
};


#endif // RPN_H_INCLUDED
