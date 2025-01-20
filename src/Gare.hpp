#ifndef Gare_H
#define Gare_H

#include "Case"
#include "Case_Achetable.hpp"

#include <iostream>
using namespace std;


class Gare: public Case_Achetable{
protected:
    int loyer;
public:
    Gare(loyer);
    int calculer_loyer();
    
} 



















#endif