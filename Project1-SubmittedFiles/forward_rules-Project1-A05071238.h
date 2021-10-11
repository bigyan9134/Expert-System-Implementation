//
//  forward_rules.h
//  BackwardChain
//
//  Created by Bigyan Bhandari on 9/21/21.
//

#ifndef forward_rules_h
#define forward_rules_h


#endif /* forward_rules_h */

#include <queue>
#include "forward_knowledge_base-Project1-A05071238.h"

class Forward_Rules {
    
public:
    std::string diagnosis;


    
    
    std::queue <std::pair <std::string, std::string> >variables_initialized_queue;
    
    // constructor with diagnosis passed here
    // our default diagnosis is "Heart Failure" otherwise
    
    
    
    
    // initiate an object of ForwardChain to use knowledge base for forward chain
    
    ForwardChain chain_forward = ForwardChain();
    
    

    
    //getting the index of the disease diagnosed to initiate our forward chain
    
    
    
    
    // we got the index of the disease, now we can initiate the effects of the disease
    // we can also initialize the conclusion variable queue
    // on our knowledge base diagnosis-ailment gives us the effects of the disease
    // the ailment condition then initializes the variable initialized list with the effect of the disease
    
    
    void initialize_ailment( int diagnosis_index) {
        
        for ( auto diagnosis_ailment_pair : chain_forward.diagnosis_ailment) {
            if ( diagnosis_index == diagnosis_ailment_pair.first){
                std::vector<int> ailments_index = diagnosis_ailment_pair.second;
                
                
                // we are initializing the ailments or clause_variable based on diagnosis
                
                
                for ( auto ailment_number : ailments_index){
                    chain_forward.variable_initialized_list[ailment_number].second = chain_forward.ailment_condition[diagnosis_index][ailment_number];
                        
                        
                        variables_initialized_queue.push(chain_forward.variable_initialized_list[ailment_number]);
                    }
                
            }
        }
        
        // this needs to call a function that goes thru the queue we just enqueued
        apply_forward_chain(variables_initialized_queue);
    }
    
    
    // now that ailments/effects have been initialized, we can work our way to the treatment as well
    // at this point all our effects of disease have been initialized, now for the next part:
    
    void apply_forward_chain(std::queue< std::pair<std::string, std::string > >variables_initialized_queue){
        
        
        while ( ! variables_initialized_queue.empty() ){
        std::pair< std::string, std::string> variable = variables_initialized_queue.front();
        variables_initialized_queue.pop();
            
        //check the value of pair in the knowlege base ailment_conditions_treatment to suggest a treatment
            
            for ( auto ailment_condition_treat : chain_forward.ailment_condition_treatment){
                std::vector<std::string> ailment_condition = ailment_condition_treat.first;
                
                
                if ( variable.first == ailment_condition[0] ) {
                    //if (variable.second == ailment_condition[1]){  // &&
                    std::string output_print = "\n\nThe patient might have " + variable.first;
                    std::string treatment_print = "\nTreat " + variable.first + " with " + ailment_condition_treat.second;
                    
                    std:: cout << output_print << std::endl;
                    std:: cout << treatment_print << std::endl;
                    }
                }
            }
        }
    
        
        //end_program();
        
    
    
    int end_program() {
        std::cout << "\n\n\n\nThank you for using this program!\n";
        exit(0);
    }
    
    
    
    
public:
    
    Forward_Rules( std::string diagnosis){
        this->diagnosis = diagnosis;
    };
    
    
    void initialize_forward_rule (){
        
        
        
        int diagnosis_index = 0;
        for ( int i = 0; i < chain_forward.diagnosis_list.size(); i++ ){
            if ( chain_forward.diagnosis_list[i] == this->diagnosis){
                diagnosis_index = i;
                break;
            }
        }
        
        initialize_ailment(diagnosis_index);
        end_program();
    }
};
