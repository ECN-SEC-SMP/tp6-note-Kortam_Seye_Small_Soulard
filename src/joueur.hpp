#ifndef joueur_hpp
#define joueur_hpp

#include "case.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

// Déclaration anticipée de la classe Plateau
class Plateau;

/**
 * @class Joueur
 * @brief Représente un joueur dans le jeu.
 * 
 * Cette classe contient toutes les informations relatives à un joueur telles que son solde,
 * sa position sur le plateau, son statut (en vie, en prison) et ses cartes de liberté.
 * Elle inclut aussi des méthodes permettant au joueur de jouer un tour, de se déplacer
 * sur le plateau, de gérer ses finances et d'interagir avec les cases du plateau.
 */
class Joueur {
private:
    bool en_vie;                ///< Indique si le joueur est en vie.
    string nom;                 ///< Nom du joueur.
    int solde;                  ///< Solde du joueur.
    int position;               ///< Position actuelle du joueur sur le plateau.
    int nb_cartes_liberte;     ///< Nombre de cartes "liberté" que possède le joueur.
    bool en_prison;             ///< Indique si le joueur est en prison.

public:
    /**
     * @brief Constructeur par défaut du joueur.
     */
    Joueur();

    /**
     * @brief Constructeur pour initialiser un joueur avec des valeurs données.
     * 
     * @param en_vie Statut du joueur : est-il en vie ?
     * @param nom Nom du joueur.
     * @param solde Le solde initial du joueur.
     * @param position Position initiale du joueur sur le plateau.
     * @param nb_cartes_liberte Nombre de cartes "liberté" possédées par le joueur.
     * @param en_prison Statut de prison du joueur : est-il en prison ?
     */
    Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison);

    // Getters et Setters

    /**
     * @brief Retourne si le joueur est en vie.
     * 
     * @return true si le joueur est en vie, sinon false.
     */
    bool geten_vie() const;

    /**
     * @brief Modifie le statut de vie du joueur.
     * 
     * @param en_vie Statut du joueur (true = en vie, false = mort).
     */
    void seten_vie(bool en_vie);

    /**
     * @brief Retourne le nom du joueur.
     * 
     * @return Le nom du joueur.
     */
    string getNom() const;

    /**
     * @brief Modifie le nom du joueur.
     * 
     * @param nom Le nouveau nom du joueur.
     */
    void setNom(string nom);

    /**
     * @brief Retourne le solde du joueur.
     * 
     * @return Le solde du joueur.
     */
    int getSolde() const;

    /**
     * @brief Modifie le solde du joueur.
     * 
     * @param solde Le nouveau solde du joueur.
     */
    void setSolde(int solde);

    /**
     * @brief Ajoute un montant au solde du joueur.
     * 
     * @param add Le montant à ajouter.
     */
    void addSolde(int add);

    /**
     * @brief Retourne la position du joueur sur le plateau.
     * 
     * @return La position actuelle du joueur.
     */
    int getPosition() const;

    /**
     * @brief Modifie la position du joueur sur le plateau.
     * 
     * @param position La nouvelle position du joueur.
     */
    void setPosition(int position);

    /**
     * @brief Retourne le nombre de cartes "liberté" du joueur.
     * 
     * @return Le nombre de cartes "liberté" du joueur.
     */
    int getNbCartesLiberte() const;

    /**
     * @brief Modifie le nombre de cartes "liberté" du joueur.
     * 
     * @param nb_cartes_liberte Le nouveau nombre de cartes "liberté".
     */
    void setNbCartesLiberte(int nb_cartes_liberte);

    /**
     * @brief Retourne si le joueur est en prison.
     * 
     * @return true si le joueur est en prison, sinon false.
     */
    bool getEnPrison() const;

    /**
     * @brief Modifie le statut de prison du joueur.
     * 
     * @param en_prison Le statut de prison (true = en prison, false = non en prison).
     */
    void setEnPrison(bool en_prison);

    /**
     * @brief Effectue un tour pour le joueur, impliquant de lancer les dés et se déplacer.
     * 
     * Cette méthode gère le déplacement du joueur sur le plateau et fait en sorte que le joueur
     * réagisse en fonction de la case sur laquelle il se trouve. Si le joueur fait trois doubles consécutifs,
     * il est envoyé en prison.
     * 
     * @param plateau Référence du plateau sur lequel se trouve le joueur.
     */
    void jouerTour(Plateau& plateau);

    /**
     * @brief Méthode permettant au joueur de construire une maison sur une case.
     * 
     * @param Case Référence de la case où construire une maison.
     */
    void construire(Case& Case);

    /**
     * @brief Lance les dés pour déterminer la somme des résultats.
     * 
     * @return Un tableau de deux entiers représentant les résultats des deux dés.
     */
    int* lancer_des(void);
};

#endif // joueur_hpp
