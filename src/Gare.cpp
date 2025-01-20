#include "case.hpp"
#include "Case_Achetable.hpp"
#include "Gare.hpp"

#include <iostream>
using namespace std;

Gare::Gare(int loyer) : loyer(loyer) {}

int Gare::calculer_loyer(){
    if (!getHypo()){
        return 0;
    }
    else{
        return loyer; 
    }
}