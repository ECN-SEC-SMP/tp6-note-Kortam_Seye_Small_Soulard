#ifndef PLATEAU_H
#define PLATEAU_H

#include "case.h"
#include "joueur.h"
#include <vector>
#include <string>
using namespace std;

class Plateau {
private:
    vector<Joueur> joueurs;        // Liste des joueurs
    vector<Case*> cases;          // Liste des cases du plateau

public:
    Plateau() = default;
    ~Plateau();
    void initialiser(const vector<Joueur>& Joueurs);
    void commencerJeu();
    int lancerDe();
};

#endif // PLATEAU_H
