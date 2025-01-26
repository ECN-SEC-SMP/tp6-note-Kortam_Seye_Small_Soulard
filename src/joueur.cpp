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
#include <vector>

using namespace std;

/**
 * @struct ResultatLancer
 * @brief Structure pour stocker le résultat d'un lancer de dés.
 */
struct ResultatLancer
{
    int de1;   // Resultat du premier de
    int de2;   // Resultat du deuxième de
    int somme; // Somme des deux des
};

/**
 * @brief Constructeur avec paramètres de la classe Joueur.
 * @param en_vie Statut actif ou non du joueur.
 * @param nom Nom du joueur.
 * @param solde Montant initial d'argent.
 * @param position Position de départ sur le plateau.
 * @param nb_cartes_liberte Nombre de cartes "Libéré de prison".
 * @param en_prison Statut de prison initial.
 */
Joueur::Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison) : en_vie(0), nom(nom), solde(solde), position(position), nb_cartes_liberte(nb_cartes_liberte), en_prison(0) {}

/**
 * @brief Constructeur par défaut de la classe Joueur.
 */
Joueur::Joueur() : en_vie(true), nom(""), solde(1500), position(0), nb_cartes_liberte(0), en_prison(false) {}


/**
 * @brief Gère le tour de jeu du joueur.
 * @details Inclut le lancer de dés, la gestion des doubles, le traitement des cases, 
 * et les mécanismes de prison.
 * @param plateau Référence au plateau de jeu.
 * @param joueurs Liste des joueurs dans la partie.
 */
void Joueur::jouerTour(Plateau& plateau, vector<Joueur>& joueurs)
{
    int nbdoubles = 0;
    bool tourTermine = false;
    // srand(static_cast<unsigned int>(time(0)));

    random_device rd;                     // Entropie (générateur de nombres aléatoires basé sur le matériel)
    mt19937 gen(rd());                    // Générateur Mersenne Twister
    uniform_int_distribution<> dis(1, 6); // Distribution uniforme pour les dés

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

        int de1 = dis(gen); // Lance le premier dé
        int de2 = dis(gen); // Lance le deuxième dé

        // int de1 = rand() % 6 + 1;
        // int de2 = rand() % 6 + 1;
        cout << "Appuyez sur entree pour lancer les des" << endl;
        cin.ignore();
        int somme = de1 + de2;
        setDes(somme);
        cout <<"\n"<< nom << ": lancer des des: " << de1 << " et " << de2 << " - Somme: " << somme << endl;

        if (de1 == de2)
        {
            if(getEnPrison()==false){
                nbdoubles++;
                cout << "Double ! Nouveau tour" << endl;               
            }else {
                return;
            }
            


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

        int anciennePosition = position;
        position = (position + somme) % 40;
        if (position < anciennePosition)
        {
            cout << "Vous passez par la case depart et recevez 200 monos." << endl;
            addSolde(200);
        }

        cout << "Nouvelle position: " << position << endl;

        Case* caseActuelle = plateau.getCase(position);

        if (caseActuelle) {
            cout << "Vous etes sur la case: " << caseActuelle->getNom() << endl;
            //cout << "Type de la case: " << typeid(*caseActuelle).name() << endl;
            //caseActuelle->actioncase(*this);

            if (typeid(*caseActuelle) == typeid(Case_NonAchetable)) {
                dynamic_cast<Case_NonAchetable*>(caseActuelle)->actioncase(*this, joueurs);
            } else if (typeid(*caseActuelle) == typeid(CaseTerrain)) {
                dynamic_cast<CaseTerrain*>(caseActuelle)->actioncase(*this, joueurs,plateau);
            } else if (typeid(*caseActuelle) == typeid(Gare)) {
                dynamic_cast<Gare*>(caseActuelle)->actioncase(*this, joueurs);
            } else if (typeid(*caseActuelle) == typeid(Service_Public)) {
                dynamic_cast<Service_Public*>(caseActuelle)->actioncase(*this, joueurs);
            } else {
                cout << "Type de case inconnu." << endl;
            }
        } else {
            cout << "Erreur: case non trouvée." << endl;
        }
    }
}

/**
 * @brief Accède au dernier résultat des dés.
 * @return Résultat du lancer de dés.
 */
int Joueur::getDes() const
{
    return des;
}

