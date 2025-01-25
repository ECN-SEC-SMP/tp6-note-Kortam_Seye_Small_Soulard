
#ifndef CASETERRAIN_H
#define CASETERRAIN_H
#include <iostream>
#include "Case.hpp"
#include "Case_Achetable.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
#include <vector>
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
    void actioncase(Joueur& joueur, vector<Joueur>& joueurs, Plateau& plateau); ;
    int getLoyer() const;
    void setLoyer(int loyer);

    int getGroupe() const;
    void setGroupe(int groupe);

    int getConstruction() const;
    void setConstruction(int construction);
    
};


#endif // CASETERRAIN_H
