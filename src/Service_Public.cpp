
#include "Case.hpp"
#include "Case_Achetable.hpp"
#include "Service_Public.hpp"

#include <iostream>
using namespace std;


Service_Public::Service_Public(loyer_m):loyer_m(loyer){}

Service_Public::calculer_loyer()
{
    if !(Service_Public.hypo_m()){
        return(0);
    }
    else{
        return loyer_m; 
    }
}


