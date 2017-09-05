#include <iostream>
#include <iomanip.h>
#include <fstream>
#include "Calculator.h"

using namespace std;

int main (int argc, char * const argv[]){
  Stream *stream;
  fstream out;
  if( argc == 3 ){
    static fstream in(argv[1], fstream::in);
    out.open(argv[2], fstream::out);
    stream = new Stream(in);
  }
  else {
    stream = new Stream(cin);
  }
  if( argc == 3 )
    out << "> ";
  else
    printf( "> " );
  BuildTree *buildTree = new BuildTree( stream );
  RPN *rpn;
  while( stream->isRead() ){
    Tree *tree = buildTree->makeTree();
    if( argc == 3 )
      out << setprecision(2) << rpn->compute( tree->ParsingToBuffer() ) << "\n> ";
    else
      printf( "%.2lf\n> ", rpn->compute( tree->ParsingToBuffer() ) );
  }
  return 0;
}
