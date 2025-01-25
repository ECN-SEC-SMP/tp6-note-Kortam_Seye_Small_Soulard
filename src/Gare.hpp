#ifndef Gare_H
#define Gare_H

#include "case.hpp"
#include "Case_Achetable.hpp"
#include "joueur.hpp"
#include <vector>

#include <iostream>
using namespace std;


class Gare: public Case_Achetable{
protected:
    int loyer;
public:
    Gare(int loyer);
    void actioncase(Joueur& joueur, vector<Joueur>& joueurs);
    
};


#endif // Gare_H