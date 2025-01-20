
#include "Case.hpp"
#include "Case_Achetable.hpp"
#include "Service_Public.hpp"

#include <iostream>
using namespace std;


Service_Public::Service_Public(loyer):loyer(loyer){}

Service_Public::calculer_loyer()
{
    if !(Service_Public.hypo()){
        return(0);
    }
    else{
        return loyer; 
    }
}


