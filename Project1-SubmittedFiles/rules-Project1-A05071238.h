#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include "knowledge_base-Project1-A05071238.h"
#include "forward_rules-Project1-A05071238.h"
/*
Index used for Diagnoses ( our goals):
0: Heart Failure 
1: Cardiomyopathy
2: Angina        
3: Coronary      
4: Tachycardia   
5: Ventricular Tachycardia


Index used for Clause / Symptons ( our states) :

0: "Rapid/Irregular Heart Beats or Heart Palpitations"
1: "Chest Pain"
2: "Persistent Shortness of Breath"                   
3: "Fatigue"
4: "Dizziness"
5: "Lightheadedness"
6: "Weakness"
7: "Unexplained Sweating"
8: "Fainting"
9: "Weight Gain"
10: "Edema"
11: "Swollen Stomach"
12: "Confusion"
13: "Chest Tightness"
14: "Vomiting"
15: "Restlessness"
16: "Heart Attack"
17: "Nausea"
18: "Tightness in Neck"
19: "Cardiac Arrest"
20: "Lung Congestion"
*/




class Rules{

public:
  Rules() {};

private:
    
    std::string final_diagnosis = "";

/*
The rule-symptom map initialized has three parts to it.
The first int refers to the rule number in our knowledge base and the pair on the second part has a vector and an int. First vector references the list of symptoms that have to have been initialized and the int references the diagnosis. eg.  {10, ({2, 4, 5}, 5) } means that the corresponding rule number is 10; the index of symptoms that need to be true is {2, 4, 5} and the diagnosis is index 5 of the diagnoses list.
*/

std::vector<int>rule_number = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340, 350, 360};

// for the diagnosis_index, the value at index i corresponnds to the diagnosis that would be given by the rule at index i of vector<int> rule_number

std::vector<int> diagnosis_index = {0,0,0,1,1,5,5,2,2,5,1,1,1,2,2,2,5,5,2,0,0,2,2,1,0,0,2,0,2,0,3,3,3,3,2,0};


// for the symptoms_combination the vector at index i is the combination of symptoms that need to be true to trigger a diagnosis at index i of the diagnosis_index


std::vector<std::vector<int>>symptoms_combination = {
  {0,1,6},
  {0,12},
  {0,20},
  {0,10},
  {0,11},
  {0,18},
  {0,19},
  {1,2,6},
  {1,2,7},
  {1,2,8},
  {1,2,9},
  {1,10},
  {1,11},
  {1,13},
  {1,14},
  {1,15},
  {1,18},
  {1,19},
  {1,3,7},
  {1,3,8},
  {1,20},
  {1,5,6},
  {1,5,7},
  {1,5,9},
  {1,12},
  {1,6,9},
  {1,6,7},
  {1,6,8},
  {1,7},
  {1,8,9},
  {0,16},
  {0,17},
  {0,7},
  {0,8,9},
  {1,4,7},
  {1,4,9}
};
    
//rule_symptoms map contains rule as key and associate symptoms as value

    
std::map< int, std::vector<int> > rule_symptoms = initialize_rule_symptoms(rule_number, symptoms_combination);

// conclusion list is the objective/conclusion of each rule. In our case, we are looking to diagnose certain heart condition in each rule, so 'diagnosis' would be a conclusion for each of our rules and we initialize our conclusion list accordingly


std::vector<std::pair<int,std::string>>conclusion_list = initialize_conclusion_list(36);

//visited conclusion list keeps track to what rules we have visited already and ruled out the possibility of diagnosis. It gets updated when we visit different conclusion list elements

std::vector<std::pair<int,std::string>>visited_conclusion_list;

// conclusion stack to keep track of what rule we need to go to next


std::stack<std::pair<int, int>>conclusion_stack = initialize_stack();

std::stack<std::pair<int, int>> initialize_stack () {
  std::stack<std::pair<int, int>>conclusion_stack;
  conclusion_stack.push(std::make_pair(10,0));
  return conclusion_stack;
}



// initialize_conclusion_list 

std::vector< std::pair<int,std::string> >initialize_conclusion_list(int numRules){
  
  std::vector<std::pair<int, std::string > > rules_conclusions;
  
  for ( int i = 1; i <= numRules; i++){
    std::pair< int, std::string> tempPair;
    tempPair = std::make_pair(i, "diagnosis");
    rules_conclusions.push_back(tempPair);
  }

  return rules_conclusions;
}
    
// initialize rule_symptoms map
    
std::map< int, std::vector<int> > initialize_rule_symptoms( std::vector<int> rules, std::vector<std::vector<int>> symptoms){
    std::map< int, std::vector< int> > rule_symptoms;
        
    if ( rules.size() != symptoms.size()){
        printf("Rules and symptoms size mismatch. Recheck data.\n");
        return rule_symptoms;
    }
        
    for ( int i = 0; i < rules.size(); i++){
        rule_symptoms[rules[i]] = symptoms[i];
    }
        
        return rule_symptoms;
}

// Initialize a knowledge_base object

Knowledge_base current_knowledge = Knowledge_base();


public:

