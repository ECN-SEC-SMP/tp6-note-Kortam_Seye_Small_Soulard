#include "CaseTerrain.hpp"

CaseTerrain::CaseTerrain(int loyer, int groupe, int construction) : loyer(loyer), groupe(groupe), construction(construction) {}


CaseTerrain::CaseTerrain(): loyer(0) {}







/*

CaseTerrain::CaseTerrain(const std::string& nom, int loyer)
    : Case_Achetable(nom), proprietaire(-1), loyer(loyer), estHypotheque(false) {}





void CaseTerrain::action() const {
    if (proprietaire == -1) {
        std::cout << "Le terrain \"" << nom << "\" est libre, vous pouvez l'acheter !\n";
    } else if (estHypotheque) {
        std::cout << "Le terrain \"" << nom << "\" est hypotheque, aucun loyer à payer.\n";
    } else {
        std::cout << "Vous payez " << loyer << " monos au proprietaire (joueur " << proprietaire << ").\n";
    }
}

void CaseTerrain::setProprietaire(int joueur) {
    proprietaire = joueur;
}

int CaseTerrain::getProprietaire() const {
    return proprietaire;
}

void CaseTerrain::hypothequer() {
    estHypotheque = true;
}

void CaseTerrain::desHypothequer() {
    estHypotheque = false;
}

*/