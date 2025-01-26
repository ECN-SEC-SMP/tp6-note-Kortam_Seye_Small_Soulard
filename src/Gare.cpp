#include "case.hpp"
#include "Case_Achetable.hpp"
#include "Gare.hpp"
#include "joueur.hpp"
#include <vector>

#include <iostream>
using namespace std;

/**
 * @brief Constructeur de la classe Gare.
 * 
 * @param loyer Le montant du loyer pour cette gare.
 */
Gare::Gare(int loyer) : loyer(loyer) {}


/**
 * @brief Gere l'action associee a la gare.
 * 
 * Si la gare appartient deja a un joueur, celui-ci doit payer un loyer. 
 * Si la gare n'est pas possedee, le joueur peut l'acheter en payant le prix specifie.
 * 
 * @param joueur Le joueur qui atterrit sur la gare.
 * @param joueurs La liste des joueurs.
 */
void Gare::actioncase(Joueur& joueur, vector<Joueur>& joueurs) {
    //printf("actiongare\n");
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
        cout << "Vous payez " << loyer << " monos de loyer a " << getProprio() << "." << endl;
        cout << "Votre solde etait de " << joueur.getSolde() << " monos." << endl;
        joueur.addSolde(-loyer);
        cout << "Votre solde est maintenant de " << joueur.getSolde() << " monos." << endl;

        for (auto& j : joueurs) {
            if (j.getNom() == getProprio()) {
                cout << j.getNom() << " a recu " << loyer << " monos." << endl;
                cout << "Le solde de " << j.getNom() << " etait de " << j.getSolde() << " monos." << endl;
                j.addSolde(loyer);
                cout << "Le solde de " << j.getNom() << " est mtn de " << j.getSolde() << " monos." << endl;

            break;
            }
        }
        char c;
        cout << "Appuyez sur 'c' pour continuer..." << endl;
        cin >> c;
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