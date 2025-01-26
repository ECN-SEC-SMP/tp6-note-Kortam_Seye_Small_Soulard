#ifndef Case_hpp
#define Case_hpp

#include <iostream>
#include <string>

using namespace std; 

/**
 * @class Case
 * @brief Classe de base représentant une case du plateau de jeu.
 * 
 * Cette classe est la classe mère pour toutes les cases (achetables ou non) du plateau.
 */
class Case {
protected:
    string nom; ///< Nom de la case.
    int numero; ///< Numéro de la case.
public:
    /**
     * @brief Constructeur paramétré.
     * 
     * @param nom Nom de la case.
     */
    explicit Case(const string& nom);

    /**
     * @brief Constructeur par défaut.
     */
    Case();

    /**
     * @brief Destructeur virtuel par défaut.
     */
    virtual ~Case() = default;


    /**
     * @brief Accesseur pour le nom de la case.
     * @return Le nom de la case.
     */
    string getNom() const;


    /**
     * @brief Mutateur pour le nom de la case.
     * 
     * @param nom Le nouveau nom de la case.
     */
    void setNom(const string& nom);

    /**
     * @brief Accesseur pour le numéro de la case.
     * @return Le numéro de la case.
     */
    int getNumero() const;

    /**
     * @brief Mutateur pour le numéro de la case.
     * 
     * @param numero Le nouveau numéro de la case.
     */
    void setNumero(int numero);
};


#endif
