#include <vector>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>




class Knowledge_base{

  public:


  // all possible conclusions for our program

  std::vector<std::string>conclusions = {"Heart Failure", "Cardiomyopathy", "Angina", "Coronary Aretry Disease", "Tachycardia", "Ventricular Tachycardia"};

  // variables_list is the list of all symptoms

  std::vector<std::string>variables_list = {"Rapid/Irregular Heart Beats or Heart Palpitations", "Chest Pain", "Persistent Shortness of Breath", "Fatigue", "Dizziness", "Lightheadedness","Weakness", "Unexplained Sweating", "Fainting","Weight Gain", "Edema", "Swollen Stomach", "Confusion", "Chest Tightness", "Vomiting","Restlessness", "Heart Attack", "Nausea", "Tightness in Neck", "Cardiac Arrest", "Lung Congestion"};

  /*
 list of all possible symptoms combination that leads to a diagnosis

  */

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

// clauses for diseases, numerical value represents
  // index in the variables list

  std::vector<int> heart_failure_clause = {0,1,3,4,6,8,9,12,20};

  std::vector<int> cardiomyopathy_clause = {0,1,2,3,5,9,10,11};

  std::vector<int> angina_clause = {1,2,3,4,5,6,7,13,14,15};

  std::vector<int> coronary_clause = {0,2,3,6,7,16,17};

  std::vector<int> tachycardia_clause = {0,1,2,4,5};

  std::vector<int> ventricular_tachycardia_clause = {0,1,2,4,5,8,18,19};

  //pushing all clauses in the clause index vector for easy retrieval later

  std::vector<std::vector<int>> clause_index = { heart_failure_clause, cardiomyopathy_clause, angina_clause, coronary_clause, tachycardia_clause, ventricular_tachycardia_clause};




  std::map<std::string, int>variable_initialized = variable_list_initializer(variables_list);


  std::vector<int>clause_variable_list = initialize_clause_variable_list( 20, clause_index);

/*
 the variable list initializer function returns a map of variable and their initialization status, -1 means the variable has not been initialized, 0 means the variable is false and 1 means the variable is true

*/


std::map<std::string, int> variable_list_initializer( std::vector<std::string> variables_list ){
  std::map<std::string, int> initialized;

  for (std::string variable : variables_list){
    std::pair<std::string, int> key_value;
    key_value = std::make_pair(variable, -1);
    initialized.insert(key_value);
  }
  
  return initialized;
}

 

std::vector<int> initialize_clause_variable_list (int numRules, std::vector<std::vector<int>>clause_index){

  std::vector<int>clause_variable_list(numRules * clause_index.size());

  for (int i = 0; i < clause_index.size(); i++ ){
    int begin_at = i * numRules;
    for ( auto variable_index : clause_index[i]){
      clause_variable_list[begin_at + variable_index] = 1;
    }
  }
  return clause_variable_list;

}


};
