#include "joueur.hpp"

Joueur::Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison) :
en_vie(0), nom(nom), solde(solde), position(position), nb_cartes_liberte(nb_cartes_liberte), en_prison(0);

Joueur::Joueur() : en_vie(true), nom(""), solde(1500), position(0), nb_cartes_liberte(0), en_prison(false) {}

void Joueur::jouerTour() {
    // Implementation of jouerTour
}


bool Joueur::getEnVie() const {
    return en_vie;
}

void Joueur::setEnVie(bool en_vie) {
    this->en_vie = en_vie;
}

string Joueur::getNom() const {
    return nom;
}

void Joueur::setNom(string nom) {
    this->nom = nom;
}

int Joueur::getSolde() const {
    return solde;
}

void Joueur::setSolde(int solde) {
    this->solde = solde;
}

int Joueur::getPosition() const {
    return position;
}

void Joueur::setPosition(int position) {
    this->position = position;
}

int Joueur::getNbCartesLiberte() const {
    return nb_cartes_liberte;
}

void Joueur::setNbCartesLiberte(int nb_cartes_liberte) {
    this->nb_cartes_liberte = nb_cartes_liberte;
}

bool Joueur::getEnPrison() const {
    return en_prison;
}

void Joueur::setEnPrison(bool en_prison) {
    this->en_prison = en_prison;
}

void Joueur::setFaillite(bool faillite) {
    // Implementation of setFaillite
}

bool Joueur::estEnFaillite() const {
    // Implementation of estEnFaillite
}