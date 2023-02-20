#include "hash.h"



Hash::Hash(){
    // Initiliazes every node in hash table as null
  length = 100;
  hashTable = new Node*[length];
  for(int i=0; i<length; i++){
    hashTable[i] = NULL;
  }
  
}

Hash::Hash(int pLength){
  // Initiliazes every node in hash table as null
  length = pLength;
  hashTable = new Node*[length];
  for(int i=0; i<length; i++){
    hashTable[i] = NULL;
  }
  
}

void Hash::addStudent(char* pName, int pId, float pGpa){
  int nodeCounter = 0;
  Node* newNode = new Node(new Student(pName,pId,pGpa));
  cout << "ID: " << newNode->getStudent()->getId() << endl;
  // Gets hash value for student
  int index = hashFunction1(newNode->getStudent()->getId(),length);  
  // Checks if student is first of its hash value
  if(hashTable[index] == NULL){
   hashTable[index] = newNode;
   cout << "Student Added" << endl;
  }
    
  else{
    // Loops through linked list until it reaches the end
    Node* current = hashTable[index];
    while(current->getNext() != NULL){
      nodeCounter++;
    
      current = current->getNext();
    
    current->setNext(newNode);
    cout << "Student Added" << endl;
    if(nodeCounter==2){
      reHash(nodeCounter);
    }
  }
}

void Hash::deleteStudent(int pId){
  
  int index = hashFunction1(pId,length);
  Node* current = hashTable[index];
  // CHecks if student to delete is at head
  if(hashTable[index]->getStudent()->getId()==pId){
    // Sets new head
    hashTable[index] = hashTable[index]->getNext();
    delete current;
    cout << "Student has been deleted." << endl;
    return;
  }
  // Loops through linked list to look for matching ID
  for(auto i=current; i!=NULL; i=i->getNext()){
    if(i->getNext() == NULL) {
      break;
    }
    if(i->getNext()->getStudent()->getId()==pId){
      Node* temp = i->getNext();
      i->setNext(i->getNext()->getNext());
      delete temp;
      cout << "Student  has been deleted." << endl;
      return;
    }
  }

  cout << "Unable to find student." << endl;
  
}


int Hash::hashFunction1(int pId,int length){
  return (pId % length);
}

void Hash::reHash(int nodeCounter){
  vector<Node*> reHashVect;
  cout << "Hashing" << endl;
  int newLength = length*3;
  int index;
  Node** newTable = new Node*[newLength];
  for(int i=0; i< newLength; i++){
    newTable[i] = NULL;
  }
  // Daren Kostov helped me out with this part of the code
  for(auto i=0; i < length; i++){
    for(auto j=hashTable[i]; j!=NULL; j=j->getNext()){
      // Puts all the necessary Nodes into a vector 
      auto current = j;
      reHashVect.push_back(j);
      hashTable[i] = j->getNext();
    }      
    for(auto k = reHashVect.begin(); k!=reHashVect.end(); k=reHashVect.begin()){
      // Rehashes nodes in vector
      // Places them in appropriate bucket in new hash table
      index = hashFunction1((*k)->getStudent()->getId(),newLength);
      if(newTable[index] == NULL){
        newTable[index] = (*k);
      }
      else{
        Node* temp = newTable[index];
        while(temp->getNext() != NULL){
          temp=temp->getNext();
        }
        temp->setNext((*k));
      }
      hashTable.delete[k]
    }
  }
  hashTable = newTable;
  length = newLength;
}

void Hash::printList(){
  // Goes through every bucket
  for(auto i=0; i < length; i++){
    // Then every node
    for(auto j=hashTable[i]; j!=NULL; j=j->getNext()){
      Student* current = j->getStudent();
      cout << "Name: " << current->getName() << endl;
      cout << "ID: " << current->getId() << endl;
      cout << "GPA: " << current->getGpa() << endl;
      cout << endl;
    }
  }
}





