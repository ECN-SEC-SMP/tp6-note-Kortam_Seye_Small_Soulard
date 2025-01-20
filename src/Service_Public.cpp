#include "case.hpp"
#include "Case_Achetable.hpp"
#include "Service_Public.hpp"

#include <iostream>
using namespace std;


Service_Public::Service_Public(int loyer):loyer(loyer){}

Service_Public::calculer_loyer()
{
    if (!getHypo()){
        return(0);
    }
    else{
        return loyer; 
    }
}



