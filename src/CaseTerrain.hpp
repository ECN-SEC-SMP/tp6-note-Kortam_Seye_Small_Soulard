
#ifndef CASETERRAIN_H
#define CASETERRAIN_H
#include <iostream>
#include "Case.hpp"
#include "Case_Achetable.hpp"
#include "joueur.hpp"
class CaseTerrain: public Case_Achetable 
{
private:
    int loyer;
    int groupe;
    int construction;
public:
    CaseTerrain(int loyer, int groupe, int construction);
    CaseTerrain();
    calculer_loyer(); 
    void actioncase(Joueur& joueur) const;
    
};


#endif // CASETERRAIN_H
