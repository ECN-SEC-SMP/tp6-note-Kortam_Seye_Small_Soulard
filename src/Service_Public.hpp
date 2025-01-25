
#ifndef Service_Public_H
#define Service_Public_H
#include <vector>
#include "case.hpp"
#include "Case_Achetable.hpp"
#include "joueur.hpp"

#include <iostream>
using namespace std;


class Service_Public: public Case_Achetable{
protected: 
    int loyer;
public: 
    Service_Public(int loyer);
    //void actioncase(Joueur& joueur) const;
    void actioncase(Joueur &joueur, vector<Joueur>& joueurs);
};
#endif  // Service_Public_H
