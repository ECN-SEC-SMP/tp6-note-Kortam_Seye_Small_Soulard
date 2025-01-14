#include "plateau.hpp"
#include "case.hpp"
#include "joueur.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

int main() {
    int nombreJoueurs;
    cout << "Entrez le nombre de joueurs: ";
    cin >> nombreJoueurs;

    vector<Joueur> joueurs;
    for (int i = 0; i < nombreJoueurs; ++i) {
        string nom;
        cout << "Entrez le nom du joueur " << i + 1 << ": ";
        cin >> nom;
        joueurs[i].setNom(nom);
    }

    //mélange les joueurs
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(joueurs.begin(), joueurs.end(), default_random_engine(seed));


    cout << "Ordre de passage des joueurs:" << endl;

    for (const auto& joueur : joueurs) {
        cout << joueur.getNom() << endl;
    }


    Plateau plateau;
    plateau.initialiser(joueurs);
    plateau.commencerJeu();

    return 0;
}
