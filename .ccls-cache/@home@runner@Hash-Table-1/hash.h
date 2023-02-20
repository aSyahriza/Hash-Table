#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cstring>
#include <vector>

#include "node.h"
#include "student.h"

class Hash{
  public:
  Hash();  
  Hash(int pLength);

  

  void addStudent(char* pName, int pId, float pGpa);
  void deleteStudent(int pId);
  void printList();
  void reHash();
  int hashFunction1(int pId,int length);

  
  
  
  private:
    int length;
    Node** hashTable = nullptr;
};

#endif