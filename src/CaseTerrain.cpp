#include "CaseTerrain.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
#include <iostream>
#include <vector>
using namespace std;

CaseTerrain::CaseTerrain(int loyer, int groupe, int construction) : loyer(loyer), groupe(groupe), construction(construction) {}


CaseTerrain::CaseTerrain(): loyer(0) {}

void CaseTerrain::actioncase(Joueur& joueur, vector<Joueur>& joueurs, Plateau& plateau) {
    if (getProprio() != "") {
        if (getProprio() == joueur.getNom()) {
            cout << "Vous êtes chez vous." << endl;
            return;
        }
        cout << "Ce terrain appartient déjà à " << getProprio() << "." << endl;
        int loyer = getLoyer();

        if (getConstruction() > 0) {
            loyer *= (1 + getConstruction()); // Augmente le loyer en fonction du nombre de constructions
        }else{
            //int tabterrains = [1, 3, 5, 6, 8, 9, 11, 13, 14, 15, 16, 18, 19, 21, 23, 24, 25, 26, 27, 29, 31, 32, 34, 35, 37, 39];
            int tabterrains[] = {1, 3, 5, 6, 8, 9, 11, 13, 14, 15, 16, 18, 19, 21, 23, 24, 25, 26, 27, 29, 31, 32, 34, 35, 37, 39};
            bool memeProprietaire = true;

            int groupe = this->getGroupe();

            for (int index : tabterrains) {
                Case* caseTemp = plateau.getCase(index);
                if (caseTemp && typeid(*caseTemp) == typeid(CaseTerrain)) {
                    auto* terrain = dynamic_cast<CaseTerrain*>(caseTemp);
                    if (terrain->getGroupe() == groupe && terrain->getProprio() != this->getProprio()) {
                        memeProprietaire = false;
                        break;
                    }
                }
            }

            if (memeProprietaire) {
                loyer *= 2;
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
    }else{
        char reponse;
        cout << "Voulez-vous acheter ce terrain pour " << getPrix() << " monos ? (o/n): ";
        cin >> reponse;

        if (reponse == 'o' || reponse == 'O') {
            if (joueur.getSolde() >= getPrix()) {
                joueur.addSolde(-getPrix());
                setProprio(joueur.getNom());;
                cout << "Vous avez acheté le terrain." << endl;
            } else {
                cout << "Vous n'avez pas assez de monos pour acheter ce terrain." << endl;
            }
        } else if (reponse == 'n' || reponse == 'N') {
            cout << "Vous avez choisi de ne pas acheter le terrain." << endl;
        } else {
            cout << "Réponse invalide." << endl;
        }
    }
}

int CaseTerrain::getLoyer() const {
    return loyer;
}

void CaseTerrain::setLoyer(int loyer) {
    this->loyer = loyer;
}

int CaseTerrain::getGroupe() const {
    return groupe;
}

void CaseTerrain::setGroupe(int groupe) {
    this->groupe = groupe;
}

int CaseTerrain::getConstruction() const {
    return construction;
}

void CaseTerrain::setConstruction(int construction) {
    this->construction = construction;
}
