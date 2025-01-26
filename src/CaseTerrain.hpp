#ifndef CASETERRAIN_H
#define CASETERRAIN_H

#include <iostream>
#include <vector>
#include "Case.hpp"
#include "Case_Achetable.hpp"
#include "joueur.hpp"
#include "plateau.hpp"

/**
 * @class CaseTerrain
 * @brief Classe représentant une case achetable de type terrain.
 * 
 * Les terrains peuvent être achetés, construits, et génèrent un loyer en fonction des propriétés.
 */
class CaseTerrain : public Case_Achetable {
private:
    int loyer;        ///< Le loyer de la case.
    int groupe;       ///< Groupe auquel appartient la case.
    int construction; ///< Nombre de constructions sur la case (maisons/hôtels).

public:
    /**
     * @brief Constructeur paramétré.
     * 
     * @param loyer Le loyer de base de la case.
     * @param groupe Le groupe auquel appartient le terrain.
     * @param construction Le nombre initial de constructions.
     */
    CaseTerrain(int loyer, int groupe, int construction);

    /**
     * @brief Constructeur par défaut.
     */
    CaseTerrain();

    /**
     * @brief Déclenche l'action associée à la case terrain.
     * 
     * Détermine le comportement en fonction de la propriété du terrain 
     * (payer un loyer ou acheter la case si disponible).
     * 
     * @param joueur Le joueur actif.
     * @param joueurs Liste des joueurs présents sur le plateau.
     * @param plateau Référence au plateau de jeu pour vérifier les propriétés du groupe.
     */
    void actioncase(Joueur& joueur, std::vector<Joueur>& joueurs, Plateau& plateau);

    /**
     * @brief Accesseur pour le loyer de la case.
     * 
     * @return Le loyer de la case.
     */
    int getLoyer() const;

    /**
     * @brief Mutateur pour le loyer de la case.
     * 
     * @param loyer La nouvelle valeur du loyer.
     */
    void setLoyer(int loyer);

    /**
     * @brief Accesseur pour le groupe de la case.
     * 
     * @return L'identifiant du groupe auquel appartient la case.
     */
    int getGroupe() const;

    /**
     * @brief Définit le groupe auquel appartient la case.
     * 
     * @param groupe L'identifiant du groupe.
     */
    void setGroupe(int groupe);

    /**
     * @brief Accesseur pour le nombre de constructions sur la case.
     * 
     * @return Le nombre de constructions sur la case.
     */
    int getConstruction() const;

    /**
     * @brief Définit le nombre de constructions sur la case.
     * 
     * @param construction Le nouveau nombre de constructions.
     */
    void setConstruction(int construction);
};

#endif // CASETERRAIN_H
