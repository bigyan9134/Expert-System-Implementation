/*
An implementation of backward chaining and forward chaining in creating an
 expert system for a hospital in diagnosing cardiovascular diseases and to
 recoomend treatment based on the diagnosis.
 
 Compilation instruction:
 
 You could compile the program however you may like but in case of any problem,
 the following is the code used to compile and run the program in the shell of
 replit.com
 
 Use: `g++ -std=c++17 Project1-A05071238.cpp` to compile the program
 Then run the program using `./a.out`
 
 Submitted by: Bigyan Bhandari
 Student ID: A05071238
 CS 4346 Artificial Intelligence Project-1
 
 Also included with this file are the following files:
    a. forward_knowlwdge_base.h
    b. forward_rules.h
    c. rules.h
    d. knowledge_base.h
 
*/

#include <iostream>
#include "rules-Project1-A05071238.h"




int main(){

  
  std::cout << "Welcome to the Diagnosis-Treatment program for Heart Diseases!\n\n\n";
    
  
  Rules heart_disease_diagnosis = Rules();


  heart_disease_diagnosis.start_iteration();
    
    
  
  return 0;
};
