
#include "Case.hpp"
#include <iostream>

using namespace std;


/**
 * @brief Constructeur paramétré.
 * 
 * Initialise une case avec un nom spécifique.
 * 
 * @param nom Nom de la case.
 */
Case::Case(const string& nom) : nom(nom) {}

/**
 * @brief Constructeur par défaut.
 * 
 * Initialise une case avec un nom vide.
 */
Case::Case() : nom("") {}

/*void Case::action() const {
    cout << "Case neutre : aucun effet.\n";
}*/

/**
 * @brief Accesseur pour le nom de la case.
 * 
 * @return Le nom de la case.
 */
string Case::getNom() const {
    return nom;
}

/**
 * @brief Mutateur pour le nom de la case.
 * 
 * @param nom Le nouveau nom de la case.
 */
void Case::setNom(const std::string& nom) {
    this->nom = nom;
}
