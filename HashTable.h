#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include "Calculator.h"

const int TABLE_SIZE = 0xFF;

struct HashNode{
  char* var;
  PNode tree;
  double value;
  bool recursion;
  HashNode* pNext;
};

template <class node>
class iter{
  private:
    node* node_ptr;
  public:
    iter(node* n): node_ptr(n){}
    node* operator*();
    void operator++();
    bool operator!=(iter const& i)const;
};

class HashList{
  protected:
    HashNode* root;
  public:
    typedef iter<HashNode> iter;
    void push_back(HashNode *p);
    iter begin();
    iter end();
};

class HashTable{
  private:
    HashTable();
  protected:
    HashList hashTable[TABLE_SIZE];
    int indexOf( char * );
    static HashTable Instance;
  public:
    static HashTable& instance();
    HashNode* putLex(char*);
};

#endif // HASHTABLE_H_INCLUDED
