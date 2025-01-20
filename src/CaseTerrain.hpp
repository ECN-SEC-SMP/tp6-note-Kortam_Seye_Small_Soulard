
#ifndef CASETERRAIN_H
#define CASETERRAIN_H
#include <iostream>
#include "Case.hpp"

class CaseTerrain : public Case_Achetable {
private:
    int loyer;
    int groupe;
    int construction;
public:
    CaseTerrain(int loyer_m, int groupe_m, int construction_m);
    CaseTerrain();
    calculer_loyer(); 
    
};


#endif // CASETERRAIN_H
