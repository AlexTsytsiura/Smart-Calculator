#include "BuilderTree.h"

BuildTree::BuildTree(Stream* input){
  stream = input;
}

PNode BuildTree::mkNode( TypeLex tVar, PNode left, PNode right ){
  PNode node = (PNode)malloc(sizeof(Node));
  node->tVar = tVar;
  node->pLeft = left;
  node->pRight = right;
  return node;
}

PNode BuildTree::mkNode( double value, PNode left, PNode right ){
  PNode node = (PNode)malloc(sizeof(Node));
  node->tVar = NUM;
  node->number = value;
  node->pLeft = left;
  node->pRight = right;
  return node;
}

PNode BuildTree::mkNode( char* var, PNode left, PNode right ){
  PNode node = (PNode)malloc(sizeof(Node));
  node->tVar = NAME;
  strcpy( node->var = new char[strlen(var)+1], var );
  node->pLeft = left;
  node->pRight = right;
  return node;
}

Tree* BuildTree::makeTree(){
  stream->GetLex();
  return new Tree( mkTree() );
}

PNode BuildTree::mkTree(){
  return mkLogic();
}

PNode BuildTree::mkLogic(){
  PNode ptr = mkAdditive();
  while( stream->CurrLex() == LOGIC_AND || stream->CurrLex() == LOGIC_OR ) {
    TypeLex prevLex = stream->CurrLex();
    stream->GetLex();
    PNode ptrNew = mkNode( prevLex, ptr, mkAdditive() );
    ptr = ptrNew;
  }
  return ptr;
}

PNode BuildTree::mkAdditive(){
  PNode ptr = mkMultiplicative();
  while( stream->CurrLex() == PLUS || stream->CurrLex() == MINUS ) {
    TypeLex prevLex = stream->CurrLex();
    stream->GetLex();
    PNode ptrNew = mkNode( prevLex, ptr, mkMultiplicative() );
    ptr = ptrNew;
  }
  return ptr;
}

PNode BuildTree::mkMultiplicative(){
  PNode ptr = mkPower();
  while( stream->CurrLex() == MULTIPLY || stream->CurrLex() == DIV || stream->CurrLex() == MOD ) {
    TypeLex prevLex = stream->CurrLex();
    stream->GetLex();
    PNode ptrNew = mkNode( prevLex, ptr, mkPower() );
    ptr = ptrNew;
  }
  return ptr;
}

PNode BuildTree::mkPower(){
  PNode ptr = mkAtom();
  while( stream->CurrLex() == POWER ){
    stream->GetLex();
    PNode ptrNew = mkNode( POWER, ptr, mkPower() );
    ptr = ptrNew;
  }
  return ptr;
}

PNode BuildTree::mkAtom(){
  switch (stream->CurrLex()) {
    case NUM:
      stream->GetLex();
      return mkNode( stream->GetNum(), NULL, NULL );
    case MINUS:{
      stream->GetLex();
      PNode temp = mkAtom();
      temp->number *= -1;
      return temp;
    }
    case NAME:{
        stream->GetLex();
        char *name = stream->GetVar();
        if( stream->CurrLex() == RESULT ) {
          strcpy( name = new char[strlen(stream->GetVar())+1], stream->GetVar() );
          stream->GetLex();
          HashTable::instance().putLex( name )->tree = mkTree();
        }
        return mkNode( name, NULL, NULL );
        break;
    }
    case LRB:{
      stream->GetLex();
      PNode ptr = mkTree();
      if ( stream->CurrLex() != NE ) stream->GetLex();
      return ptr;
      break;
    }
    case LSB:{
      stream->GetLex();
      PNode ptr = mkAtom();
      stream->GetLex();
      return mkNode( HashTable::instance().putLex(ptr->var)->value, NULL, NULL );
      break;
    }
    case COS:{
      stream->GetLex();
      PNode ptr = mkTree();
      if ( stream->CurrLex() != NE ) stream->GetLex();
      return mkNode( COS, ptr, mkNode( NUM, NULL, NULL ) );
      break;
    }
    case SIN:{
      stream->GetLex();
      PNode ptr = mkTree();
      if ( stream->CurrLex() != NE ) stream->GetLex();
      return mkNode( SIN, ptr, mkNode( NUM, NULL, NULL ) );
      break;
    }
    default:
      return mkNode( NE, NULL, NULL );
  }
}
