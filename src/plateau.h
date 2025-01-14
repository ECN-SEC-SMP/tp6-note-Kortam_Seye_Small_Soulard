#ifndef PLATEAU_H
#define PLATEAU_H

#include "case.h"
#include "joueur.h"
#include <vector>
#include <string>
using namespace std;

class Plateau {
public:
    void initialiser(const vector<Joueur>& Joueurs);
    void commencerJeu();

private:
    vector<Joueur> joueurs;
    vector<Case> cases;
};

#endif // PLATEAU_H



