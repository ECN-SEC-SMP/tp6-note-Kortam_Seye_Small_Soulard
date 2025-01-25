#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <windows.h> // Pour Sleep()
#include "case.hpp"
#include "CaseTerrain.hpp"
#include "Case_nonAchetable.hpp"
#include "Gare.hpp"
#include "Service_Public.hpp"
#include "joueur.hpp"
#include "plateau.hpp"

using namespace std;

/**
 * @struct ResultatLancer
 * @brief Structure utilisée pour stocker les résultats d'un lancer de dés.
 */
struct ResultatLancer {
    int de1;   ///< Résultat du premier dé
    int de2;   ///< Résultat du deuxième dé
    int somme; ///< Somme des deux dés
};

/**
 * @class Joueur
 * @brief Classe représentant un joueur dans le jeu.
 */
Joueur::Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison) 
    : en_vie(0), nom(nom), solde(solde), position(position), nb_cartes_liberte(nb_cartes_liberte), en_prison(0) {}

Joueur::Joueur() 
    : en_vie(true), nom(""), solde(1500), position(0), nb_cartes_liberte(0), en_prison(false) {}

/**
 * @brief Cette méthode gère un tour de jeu pour le joueur.
 * Le joueur lance deux dés et se déplace sur le plateau. En fonction de la case sur laquelle il tombe,
 * il devra prendre une action spécifique (acheter, payer des frais, etc.).
 * Si le joueur fait trois doubles consécutifs, il est envoyé en prison.
 * 
 * @param plateau Le plateau de jeu sur lequel le joueur évolue.
 */
