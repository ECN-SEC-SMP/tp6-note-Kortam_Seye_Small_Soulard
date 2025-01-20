#include <iostream>
#include <cstdlib>
#include <ctime>
#include "joueur.hpp"


struct ResultatLancer {
    int de1;  // Résultat du premier dé
    int de2;  // Résultat du deuxième dé
    int somme;  // Somme des deux dés
};

Joueur::Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison) :
en_vie(0), nom(nom), solde(solde), position(position), nb_cartes_liberte(nb_cartes_liberte), en_prison(0){}
Joueur::Joueur() : en_vie(true), nom(""), solde(1500), position(0), nb_cartes_liberte(0), en_prison(false) {}

void Joueur::jouerTour() {
    // Implementation of jouerTour
}


bool Joueur::geten_vie() const {
    return en_vie;
}

void Joueur::seten_vie(bool en_vie) {
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

void Joueur::addSolde(int add) {
    this->solde = this->solde + add;
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

// Fonction pour lancer les dés
ResultatLancer lancer_des() {
    // Initialisation du générateur de nombres aléatoires (avec une graine)
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Lancer des dés à 6 faces
    int de1 = std::rand() % 6 + 1;  // Premier dé (valeurs entre 1 et 6)
    int de2 = std::rand() % 6 + 1;  // Deuxième dé (valeurs entre 1 et 6)

    // Calcul de la somme des deux dés
    int somme = de1 + de2;

    // Retourner le résultat sous forme d'un struct
    return {de1, de2, somme};
}
