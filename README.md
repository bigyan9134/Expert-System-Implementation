# Expert System Implementation For Diagnosis and Treatment of Heart Disease
An application of Expert System and Forward-Chaining and Backward-Chaining to design a heart disease diagnosis and treatment recommendation tool.

This command line tool uses a Knowledge base stored in an appropriate data structure and the input from the user to implement an algorithm that 
uses backward chaining principle. The algorithm uses recursive backward chain method along with memoization technique to come up with the most
likely diagnosis for a heart disease based on user provided answers to questions about symptoms.

It then implements a forward chaining algorithm to suggest various treatment regimens based on the diagnosis provided by the backward chaining
algorithm.

# Data Structure and algorithms used:

Use of appropriate data structures to store knowlege base in the form of a list is done in the event more disases and diagnosis are wished to be
added to the knowledge base.
A map structure to store the relation between symptoms and diagnosis allows a constant time lookup of possible diagnosis for the given list of 
symptoms.

Similar data structures are also used for forward chaining algorithm.

A stack based implementation of backward chaining algorithm and storing of input from the user in an appropriate map ensures that our recursive
backward chaining algorithm does not prompt user for duplicate inputs while at the same time keeping track of what possible path to follow and
backtracking to previous decision paths if necessary.

# Analysis of the program

The program uses map structure to store the most frequently required variables in the program i.e. the unique combination of symptoms that lead
tp a particular diagnosis. 

As such, increasing the size of the knowledge base would not slow the runtime of the program once the initialization of
data structures is done at the beginning of the program. Appropriate clause-variable list and instantiated variables list could be created in the
beginning of the program and once done, the runtime of the program would not be dependent on the size of knowledge base. 

Thus the program could also be scaled to include more detail and more diverse set of rules and knowledge base without inflating its runtime. 


## Please refer to the PDF document in the Main folder to get detailed description about the implementation of the program.
