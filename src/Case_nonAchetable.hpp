#ifndef CASE_NONACHETABLE_H
#define CASE_NONACHETABLE_H

#include <string>
#include <iostream>
#include "joueur.hpp" 
#include <vector>

/**
 * @class Case_NonAchetable
 * @brief Une classe représentant une case non achetable dans le jeu.
 * 
 * Les cases non achetables ont un type spécifique (par exemple, Départ, Prison, etc.)
 * et déclenchent des actions spécifiques lorsqu'un joueur atterrit dessus.
 */
class Case_NonAchetable: public Case 
{
public:
    /**
     * @brief Énumération représentant les types de cases non achetables.
     */
    enum class TypeCaseNonAchetable {
        DEPART,            ///< Case Départ.
        PRISON,            ///< Case Prison.
        ALLEZ_EN_PRISON,   ///< Case Allez en Prison.
        CHANCE,            ///< Case Chance.
        CAISSE_DE_COMMUNAUTE, ///< Case Caisse de Communauté.
        IMPOT,             ///< Case Impôt.
        TAXE_DE_LUXE,      ///< Case Taxe de Luxe.
        PARC_GRATUIT       ///< Case Parc Gratuit.
    };

    /**
     * @brief Constructeur de la classe Case_NonAchetable.
     * 
     * @param nom Le nom de la case.
     * @param type_case Le type de la case (parmi les types définis dans l'énumération TypeCaseNonAchetable).
     */
    Case_NonAchetable(const std::string& nom, TypeCaseNonAchetable type_case);

    /**
     * @brief Déclenche l'action associée à la case.
     * 
     * Cette méthode définit les effets spécifiques de la case sur le joueur actif
     * et, dans certains cas, sur les autres joueurs.
     * 
     * @param joueur Le joueur actif.
     * @param joueurs La liste des joueurs dans le jeu.
     */
    void actioncase(Joueur& joueur, std::vector<Joueur>& joueurs);

private:
    TypeCaseNonAchetable type_case; ///< Le type de la case.

    /**
     * @brief Convertit le type de case en chaîne de caractères.
     * 
     * @param type Le type de la case.
     * @return Une chaîne de caractères représentant le type de la case.
     */
    static const char* typeToString(TypeCaseNonAchetable type);
};

#endif // CASE_NONACHETABLE_H
