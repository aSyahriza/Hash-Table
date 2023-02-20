#include "hash.h"



Hash::Hash(){
  length = 100;
  hashTable = new Node*[length];
  for(int i=0; i<length; i++){
    hashTable[i] = NULL;
  }
  
}

Hash::Hash(int pLength){
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
    Node* current = hashTable[index];
    while(current->getNext() != NULL){
      nodeCounter++;
      
     // cout << "Current:" << current->getStudent()->getId() << endl;
      current = current->getNext();
    }
    // cout << "Node counter: " << nodeCounter << endl;
    current->setNext(newNode);
    cout << "Student Added" << endl;
    if(nodeCounter==2){
      reHash();
    }
  }
}

void Hash::deleteStudent(int pId){
  int index = hashFunction1(pId,length);
  Node* current = hashTable[index];
  if(hashTable[index]->getStudent()->getId()==pId){
    hashTable[index] = hashTable[index]->getNext();
    delete current;
    cout << "Student has been deleted." << endl;
    return;
  }
  for(auto i=current; i!=NULL; i=i->getNext()){
    if(i->getNext() == NULL) {
      break;
    }
    if(i->getNext()->getStudent()->getId()==pId){
      Node* temp = i->getNext();
      i->setNext(i->getNext()->getNext());
      delete temp;
      cout << "Student  has been deleted" << endl;
      return;
    }
  }

  cout << "Unable to find student" << endl;
  
}


int Hash::hashFunction1(int pId,int length){
  return (pId % length);
}

void Hash::reHash(){
  vector<Node*> reHashVect;
  cout << "Hashing" << endl;
  int newLength = length*3;
  Node* current;
  int index;
  Node** newTable = new Node*[newLength];
  for(int i=0; i< newLength; i++){
    newTable[i] = NULL;
  }
  for(auto i=0; i < length; i++){
    for(auto j=hashTable[i]; j!=NULL; j=j->getNext()){
      reHashVect.push_back(j);
      current = j;
      index = hashFunction1(current->getStudent()->getId(),newLength);
      if(newTable[index] == NULL){
        newTable[index] = current;
        cout << "CHanged1" << endl;
      }
      else{
        Node* temp = newTable[index];
        while(temp->getNext() != NULL){
          cout << "Temp name: "<< temp->getStudent()->getName() << endl;
          temp=temp->getNext();
          cout << "yuh" << endl;
        }
        temp->setNext(current);
        cout << "CHanged2" << endl;
        printList();
      }
    }
  }
  hashTable = newTable;
  length = newLength;
  cout << " I pull up" << endl;
}

void Hash::printList(){
  /*
  for(auto i=0; i < length; i++){
    for(auto j=hashTable[i]; j!=NULL; j=j->getNext()){
      Student* current = j->getStudent();
      cout << "Name: " << current->getName() << endl;
      cout << "ID: " << current->getId() << endl;
      cout << "GPA: " << current->getGpa() << endl;
      cout << "Key: " << i << endl;
      cout << endl;
    }
  }*/
}





/*

class Hash{
  public:
  Hash();  
  Hash(int pLength);

  Node** hashTable;

  void addStudent(Node* pNode);
  void deleteStudent(Node* pNode);
  void printList();
  void reHash();
  int hashFunction1(Node* pNode);
  int hashFunction2(Node* pNode);
  
  private:
    int length;
};

*/