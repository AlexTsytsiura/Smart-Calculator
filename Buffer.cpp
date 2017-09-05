#include "Buffer.h"

Buffer::Buffer(std::vector<PNode>* ArrOfNode){
  it = ArrOfNode->begin();
  iteratorEnd = ArrOfNode->end();
}

PNode Buffer::getNext(){
  return ( it == iteratorEnd ) ? NULL : *(it++);
}
