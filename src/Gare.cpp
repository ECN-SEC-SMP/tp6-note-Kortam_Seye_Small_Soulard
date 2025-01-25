#include "case.hpp"
#include "Case_Achetable.hpp"
#include "Gare.hpp"
#include "joueur.hpp"

#include <iostream>
using namespace std;

Gare::Gare(int loyer) : loyer(loyer) {}

void Gare::actioncase(Joueur& joueur) const {
    printf("actiongare\n");
}