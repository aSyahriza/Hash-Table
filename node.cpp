#include "node.h"

Node::Node(){
  student = NULL;
  next = NULL;
}

Node::Node(Student* studentP){
  student = studentP;
  next = NULL;
}

Node::~Node(){
  delete student;
  next = NULL;
}


void Node::setValue(Student* studentP){
  student = studentP;
}
Student* Node::getStudent(){
  return student;
}

void Node::setNext(Node* nextP){
  next = nextP;
}

Node* Node::getNext(){
  return next;
} 