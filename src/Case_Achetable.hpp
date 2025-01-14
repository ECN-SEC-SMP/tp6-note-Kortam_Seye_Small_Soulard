#ifndef Case_Achetable_hpp

#define Case_Achetable_hpp

#include "Case.hpp"

#include <iostream>

using namespace std; 

class Case_Achetable: public Case
{
private:
    string proprio_m;
    int prix_m;
    bool hypothèque_m;

public:
    Case_Achetable(string proprio, int prix, bool hypo);
    
    ~Case_Achetable();
};



#endif