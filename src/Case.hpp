#ifndef Case_hpp
#define Case_hpp

#include <iostream>

using namespace std; 

class Case

{
private:
    /* data */
    int numero;
    string nom; 
    bool achetable; // à revoir  
    
public:
    //Case();
    Case(int numero,  string nom);
    
    ~Case();
};








#endif
