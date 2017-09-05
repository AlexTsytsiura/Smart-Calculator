#include "Stream.h"

TypeLex Stream::CurrLex(){
  return currLex;
}

double Stream::GetNum(){
  return number;
}

char* Stream::GetVar(){
  return var;
}

TypeLex Stream::GetLex(){
  char c;
  do{
    if(!input.get(c)) return currLex = NE;
  }
  while (c!='\n' && isspace(c)) ;
  switch (c){
    case '+':
    case '-':
    case '^':
    case '(':
    case ')':
    case '[':
    case ']':
    case '*':
    case '%':
    case '/':
    case '|':
    case '=':
    case '&':{
      return currLex = (TypeLex)c;
    }
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':{
      input.putback(c);;
      input >> number;
      return currLex = NUM;
    }
    default:
      if( isalpha(c) ){
        char *p = var;
        memset(p, '\0' ,sizeof(char)*VAR_LENGTH);
        p[0] = c;
        int i = 1;
        while( input.get(c) && isalnum(c) ){
          p[i++] = c;
        }
        if( !strcmp("exit", p) ){
          exit(0);
        }
        if( !strcmp("sin", p) ){
          return currLex = SIN;
        }
        if( !strcmp("cos", p) ){
          return currLex = COS;
        }
        input.putback(c);
        return currLex = NAME;
      }
      return currLex = NE;
  }
}

bool Stream::isRead(){
  return (bool)input;
}
