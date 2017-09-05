#include "RPN.h"
#include <math.h>
#include <stack>

double RPN::compute(Buffer* buffer){
  std::stack<double> Stack;
  PNode p;
  while( p = buffer->getNext() ){
    if( p->tVar == NUM ){
      Stack.push( p->number );
    }
    else {
      double p1 = Stack.top();
      Stack.pop();
      double p2 = Stack.top();
      Stack.pop();

      switch( p->tVar ){
        case PLUS:{
          Stack.push(p1+p2);
          break;
        }
        case MINUS:{
          Stack.push(p2-p1);
          break;
        }
        case MULTIPLY:{
          Stack.push(p1*p2);
          break;
        }
        case DIV:{
          Stack.push(p2/p1);
          break;
        }
        case MOD:{
          Stack.push( fmod( p2, p1 ) );
          break;
        }
        case LOGIC_AND:{
          Stack.push((int)p2&(int)p1);
          break;
        }
        case LOGIC_OR:{
          Stack.push((int)p2|(int)p1);
          break;
        }
        case POWER:{
          Stack.push( pow( p2, p1 ) );
          break;
        }
        case COS:{
          Stack.push( cos(p2) );
          break;
        }
        case SIN:{
          Stack.push( sin(p2) );
          break;
        }
        default:
          Stack.push(0);
      }
    }
  }
  return Stack.empty() ? 0 : Stack.top();
}
