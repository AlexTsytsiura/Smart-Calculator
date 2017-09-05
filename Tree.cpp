#include <math.h>
#include "Tree.h"

Tree::Tree(PNode p){
  root = p;
}

PNode Tree::isNE(PNode p){
  if( p->pLeft == NULL && p->pRight == NULL) return NULL;
  if( p->pLeft->tVar == NE && p->pRight->tVar != NE )
    return p->pRight;
  if( p->pLeft->tVar != NE && p->pRight->tVar == NE )
    return p->pLeft;
  return NULL;
}

double Tree::calc(PNode p){
  if( isNE(p) != NULL )
    return calc(isNE(p));
  switch(p->tVar){
    case NAME:{
      return HashTable::instance().putLex(p->var)->value;
      break;
    }
    case NUM:{
      return p->number;
      break;
    }
    case PLUS:{
      return calc(p->pLeft)+calc(p->pRight);
      break;
    }
    case MINUS:{
      return calc(p->pLeft)-calc(p->pRight);
      break;
    }
    case MULTIPLY:{
      return calc(p->pLeft)*calc(p->pRight);
      break;
    }
    case DIV:{
      return calc(p->pLeft)/calc(p->pRight);
      break;
    }
    case MOD:{
      return fmod(calc(p->pLeft),calc(p->pRight));
      break;
    }
    case LOGIC_AND:{
      return (int)calc(p->pLeft)&(int)calc(p->pRight);
      break;
    }
    case LOGIC_OR:{
      return (int)calc(p->pLeft)|(int)calc(p->pRight);
      break;
    }
    case POWER:{
      return pow(calc(p->pLeft),calc(p->pRight));
      break;
    }
    case LRB:{
      return calc(p->pLeft);
      break;
    }
    case COS:{
      return cos( calc(p->pLeft) );
      break;
    }
    case SIN:{
      return sin( calc(p->pLeft) );
      break;
    }
    default:
      return 0;
  }
  return 0;
}

void Tree::convert(PNode p, std::vector<PNode> *ArrOfNode){
  if( p->tVar == NAME ){
    if( HashTable::instance().putLex( p->var )->tree == NULL ){
        PNode newNode = new Node();
        newNode->pLeft = newNode->pRight = NULL;
        newNode->tVar = NUM;
        newNode->number = 0;
        ArrOfNode->push_back(newNode);
        return;
    }
    if( HashTable::instance().putLex( p->var )->recursion == false ){
        PNode newNode = new Node();
        newNode->pLeft = newNode->pRight = NULL;
        newNode->number = HashTable::instance().putLex( p->var )->value;
        newNode->tVar = NUM;
        ArrOfNode->push_back(newNode);
        return;
    }
    HashTable::instance().putLex( p->var )->recursion = false;
    convert( HashTable::instance().putLex( p->var )->tree, ArrOfNode );
    HashTable::instance().putLex( p->var )->recursion = true;
    HashTable::instance().putLex( p->var )->value = calc(HashTable::instance().putLex( p->var )->tree);
    return;
  }
  if(!p->pLeft && !p->pRight){
    ArrOfNode->push_back(p);
    return;
  }
  if(p->pLeft) convert(p->pLeft, ArrOfNode);
  if(p->pRight) convert(p->pRight, ArrOfNode);
  ArrOfNode->push_back(p);
  return;
}

Buffer* Tree::ParsingToBuffer(){
  std::vector<PNode> *ArrOfNode = new std::vector<PNode>();
  convert(root, ArrOfNode);
  return new Buffer(ArrOfNode);
}
