#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED

enum TypeLex {
  NUM,
  PLUS      = '+',
  MINUS     = '-',
  DIV       = '/',
  POWER     = '^',
  LOGIC_AND = '&',
  LOGIC_OR  = '|',
  MOD       = '%',
  MULTIPLY  = '*',
  RESULT    = '=',
  LRB       = '(',
  RRB       = ')',
  LSB       = '[',
  RSB       = ']',
  SIN       = 's',
  COS       = 'c',
  NAME,
  NE
};

#endif // LEX_H_INCLUDED
