#include "plateau.h"
#include "case.h"
#include "joueur.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void Plateau::initialiser(const vector<Joueur>& Joueurs) {
    joueurs = Joueurs;
    for (int i = 0; i < 40; ++i) {
        cases.push_back(new Case("Case " + to_string(i)));
    }
    //ici faut récupérer les cases
    cout << "Plateau initialise avec " << cases.size() << " cases." << endl;
}

void Plateau::commencerJeu() {
    bool jeuTermine = false;
    int tour = 0;
    while (!jeuTermine) {
        cout << "\n==== Tour " << tour + 1 << " ====" << endl;
        for (auto& joueur : joueurs) {
            if (joueur.estEnFaillite()) {
                continue;
            }
            cout << joueur.getNom() << ", c'est votre tour." << endl;
            int de1 = lancerDe();
            int de2 = lancerDe();
            int totalDe = de1 + de2;
            cout << "Vous avez obtenu " << de1 << " et " << de2 << " (total: " << totalDe << ")." << endl;
            joueur.avancer(totalDe, cases.size());
            Case* caseActuelle = cases[joueur.getPosition()];
            cout << "Vous êtes maintenant sur la case : " << caseActuelle->getNom() << endl;
            caseActuelle->action(joueur);
            if (joueur.getArgent() <= 0) {
                joueur.setFaillite(true);
                cout << joueur.getNom() << " est en faillite !" << endl;
            }
        }
        int joueursRestants = count_if(joueurs.begin(), joueurs.end(), [](const Joueur& joueur) {
            return !joueur.estEnFaillite();
        });
        if (joueursRestants <= 1) {
            jeuTermine = true;
        }
        ++tour;
    }
    for (const auto& joueur : joueurs) {
        if (!joueur.estEnFaillite()) {
            cout << "\nFélicitations, " << joueur.getNom() << " a gagné la partie !" << endl;
            break;
        }
    }
}

int Plateau::lancerDe() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