void Joueur::jouerTour(Plateau& plateau) {
    int nbdoubles = 0;      ///< Nombre de doubles consécutifs
    bool tourTermine = false; ///< Booléen pour savoir si le tour est terminé

    random_device rd;                     // Entropie (générateur de nombres aléatoires basé sur le matériel)
    mt19937 gen(rd());                    // Générateur Mersenne Twister
    uniform_int_distribution<> dis(1, 6); // Distribution uniforme pour les dés

<<<<<<< HEAD
    while (!tourTermine) {
=======
    /*
    if (peutConstruireMaisons()) {
        construireMaisons();
    }*/
    if (getEnPrison()==true) {
        cout << "Vous êtes en prison." << endl;
        cout << "Vous avez passé " << getToursEnPrison() << " tours en prison." << endl;
        if (getToursEnPrison() >= 3) {
            cout << "Vous êtes libéré de prison après 3 tours." << endl;
            setEnPrison(false);
            jouerTour(plateau, joueurs); 
            return;
        }

        if (getNbCartesLiberte()>0) { // Si le joueur possède une carte de sortie de prison
            cout << "Vous utilisez votre carte de sortie de prison." << endl;
            setNbCartesLiberte(getNbCartesLiberte() - 1);
            setEnPrison(false);
        }else{
            cout << "Voulez-vous payer une amende de 50 pour sortir de prison ? (o/n): ";
            char choix;
            cin >> choix;
            if (choix == 'O' || choix == 'o') {
                if (solde >= 50) {
                    solde -= 50;
                    cout << "Vous avez payé l'amende et êtes libéré de prison." << endl;
                    setEnPrison(false);
                } else {
                    cout << "Vous n'avez pas assez d'argent pour payer l'amende." << endl;
                }
            } else {
                cout << "Vous essayez de faire un double pour sortir de prison." << endl;
                int de1 = dis(gen);
                int de2 = dis(gen);
                cout << "Lancer des dés: " << de1 << " et " << de2 << endl;
                if (de1 == de2) {
                    cout << "Double ! Vous êtes libéré de prison." << endl;
                    setEnPrison(false);
                } else {
                    cout << "Pas de double. Vous restez en prison." << endl;
                    incrementerToursEnPrison();
                    return;
                }
            }
        } 
    }
    

    while (!tourTermine)
    {

>>>>>>> 848dcc221152cabe6ba52fc42ef110c6e05c85dc
        int de1 = dis(gen); // Lance le premier dé
        int de2 = dis(gen); // Lance le deuxième dé

        int somme = de1 + de2;
        cout << "\n" << nom << ": lancer des des: " << de1 << " et " << de2 << " - Somme: " << somme << endl;

        if (de1 == de2) {
            nbdoubles++;
            cout << "Double ! Nouveau tour" << endl;

            if (nbdoubles == 3) {
                cout << "Trois doubles consecutifs! Le joueur va en prison." << endl;
                setPosition(10);
                setEnPrison(true);
                return;
            }
        } else {
            tourTermine = true;
        }

        position = (position + somme) % 40;
        cout << "Nouvelle position: " << position << endl;

        Case* caseActuelle = plateau.getCase(position);

        if (caseActuelle) {
            cout << "Vous êtes sur la case: " << caseActuelle->getNom() << endl;
            cout << "Type de la case: " << typeid(*caseActuelle).name() << endl;

            // Appel de l'action spécifique en fonction du type de case
            if (typeid(*caseActuelle) == typeid(Case_NonAchetable)) {
                dynamic_cast<Case_NonAchetable*>(caseActuelle)->actioncase(*this);
            } else if (typeid(*caseActuelle) == typeid(CaseTerrain)) {
                dynamic_cast<CaseTerrain*>(caseActuelle)->actioncase(*this);
            } else if (typeid(*caseActuelle) == typeid(Gare)) {
                dynamic_cast<Gare*>(caseActuelle)->actioncase(*this);
            } else if (typeid(*caseActuelle) == typeid(Service_Public)) {
                dynamic_cast<Service_Public*>(caseActuelle)->actioncase(*this);
            } else {
                cout << "Type de case inconnu." << endl;
            }
        } else {
            cout << "Erreur: case non trouvée." << endl;
        }
    }
}

/**
 * @brief Getter pour savoir si le joueur est en vie.
 * 
 * @return true si le joueur est en vie, sinon false.
 */
bool Joueur::geten_vie() const {
    return en_vie;
}

/**
 * @brief Setter pour changer l'état de vie du joueur.
 * 
 * @param en_vie Le nouvel état de vie du joueur.
 */
void Joueur::seten_vie(bool en_vie) {
    this->en_vie = en_vie;
}

/**
 * @brief Getter pour obtenir le nom du joueur.
 * 
 * @return Le nom du joueur.
 */
string Joueur::getNom() const {
    return nom;
}

/**
 * @brief Setter pour changer le nom du joueur.
 * 
 * @param nom Le nouveau nom du joueur.
 */
void Joueur::setNom(string nom) {
    this->nom = nom;
}

/**
 * @brief Getter pour obtenir le solde du joueur.
 * 
 * @return Le solde actuel du joueur.
 */
int Joueur::getSolde() const {
    return solde;
}

/**
 * @brief Setter pour changer le solde du joueur.
 * 
 * @param solde Le nouveau solde du joueur.
 */
void Joueur::setSolde(int solde) {
    this->solde = solde;
}

/**
 * @brief Ajoute une certaine somme au solde du joueur.
 * 
 * @param add La somme à ajouter.
 */
void Joueur::addSolde(int add) {
    this->solde = this->solde + add;
}

/**
 * @brief Getter pour obtenir la position du joueur sur le plateau.
 * 
 * @return La position actuelle du joueur sur le plateau.
 */
int Joueur::getPosition() const {
    return position;
}

/**
 * @brief Setter pour changer la position du joueur sur le plateau.
 * 
 * @param position La nouvelle position du joueur.
 */
void Joueur::setPosition(int position) {
    this->position = position;
}

/**
 * @brief Getter pour obtenir le nombre de cartes "liberté" du joueur.
 * 
 * @return Le nombre de cartes "liberté" du joueur.
 */
int Joueur::getNbCartesLiberte() const {
    return nb_cartes_liberte;
}

/**
 * @brief Setter pour changer le nombre de cartes "liberté" du joueur.
 * 
 * @param nb_cartes_liberte Le nouveau nombre de cartes.
 */
void Joueur::setNbCartesLiberte(int nb_cartes_liberte) {
    this->nb_cartes_liberte = nb_cartes_liberte;
}

/**
 * @brief Getter pour savoir si le joueur est en prison.
 * 
 * @return true si le joueur est en prison, sinon false.
 */
bool Joueur::getEnPrison() const {
    return en_prison;
}

/**
 * @brief Setter pour changer l'état de prison du joueur.
 * 
 * @param en_prison L'état de prison du joueur.
 */
void Joueur::setEnPrison(bool en_prison) {
    this->en_prison = en_prison;
}
