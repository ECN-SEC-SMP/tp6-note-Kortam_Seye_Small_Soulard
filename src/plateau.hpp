#ifndef PLATEAU_H
#define PLATEAU_H

#include "case.hpp"
#include "joueur.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Plateau {
public:
    //void initialiser(const vector<Joueur> &Joueurs,const vector<Case> &Cases);
    void initialiser(const vector<Joueur> &Joueurs);
    void commencerJeu();
    //Case* getCase(const string& nom) const;
    Case* getCase(int index) const;

private:
    vector<Joueur> joueurs;
    vector<unique_ptr<Case>> cases;
    //vector<Case> cases;
};

#endif // PLATEAU_H



