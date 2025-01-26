#include "CaseTerrain.hpp"
#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

/**
 * @brief Constructeur paramétré de la classe CaseTerrain.
 * 
 * @param loyer Le loyer de la case.
 * @param groupe Le groupe auquel appartient le terrain.
 * @param construction Le nombre initial de constructions sur la case.
 */
CaseTerrain::CaseTerrain(int loyer, int groupe, int construction)
    : loyer(loyer), groupe(groupe), construction(construction) {}

/**
 * @brief Constructeur par défaut.
 */
CaseTerrain::CaseTerrain() : loyer(0), groupe(0), construction(0) {}

/**
 * @brief Déclenche l'action liée à la case terrain.
 * 
 * Cette méthode détermine si le joueur doit payer un loyer, peut acheter le terrain,
 * ou si d'autres effets doivent être appliqués selon les règles.
 * 
 * @param joueur Le joueur actif.
 * @param joueurs Liste des joueurs présents sur le plateau.
 * @param plateau Référence au plateau de jeu.
 */
void CaseTerrain::actioncase(Joueur& joueur, vector<Joueur>& joueurs, Plateau& plateau) {
    if (getProprio() != "") {
        // La case est déjà possédée
        if (getProprio() == joueur.getNom()) {
            cout << "Vous êtes sur votre propre terrain." << endl;
            return;
        }

        cout << "Ce terrain appartient à " << getProprio() << "." << endl;
        int loyer = getLoyer();

        if (getConstruction() > 0) {
            loyer *= (1 + getConstruction()); // Augmente le loyer en fonction des constructions
        } else {
            // Vérifie si tous les terrains du groupe appartiennent au même propriétaire
            int tabTerrains[] = {1, 3, 5, 6, 8, 9, 11, 13, 14, 15, 16, 18, 19, 21, 23, 24, 25, 26, 27, 29, 31, 32, 34, 35, 37, 39};
            bool memeProprietaire = true;
            int groupe = getGroupe();

            for (int index : tabTerrains) {
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
        }

        // Paiement du loyer
        cout << "Vous payez " << loyer << " monos à " << getProprio() << "." << endl;
        joueur.addSolde(-loyer);

        for (auto& j : joueurs) {
            if (j.getNom() == getProprio()) {
                j.addSolde(loyer);
                break;
            }
        }

    } else {
        // La case n'est pas encore possédée
        char reponse;
        cout << "Voulez-vous acheter ce terrain pour " << getPrix() << " monos ? (o/n) : ";
        cin >> reponse;

        if (reponse == 'o' || reponse == 'O') {
            if (joueur.getSolde() >= getPrix()) {
                joueur.addSolde(-getPrix());
                setProprio(joueur.getNom());
                cout << "Vous avez acheté le terrain." << endl;
            } else {
                cout << "Vous n'avez pas assez de monos pour acheter ce terrain." << endl;
            }
        } else {
            cout << "Vous avez choisi de ne pas acheter le terrain." << endl;
        }
    }
}

/**
 * @brief Accesseur pour le loyer.
 */
int CaseTerrain::getLoyer() const {
    return loyer;
}

/**
 * @brief Mutateur pour le loyer.
 */
void CaseTerrain::setLoyer(int loyer) {
    this->loyer = loyer;
}

/**
 * @brief Accesseur pour le groupe.
 */
int CaseTerrain::getGroupe() const {
    return groupe;
}

/**
 * @brief Mutateur pour le groupe.
 */
void CaseTerrain::setGroupe(int groupe) {
    this->groupe = groupe;
}

/**
 * @brief Accesseur pour les constructions.
 */
int CaseTerrain::getConstruction() const {
    return construction;
}

/**
 * @brief Mutateur pour les constructions.
 */
void CaseTerrain::setConstruction(int construction) {
    this->construction = construction;
}
