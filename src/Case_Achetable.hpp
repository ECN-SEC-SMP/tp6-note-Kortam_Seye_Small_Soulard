#ifndef CASEACHETABLE_HPP
#define CASEACHETABLE_HPP

#include "Case.hpp"
#include <string>
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

#endif // CASEACHETABLE_HPP