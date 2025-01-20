#ifndef NON_ACHETABLE_H
#define NON_ACHETABLE_H

#include <string>
#include <iostream>
#include "Joueur.h"  // Inclure votre classe Joueur si nécessaire

/**
 * @class NonAchetable
 * @brief Représente une case non achetable dans le jeu (comme Départ, Prison, etc.).
 */
class NonAchetable : public Case {
public:
    /**
     * @enum TypeCaseNonAchetable
     * @brief Types de cases non achetables dans le jeu.
     */
    enum class TypeCaseNonAchetable {
        DEPART, /**< Case Départ */
        PRISON, /**< Case Prison */
        ALLEZ_EN_PRISON, /**< Case Allez en Prison */
        CHANCE, /**< Case Chance */
        CAISSE_DE_COMMUNAUTE, /**< Case Caisse de Communauté */
        IMPOT, /**< Case Impôt */
        TAXE_DE_LUXE, /**< Case Taxe de Luxe */
        PARC_GRATUIT /**< Case Parc Gratuit */
    };

    /**
     * @brief Constructeur de la classe NonAchetable.
     * @param nom Le nom de la case.
     * @param type_case Le type de la case (défini par l'énumération TypeCaseNonAchetable).
     */
    NonAchetable(const std::string& nom, TypeCaseNonAchetable type_case);

    /**
     * @brief Effectue l'action associée à la case.
     * @param joueur Le joueur qui passe sur la case.
     */
    void action(Joueur& joueur);

private:
    TypeCaseNonAchetable type_case; /**< Le type de la case non achetable */

    /**
     * @brief Convertit un type de case en une chaîne de caractères.
     * @param type Le type de la case.
     * @return La chaîne de caractères représentant le type de case.
     */
    static const char* typeToString(TypeCaseNonAchetable type);
};

#endif
