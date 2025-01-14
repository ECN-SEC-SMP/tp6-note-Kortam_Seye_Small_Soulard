
#include "case.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void Plateau::initialiser(const vector<Joueur>& Joueurs) {
    joueurs = Joueurs; //initialise le tableau de joueurs

    //ici faut récupérer les cases
    cout << "Plateau initialise avec " << cases.size() << " cases." << endl;
}

void Plateau::commencerJeu() {
    bool jeuTermine = false;
    int tour = 0;
    while (!jeuTermine) {
        cout << "\n==== Tour " << tour + 1 << " ====" << endl;
        for (auto& joueur : joueurs) { //pour chaque joueur
            if (joueur.estEnFaillite()) {
                continue;
            }
            cout << joueur.getNom() << ", c'est votre tour." << endl;
            joueur.jouerTour();
            if (joueur.getSolde() <= 0) {
                joueur.setFaillite(true);
                cout << joueur.getNom() << " est en faillite !" << endl;
            }
        }

        int joueursRestants = 0; //compte le nombre de joueurs restants
        for (const auto& joueur : joueurs) {
            if (!joueur.estEnFaillite()) {
            ++joueursRestants;
            }
        }
        //si il reste un joueur ou moins, le jeu est terminé
        if (joueursRestants <= 1) {
            jeuTermine = true;
        }
        ++tour;
    }
    for (const auto& joueur : joueurs) {
        if (!joueur.estEnFaillite()) {//si le joueur n'est pas en faillite
            cout << "\nFélicitations, " << joueur.getNom() << " a gagné la partie !" << endl;
            break;
        }
    }
}

