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
    do {
        cout << "Entrez le nombre de joueurs (entre 2 et 4): ";
        cin >> nombreJoueurs;
        if (cin.fail() || nombreJoueurs < 2 || nombreJoueurs > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nombre de joueurs invalide. Veuillez reessayer." << endl;
        }
    } while (nombreJoueurs < 2 || nombreJoueurs > 4);


    vector<Joueur> joueurs;
    for (int i = 0; i < nombreJoueurs; ++i) {
        string nom;
        cout << "Entrez le nom du joueur " << i + 1 << ": ";
        cin >> nom;
        Joueur nouveaujoueur(true,nom, 1500, 0, 0, false);
        nouveaujoueur.setNbGares(0);
        nouveaujoueur.setDes(0);
        nouveaujoueur.setNbServices(0);
        nouveaujoueur.setToursEnPrison(0);
        joueurs.push_back(nouveaujoueur);
    }



    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(joueurs.begin(), joueurs.end(), default_random_engine(seed));


    cout << "Ordre de passage des joueurs:" << endl;

    for (size_t i = 0; i < joueurs.size(); ++i) {
        cout << "Joueur " << i + 1 << ": " << joueurs[i].getNom() << endl;
    }

    Plateau plateau;
    //vector<Case> cases;
    //plateau.initialiser(joueurs,cases);
    plateau.initialiser(joueurs);
    plateau.commencerJeu();

    return 0;
}
