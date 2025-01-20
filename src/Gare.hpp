#ifndef Gare_H
#define Gare_H

#include "case.hpp"
#include "Case_Achetable.hpp"

#include <iostream>
using namespace std;


class Gare: public Case_Achetable{
protected:
    int loyer;
public:
    Gare(int loyer);
    int calculer_loyer();
    
};


#endif // Gare_H