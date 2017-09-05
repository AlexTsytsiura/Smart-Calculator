#include "HashTable.h"

/**********************
  Hash Table iterator
***********************/

template <class node>
node* iter<node>::operator*(){
  return node_ptr;
}

template <class node>
void iter<node>::operator++(){
  node_ptr = node_ptr->pNext;
}

template <class node>
bool iter<node>::operator!=(iter const& i)const{
  return node_ptr != i.node_ptr;
}

/******************
  Hash Table List
*******************/

void HashList::push_back(HashNode *p){
  p->pNext = root;
  root = p;
}

iter<HashNode> HashList::begin(){
  return iter(root);
}

iter<HashNode> HashList::end(){
  return iter(NULL);
}

/**********************
        Hashtable
***********************/
HashTable HashTable::Instance;

HashTable& HashTable::instance(){
  return Instance;
}

HashTable::HashTable(){
  memset( hashTable, NULL, sizeof(hashTable) );
}

int HashTable::indexOf( char * p ){
  int index = 0;
  for( size_t j = 0; j < strlen(p); j++ )
    index = index << 1 ^ p[j];
  return index %= TABLE_SIZE;
}

HashNode* HashTable::putLex(char* p){
  int index = indexOf(p);
  assert( index < TABLE_SIZE );
  for( HashList::iter it = hashTable[index].begin(); it != hashTable[index].end(); ++it ){
   if( !strcmp(p, (*it)->var) )
    return (*it);
  }
  HashNode* obj = new HashNode;
  obj->recursion = true;
  obj->value = 0;
  strcpy( obj->var = new char[strlen(p)+1], p );
  obj->tree = NULL;
  hashTable[index].push_back(obj);
  return obj;
}