/*
Main logic-control area of the program here. After all data structures and variables have been initialized we are ready to implement the rules.


*/

std::pair<int, int> check_conclusion_stack(){
  
  if (conclusion_stack.empty()){
    conclusion_stack.push( std::make_pair(10, 0));
  }
    
  return conclusion_stack.top();
}

/*

Start iteration checks the top of the stack and returns the rule number and the conclusion index number that needs to be processed by the program. It means the check_conclusion_stack function tells our program which rule and which variable are we working on next to get response from or to check if diagnosis is possible. 

*/


void start_iteration(){
    std::string response;
    int response_value;

    // check_conclusion_stack to determine which rule and variable to get response for


    std::pair<int, int> rule_to_process = check_conclusion_stack();


    //int rule_number = rule_to_process.first;
    int variable_index = rule_to_process.second;

  

    while ( (response != "Y") && (response != "N") && (response != "y") && (response != "n") ){
        std::string condition = current_knowledge.variables_list[variable_index];
        printf("Does the patient have %s?  enter: Y/N\n", condition.c_str());
      std::cin >> response;
    }
    
    /*
     a function to read in an input from gui
     
    */
    if ( response == "Y" || response == "y"){
      response_value = 1;
    } else {
      response_value = 0;
    }
    
    updateResponse(response_value, variable_index);

}
  
/*
 startResponse has gotten a response whether a symptom can be initialized as 0 if it is not present in a patient
 and 1 if a patient shows the symptom. updateResponse now updats that response and calls process response for the
 rule that is at the top of the stack

*/
    
void updateResponse( int variable_value, int variable_position){
        
    current_knowledge.variable_initialized[current_knowledge.variables_list[variable_position]] = variable_value;

        
    std::pair<int, int> rule_to_process = check_conclusion_stack();
        
    int rule_num_to_process = rule_to_process.first;
        
    processResponse(rule_num_to_process);
}

/*

 process response is provide with rule number. It checks the rules_symptoms map and figures whether all symptoms variable have been
 initialized. If all symptoms variables are initialized, a dignosis can be made or ruled out. If diagnosis is made, we have reached
 the end of our program. If the ddiagnosis is ruled out, we go the next rule in the rules list, update the stack and call startIteration.
 If the decision can't be reached, it means some variable still need to be initialized. If such is the case, we call start iteration for
 the same rule number and new symptom index. The stack is updated.
 
*/



void processResponse( int rule_num_to_process){

        int next_rule = -1;
        std::vector<int>symptoms_for_rule = rule_symptoms[rule_num_to_process];
    
    

        for ( int symptom : symptoms_for_rule){
            
          
             if (current_knowledge.variable_initialized[current_knowledge.variables_list[symptom]] == 0){
                  
          // the diagnosis cannot be true
          // check next set of rules
          // remove top item from conclusion stack
          // break from the for loop
                  visited_conclusion_list.push_back({rule_num_to_process, "diagnosis"});
                  conclusion_stack.pop();
                  
                  next_rule = ( rule_num_to_process + 10 );
                 
                 if ( next_rule > rule_number[rule_number.size() - 1] ){
                     // We have reached the end without finding a diagnosis --  print out a message and return
                        printf("Diagnosis not possible at this time. Please refer to an MD.\n");
                        endProgram();
                     } 
                  
                 std::vector<int> next_set_of_symptom = rule_symptoms[next_rule];
                 
                 conclusion_stack.push({next_rule, next_set_of_symptom[0]});
                 processResponse(next_rule);
            }
        
        
          
        /*
        if symptom is -1 that means current rule has not been fully processed. We roll back the next rule variable as the code below
        processes the same rule-symptom block until we initialize all variables for the rule and can reach to the conclusion
         
        */
          
         else if ( current_knowledge.variable_initialized[current_knowledge.variables_list[symptom]] == -1) {
            next_rule = rule_num_to_process;
             conclusion_stack.pop();
             conclusion_stack.push({next_rule, symptom});
             start_iteration();
        }
        
    }
    
    
    
    if ( next_rule == -1){
        
        printf("\n\nThe patient is showing the following symptoms:\n\n");
        
        for ( auto each_symptom : rule_symptoms[rule_num_to_process]){
            std::string symptom_description = current_knowledge.variables_list[each_symptom];
            printf("%s\n", symptom_description.c_str());
        }
        
        
        final_diagnosis = current_knowledge.conclusions[diagnosis_index[(rule_num_to_process/ 10) - 1]];
        
        printf("\n\nThe patient might be suffering from %s. Please perform appropriate tests to confirm and treat for the condition.\n\n",  final_diagnosis.c_str());
        endProgram();
        
    }
    
    
}
    
void endProgram(){
    
    
    Forward_Rules treatment = Forward_Rules( getDiagnosis());
    
    if ( this-> getDiagnosis() == ""){
        treatment.end_program();    // could not diagnose the disease so no use running forward chaining
        
    } else {
        
    treatment.initialize_forward_rule();
    }
}
    
    
// get diagnosis will be called by the forward chain program to recommend the course of treatment
std::string getDiagnosis(){
        return this->final_diagnosis;
    }

};
