#ifndef PLATEAU_H
#define PLATEAU_H

#include "case.hpp"
#include "joueur.hpp"
#include <vector>
#include <string>
using namespace std;

class Plateau {
public:
    void initialiser(const vector<Joueur> &Joueurs,const vector<Case> &Cases);
    void commencerJeu();

private:
    vector<Joueur> joueurs;
    vector<Case> cases;
};

#endif // PLATEAU_H



