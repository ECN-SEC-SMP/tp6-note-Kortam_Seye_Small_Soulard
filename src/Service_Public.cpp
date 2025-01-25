#include "case.hpp"
#include "Case_Achetable.hpp"
#include "Service_Public.hpp"
#include "joueur.hpp"

#include <iostream>
using namespace std;


Service_Public::Service_Public(int loyer):loyer(loyer){}

void Service_Public::actioncase(Joueur& joueur) const {
    printf("actionpublic\n");
}


