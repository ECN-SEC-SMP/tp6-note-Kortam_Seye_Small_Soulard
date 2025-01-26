#ifndef Case_Achetable_hpp
#define Case_Achetable_hpp

#include "Case.hpp"
#include "Case_Achetable.hpp"

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Constructeur par défaut de Case_Achetable.
 * 
 * Initialise la case avec des valeurs par défaut : pas de propriétaire, prix nul, et non hypothéquée.
 */
Case_Achetable::Case_Achetable() : proprio(""), prix(0), hypo(false) {}

/**
 * @brief Constructeur paramétré de Case_Achetable.
 * 
 * @param proprio Le propriétaire de la case.
 * @param prix Le prix de la case.
 * @param hypo Le statut hypothécaire de la case.
 */
Case_Achetable::Case_Achetable(string proprio, int prix, bool hypo) : proprio(proprio), prix(prix), hypo(hypo) {}

/**
 * @brief Destructeur de Case_Achetable.
 */
Case_Achetable::~Case_Achetable() {}

/**
 * @brief Définit le propriétaire de la case.
 * 
 * @param _proprio Le nouveau propriétaire de la case.
 */
void Case_Achetable::setProprio(string _proprio) {
    proprio = _proprio;
}

/**
 * @brief Retourne le propriétaire de la case.
 * 
 * @return Le propriétaire actuel de la case.
 */
string Case_Achetable::getProprio() const {
    return proprio;
}

/**
 * @brief Définit le prix de la case.
 * 
 * @param _prix Le nouveau prix de la case.
 */
void Case_Achetable::setPrix(int _prix) {
    prix = _prix;
}

/**
 * @brief Retourne le prix de la case.
 * 
 * @return Le prix actuel de la case.
 */
int Case_Achetable::getPrix() const {
    return prix;
}

/**
 * @brief Définit le statut hypothécaire de la case.
 * 
 * @param _hypo Le nouveau statut hypothécaire (true si hypothéquée, false sinon).
 */
void Case_Achetable::setHypo(bool _hypo) {
    hypo = _hypo;
}

/**
 * @brief Retourne le statut hypothécaire de la case.
 * 
 * @return Le statut hypothécaire actuel (true si hypothéquée, false sinon).
 */
bool Case_Achetable::getHypo() const {
    return hypo;
}

#endif
