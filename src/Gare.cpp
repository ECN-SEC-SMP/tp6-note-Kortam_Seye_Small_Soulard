#include "case.hpp"
#include "Case_Achetable.hpp"
#include "Gare.hpp"
#include "joueur.hpp"

#include <iostream>
using namespace std;

Gare::Gare(int loyer) : loyer(loyer) {}

void Gare::actioncase(Joueur& joueur) {
    printf("actiongare\n");
    if (getProprio() != "") {
        if (getProprio() == joueur.getNom()) {
            cout << "Vous etes chez vous." << endl;
            return;
        }
        cout << "Cette gare appartient deja a " << getProprio() << "." << endl;
        int nbGares = joueur.getNbGares();
        int loyer = 25;
        if (nbGares == 2) {
            loyer = 50;
        } else if (nbGares == 3) {
            loyer = 100;
        } else if (nbGares >= 4) {
            loyer = 200;
        }
        joueur.addSolde(-loyer);
        cout << "Vous payez " << loyer << " monos de loyer a " << getProprio() << "." << endl;
        return;
    }
    char reponse;
    cout << "Voulez-vous acheter cette gare pour " << getPrix() << " monos ? (o/n): ";
    cin >> reponse;

    if (reponse == 'o' || reponse == 'O') {
        if (joueur.getSolde() >= getPrix()) {
            joueur.addSolde(-getPrix());
            setProprio(joueur.getNom());
            cout << "Vous avez achete la gare." << endl;
            joueur.setNbGares(joueur.getNbGares() + 1);
        } else {
            cout << "Vous n'avez pas assez de monos pour acheter cette gare." << endl;
        }
    } else if (reponse == 'n' || reponse == 'N') {
        cout << "Vous avez choisi de ne pas acheter la gare." << endl;
    } else {
        cout << "Reponse invalide." << endl;
    }
}