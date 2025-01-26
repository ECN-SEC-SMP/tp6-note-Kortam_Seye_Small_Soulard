#ifndef joueur_hpp
#define joueur_hpp
#include "case.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Déclaration anticipée de la classe Plateau
class Plateau;


/**
 * @class Joueur
 * @brief Représente un joueur dans le jeu Monopoly.
 *
 * Chaque joueur possède des attributs tels que le nom, le solde, la position sur le plateau,
 * les cartes de liberté, et la capacité à acheter des propriétés comme les terrains, les gares, etc.
 */
class Joueur{
    private :
        bool en_vie;           ///< Statut de vie du joueur.
        string nom;            ///< Nom du joueur.
        int solde;             ///< Solde actuel du joueur.
        int position;          ///< Position actuelle du joueur sur le plateau.
        int nb_cartes_liberte; ///< Nombre de cartes de liberté.
        int nb_gares;          ///< Nombre de gares possédées par le joueur.
        int des;               ///< Dernier résultat du lancement de dés.
        int nb_services;       ///< Nombre de services publics possédés par le joueur.
        int tours_en_prison;   ///< Nombre de tours que le joueur a passé en prison.
        bool en_prison;        ///< Si le joueur est en prison ou non.

    public : 
        /**
         * @brief Constructeur par défaut.
         * 
         * Initialise un joueur avec un solde de 1500 monos, la position 0, et aucune carte de liberté, gare ou service.
         */
        Joueur();

        /**
         * @brief Constructeur personnalisé pour créer un joueur avec des informations spécifiques.
         * 
         * @param en_vie Statut de vie du joueur.
         * @param nom Nom du joueur.
         * @param solde Solde initial du joueur.
         * @param position Position initiale du joueur.
         * @param nb_cartes_liberte Nombre de cartes de liberté du joueur.
         * @param en_prison Si le joueur est en prison.
         */
        Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison);

        // Getters et setters pour les attributs
        bool geten_vie() const;
        void seten_vie(bool en_vie);
        string getNom() const;
        void setNom(string nom);
        int getSolde() const;
        void setSolde(int solde);
        void addSolde(int add);
        int getPosition() const;
        void setPosition(int position);
        int getNbCartesLiberte() const;
        void setNbCartesLiberte(int nb_cartes_liberte);
        bool getEnPrison() const;
        void setEnPrison(bool en_prison);
        void jouerTour(Plateau& plateau, vector<Joueur>& joueurs);
        void construire(Case& Case);
        int* lancer_des(void);
        int getNbGares() const;
        void setNbGares(int nb_gares);
        int getDes() const;
        void setDes(int des);
        int getNbServices() const;
        void setNbServices(int nb_services);
        void incrementNbServices();
        int getToursEnPrison() const;
        void setToursEnPrison(int tours);
        void incrementerToursEnPrison();

};

#endif // joueur_hpp

