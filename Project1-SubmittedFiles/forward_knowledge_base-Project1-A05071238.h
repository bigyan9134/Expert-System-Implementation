//
//  forward_chain.h
//  BackwardChain
//
//  Created by Bigyan Bhandari on 9/18/21.
//

#ifndef forward_chain_h
#define forward_chain_h

#endif /* forward_chain_h */


class ForwardChain {
  
    public:
    
   
    
    std::vector<std::string> clause_variable_list = {"High blood pressure and progression of disease",
                                                "Fluid Collection",
                                                "Inflammation",
                                                "Poor blood circulation",
                                                "Narrow blood vessels and chest pain",
                                                "Elevated Cholesterol",
                                                "Blood Clotting",
                                                "Increased Heart Rate",
                                                "Blockage in blood vessels"};
    
    std::vector<std::string> treatment_list = { "ACE INHIBITOR / ARB BLOCKERS" ,
                                            "DIURETICS / ALDOSTERONE ANTAGONISTS"
                                            "CORTICOSTEROIDS",
                                            "ACE INHIBITOR/ ANGIOTENSIN II RECEPTOR BLOCKERS",
                                            "NITRATES",
                                            "STATIN",
                                            "VAGAL MANEUVER",
                                            "CLOT PREVENTING DRUGS ( CLOPIDOGREL, TICAGRELOR)/ ASPIRIN",
                                            "ANTI-ARRYTHMIC DRUGS",
                                            "NITRATES/ OPEN HEART SURGERY" };
    
    
    
    std::vector<std::string> diagnosis_list = {"Heart Failure", "Cardiomyopathy", "Angina", "Coronary Artery Disease", "Tachycardia", "Ventricular Tachycardia"};
    
    std::vector<std::pair<std::string, std::string>> variable_initialized_list = variable_initializer(clause_variable_list);
    
    
    std::vector<std::pair<std::string, std::string>>variable_initializer(std::vector<std::string> variable_list){
        std::vector< std::pair<std::string, std::string> > temp_var_initializer;
        
        for ( std::string variable : variable_list){
            std::pair<std::string, std::string> temp_pair = std::make_pair(variable, "");
            temp_var_initializer.push_back(temp_pair);
        }
        
        return temp_var_initializer;
    }
    
    // 
    
    std::vector< std::pair< int, std::vector<int>> >diagnosis_ailment = {
        {0, {0,1}}, {1, {2, 3}}, {2, {4, 5, 6}}, {3, {0,6}}, {4, {6,7}}, {7, {7,8}}   };
    
    std::vector < std::vector<std::string> > ailment_condition = { {"HIGH", "COLLECTED"}, {"INFLAMED", "REDUCED"}, {"NARROWED", "ELEVATED", "CLOT"}, {"HIGH", "CLOT"}, {"INCREASED", "CLOT"}, {"INCREASED", "BLOCKAGE"} };
    
    std::vector<std::pair< std::vector<std::string>, std::string > > ailment_condition_treatment = {
        {{clause_variable_list[0], "HIGH"}, "ACE-INHIBITOR / ARB BLOCKERS"}, {{clause_variable_list[1], "COLLECTED"}, "DIURETICS / ALDOSTERONE ANTAGONISTS"}, {{clause_variable_list[2], "INFLAMED"}, "CORTICOSTEROIDS"}, {{clause_variable_list[3], "REDUCED"}, "ACE INHIBITOR / ANGIOTENSIN II RECEPTOR BLOCKERS"}, {{clause_variable_list[4], "NARROWED"}, "NITRATES"}, {{clause_variable_list[5], "ELEVATED"}, "STATIN"}, {{clause_variable_list[6], "CLOT"}, "CLOT PREVENTING DRUGS (CLOPIDOGREL, TICAGRELOR) OR ASPIRIN"}, {{ clause_variable_list[7], "INCREASED"}, "VAGAL MANEUVER"} };
    
    
};
    

