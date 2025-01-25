#include "case.hpp"
#include "Case_Achetable.hpp"
#include "Service_Public.hpp"
#include "joueur.hpp"
#include <vector>
#include <iostream>
using namespace std;


Service_Public::Service_Public(int loyer):loyer(loyer){}

void Service_Public::actioncase(Joueur& joueur, vector<Joueur>& joueurs) {
    printf("actionpublic\n");
    if (getProprio() != "") {
        if (getProprio() == joueur.getNom()) {
            cout << "Vous etes chez vous." << endl;
            return;
        }
        cout << "Ce service public appartient deja a " << getProprio() << "." << endl;

        int nbServicesProprio = 0;
        for (auto& j : joueurs) {
            if (j.getNom() == getProprio()) {
            nbServicesProprio = j.getNbServices();
            break;
            }
        }
        cout << "Le proprietaire " << getProprio() << " possede " << nbServicesProprio << " services." << endl;
        int des = joueur.getDes(); 
        printf("des: %d\n", des);
        if (nbServicesProprio == 1) {
            loyer = des * 4;
        } else if (nbServicesProprio == 2) {
            loyer = des * 10;
        }
        joueur.addSolde(-loyer);
        cout << "Vous payez " << loyer << " monos de loyer a " << getProprio() << "." << endl;
        char c;
        cout << "Appuyez sur 'c' pour continuer..." << endl;
        cin >> c;
        /*for (auto& j : joueur) {
            if (j.getNom() == getProprio()) {
            j.addSolde(loyer);
            break;
            }
        }*/
        return;
    }
    char reponse;
    cout << "Voulez-vous acheter ce service public pour " << getPrix() << " monos ? (o/n): ";
    cin >> reponse;

    if (reponse == 'o' || reponse == 'O') {
        if (joueur.getSolde() >= getPrix()) {
            joueur.addSolde(-getPrix());
            setProprio(joueur.getNom());
            cout << "Vous avez achete le service public." << endl;
            //joueur.setNbServices(joueur.getNbServices() + 1);
            joueur.incrementNbServices();
            cout << "Vous possédez maintenant " << joueur.getNbServices() << " services." << endl;
        } else {
            cout << "Vous n'avez pas assez de monos pour acheter ce service public." << endl;
        }
    } else if (reponse == 'n' || reponse == 'N') {
        cout << "Vous avez choisi de ne pas acheter le service public." << endl;
    } else {
        cout << "Reponse invalide." << endl;
    }
}

