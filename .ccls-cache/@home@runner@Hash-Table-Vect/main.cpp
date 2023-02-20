#include <iostream>
#include <cstring>

using namespace std; 

#include "hash.h"
#include "node.h"
#include "student.h"

int main() {
  bool loop = true;

  // Char array to hold user input
  char command[10];
  char* inputName = new char[80];
  int inputId;
  float inputGpa;
  Hash hashTable;
  
  
  cout << "Enter ADD, DELETE, PRINT, or QUIT" << endl;
  cout << "\n" << endl;
  
  // Loops program
  while(loop == true){
    // Gets input from user
    cin.get(command,10,'\n');
    cin.clear();
    cin.ignore(99999,'\n');
    
    
    
    // Checks if the user wants to ADD students to list
    if(strcmp(command, "ADD") == 0){

      // Asks user for information of student.
      inputName = new char[80];
      cout << "Enter name of student: " << endl; 
      cin.get(inputName,80);

      cout << "Enter ID of student: " << endl;
      cin >> inputId;

      cout << "Enter GPA of student: " << endl;
      cin >> inputGpa;

     
      hashTable.addStudent(inputName, inputId, inputGpa);
      cout << "\n" << endl;
     

      

      // Creates new student
      
      
    }
    // Checks if the user wants to DELETE students to list
    else if(strcmp(command, "DELETE") == 0){

      cout << "Enter ID of student: " << endl;
      cin >> inputId;

      hashTable.deleteStudent(inputId);
      cout << "\n" << endl;
    }
    // Checks if the user wants to PRINT the current list
    else if(strcmp(command, "PRINT") == 0){

      hashTable.printList();
      cout << endl;
      
    }
    // Checks if user wants to QUIT
    else if(strcmp(command, "QUIT") == 0){

      // Breaks the loop, quits program
      loop = false;
      
    }    
  }
  cout << "Program ended." << endl;
  return 0;
}