/**
 * @brief Définit le dernier résultat des dés.
 * @param des Résultat à enregistrer.
 */
void Joueur::setDes(int des)
{
    this->des = des;
}

/**
 * @brief Récupère le nombre de services publics possédés.
 * @return Nombre de services publics.
 */
int Joueur::getNbServices() const
{
    return nb_services;
}

/**
 * @brief Définit le nombre de services publics possédés.
 * @param nb_services Nombre de services publics.
 */
void Joueur::setNbServices(int nb_services)
{
    this->nb_services = nb_services;
}

/**
 * @brief Incrémente le compteur des services publics possédés.
 */
void Joueur::incrementNbServices()
{
    nb_services++;
}

/**
 * @brief Récupère le nombre de gares possédées par le joueur.
 * @return Nombre de gares possédées.
 */
int Joueur::getNbGares() const
{
    return nb_gares;
}

/**
 * @brief Définit le nombre de gares possédées par le joueur.
 * @param nb_gares Nombre de gares.
 */
void Joueur::setNbGares(int nb_gares)
{
    this->nb_gares = nb_gares;
}

/**
 * @brief Vérifie si le joueur est encore en vie.
 * @return `true` si le joueur est actif, sinon `false`.
 */
bool Joueur::geten_vie() const
{
    return en_vie;
}

/**
 * @brief Définit le statut de vie du joueur.
 * @param en_vie `true` si le joueur est actif, sinon `false`.
 */
void Joueur::seten_vie(bool en_vie)
{
    this->en_vie = en_vie;
}

/**
 * @brief Récupère le nom du joueur.
 * @return Nom du joueur.
 */
string Joueur::getNom() const
{
    return nom;
}

/**
 * @brief Modifie le nom du joueur.
 * @param nom Nouveau nom du joueur.
 */
void Joueur::setNom(string nom)
{
    this->nom = nom;
}

/**
 * @brief Récupère le solde d'argent du joueur.
 * @return Solde actuel.
 */
int Joueur::getSolde() const
{
    return solde;
}

/**
 * @brief Définit le solde d'argent du joueur.
 * @param solde Nouveau montant.
 */
void Joueur::setSolde(int solde)
{
    this->solde = solde;
}

/**
 * @brief Ajoute un montant au solde du joueur.
 * @param add Montant à ajouter (peut être négatif).
 */
void Joueur::addSolde(int add)
{
    this->solde = this->solde + add;
}

/**
 * @brief Récupère la position actuelle du joueur.
 * @return Position sur le plateau.
 */
int Joueur::getPosition() const
{
    return position;
}

/**
 * @brief Modifie la position actuelle du joueur.
 * @param position Nouvelle position.
 */
void Joueur::setPosition(int position)
{
    this->position = position;
}

/**
 * @brief Récupère le nombre de cartes "Libéré de prison" du joueur.
 * @return Nombre de cartes en possession.
 */
int Joueur::getNbCartesLiberte() const
{
    return nb_cartes_liberte;
}

/**
 * @brief Modifie le nombre de cartes "Libéré de prison" du joueur.
 * @param nb_cartes_liberte Nouveau nombre de cartes.
 */
void Joueur::setNbCartesLiberte(int nb_cartes_liberte)
{
    this->nb_cartes_liberte = nb_cartes_liberte;
}

/**
 * @brief Vérifie si le joueur est en prison.
 * @return `true` si le joueur est en prison, sinon `false`.
 */
bool Joueur::getEnPrison() const
{
    return en_prison;
}

/**
 * @brief Modifie le statut de prison du joueur.
 * @param en_prison `true` pour mettre en prison, sinon `false`.
 */
void Joueur::setEnPrison(bool en_prison)
{
    this->en_prison = en_prison;
}

/**
 * @brief Récupère le nombre de tours passés en prison par le joueur.
 * @return Nombre de tours en prison.
 */
int Joueur::getToursEnPrison() const
{
    return tours_en_prison;
}

/**
 * @brief Définit le nombre de tours passés en prison par le joueur.
 * @param tours Nouveau nombre de tours.
 */
void Joueur::setToursEnPrison(int tours)
{
    this->tours_en_prison = tours;
}

/**
 * @brief Incrémente le compteur de tours en prison.
 */
void Joueur::incrementerToursEnPrison()
{
    this->tours_en_prison++;
}