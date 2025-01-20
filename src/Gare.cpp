

#include "Case"
#include "Case_Achetable.hpp"
#include "Gare.hpp"

#include <iostream>
using namespace std;

Gare::Gare(loyer):loyer_m(loyer){}

int Gare::calculer_loyer(){
    if !(Gare.hypo_m()){
        return(0);
    }
    else{
        return loyer_m; 
    }
    
    
}