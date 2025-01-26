#ifndef CASEACHETABLE_HPP
#define CASEACHETABLE_HPP

#include "Case.hpp"
#include <string>
#include <iostream>

using namespace std; 

/**
 * @class Case_Achetable
 * @brief Une classe représentant une propriété achetable dans le jeu.
 * 
 * La classe Case_Achetable hérite de la classe Case. Elle inclut des attributs
 * comme le propriétaire, le prix et l'état hypothécaire.
 */
class Case_Achetable: public Case
{
private:
    string proprio; ///< Propriétaire de la case.
    int prix;       ///< Prix de la case.
    bool hypo;      ///< Statut hypothécaire de la case.

public:
    /**
     * @brief Constructeur par défaut de Case_Achetable.
     * 
     * Initialise la case avec des valeurs par défaut : pas de propriétaire, prix nul, et non hypothéquée.
     */
    Case_Achetable();

    /**
     * @brief Constructeur paramétré de Case_Achetable.
     * 
     * @param proprio Le propriétaire de la case.
     * @param prix Le prix de la case.
     * @param hypo Le statut hypothécaire de la case (true si hypothéquée, false sinon).
     */
    Case_Achetable(string proprio, int prix, bool hypo);

    /**
     * @brief Destructeur de Case_Achetable.
     * 
     * Détruit les ressources utilisées par l'objet.
     */
    ~Case_Achetable();

    /**
     * @brief Définit le propriétaire de la case.
     * 
     * @param proprio Le nouveau propriétaire de la case.
     */
    void setProprio(string proprio);

    /**
     * @brief Retourne le propriétaire de la case.
     * 
     * @return Le propriétaire actuel de la case.
     */
    string getProprio() const;

    /**
     * @brief Définit le prix de la case.
     * 
     * @param prix Le nouveau prix de la case.
     */
    void setPrix(int prix);

    /**
     * @brief Retourne le prix de la case.
     * 
     * @return Le prix actuel de la case.
     */
    int getPrix() const;

    /**
     * @brief Définit le statut hypothécaire de la case.
     * 
     * @param hypo Le nouveau statut hypothécaire (true si hypothéquée, false sinon).
     */
    void setHypo(bool hypo);

    /**
     * @brief Retourne le statut hypothécaire de la case.
     * 
     * @return Le statut hypothécaire actuel (true si hypothéquée, false sinon).
     */
    bool getHypo() const;
};

#endif // CASEACHETABLE_HPP
