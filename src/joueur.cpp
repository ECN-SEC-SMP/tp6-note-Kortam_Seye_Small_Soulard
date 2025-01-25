#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <windows.h> // Pour Sleep()
#include "joueur.hpp"
#include "plateau.hpp"

using namespace std;

struct ResultatLancer
{
    int de1;   // Resultat du premier de
    int de2;   // Resultat du deuxième de
    int somme; // Somme des deux des
};

Joueur::Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison) : en_vie(0), nom(nom), solde(solde), position(position), nb_cartes_liberte(nb_cartes_liberte), en_prison(0) {}
Joueur::Joueur() : en_vie(true), nom(""), solde(1500), position(0), nb_cartes_liberte(0), en_prison(false) {}

void Joueur::jouerTour(Plateau& plateau)
{
    /*
    if (peutConstruireMaisons()) {
        construireMaisons();
    }
    if (en_prison) {
        gererPrison();
        return;
    }
    */
    int nbdoubles = 0;
    bool tourTermine = false;
    // srand(static_cast<unsigned int>(time(0)));

    random_device rd;                     // Entropie (générateur de nombres aléatoires basé sur le matériel)
    mt19937 gen(rd());                    // Générateur Mersenne Twister
    uniform_int_distribution<> dis(1, 6); // Distribution uniforme pour les dés

    while (!tourTermine)
    {

        int de1 = dis(gen); // Lance le premier dé
        int de2 = dis(gen); // Lance le deuxième dé

        // int de1 = rand() % 6 + 1;
        // int de2 = rand() % 6 + 1;

        int somme = de1 + de2;

        cout <<"\n"<< nom << ": lancer des des: " << de1 << " et " << de2 << " - Somme: " << somme << endl;

        if (de1 == de2)
        {
            nbdoubles++;
            cout << "Double ! Nouveau tour" << endl;

            if (nbdoubles == 3)
            {
                cout << "Trois doubles consecutifs! Le joueur va en prison." << endl;
                setPosition(10);
                setEnPrison(true);
                return;
            }
        }
        else
        {
            tourTermine = true;
        }

        position = (position + somme) % 40;

        cout << "Nouvelle position: " << position << endl;

        Case* caseActuelle = plateau.getCase(position);
        /*for (int i = 0; i < 40; ++i) {
            Case* c = plateau.getCase(i);
            if (c) {
                cout << "Case " << i << " : " << c->getNom() << endl;
            } else {
                cout << "Case " << i << " : Erreur: case non trouvée." << endl;
            }
        }*/

        if (caseActuelle) {
            cout << "Vous etes sur la case: " << caseActuelle->getNom() << endl;
            caseActuelle->action();
        } else {
            cout << "Erreur: case non trouvée." << endl;
        }
        // agir En Fonction De La Case
    }
}

bool Joueur::geten_vie() const
{
    return en_vie;
}

void Joueur::seten_vie(bool en_vie)
{
    this->en_vie = en_vie;
}

string Joueur::getNom() const
{
    return nom;
}

void Joueur::setNom(string nom)
{
    this->nom = nom;
}

int Joueur::getSolde() const
{
    return solde;
}

void Joueur::setSolde(int solde)
{
    this->solde = solde;
}

void Joueur::addSolde(int add)
{
    this->solde = this->solde + add;
}

int Joueur::getPosition() const
{
    return position;
}

void Joueur::setPosition(int position)
{
    this->position = position;
}

int Joueur::getNbCartesLiberte() const
{
    return nb_cartes_liberte;
}

void Joueur::setNbCartesLiberte(int nb_cartes_liberte)
{
    this->nb_cartes_liberte = nb_cartes_liberte;
}

bool Joueur::getEnPrison() const
{
    return en_prison;
}

void Joueur::setEnPrison(bool en_prison)
{
    this->en_prison = en_prison;
}
