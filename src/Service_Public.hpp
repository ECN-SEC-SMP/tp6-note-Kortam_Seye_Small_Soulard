
#ifndef Service_Public_H
#define Service_Public_H

#include "Case.hpp"
#include "Case_Achetable.hpp"

#include <iostream>
using namespace std;


class Service_Public: public Case_Achetable{
private: 
    int loyer ;
public: 
    Service_Public(loyer);
    calculer_loyer(); 
}
#endif