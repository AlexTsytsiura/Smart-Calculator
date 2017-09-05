#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

#include "Calculator.h"
#include <iostream>

const int VAR_LENGTH = 0xFF;

class Stream {
  protected:
    TypeLex currLex;
    double number;
    char var[VAR_LENGTH];
    std::istream &input;
  public:
    Stream(std::istream &stream):input(stream){}
    bool isRead();
    char* GetVar();
    double GetNum();
    TypeLex CurrLex();
    TypeLex GetLex();
};

#endif // STREAM_H_INCLUDED
