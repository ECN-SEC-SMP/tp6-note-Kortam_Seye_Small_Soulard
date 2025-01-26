#ifndef SERVICE_PUBLIC_H
#define SERVICE_PUBLIC_H

#include <vector>
#include "case.hpp"
#include "Case_Achetable.hpp"
#include "joueur.hpp"
#include <iostream>
using namespace std;

/**
 * @class Service_Public
 * @brief Représente une case de service public dans le jeu de Monopoly.
 * 
 * Cette classe hérite de `Case_Achetable` et gère les interactions spécifiques aux services publics, 
 * tels que les loyers variables basés sur les dés et le nombre de services possédés par le propriétaire.
 */
class Service_Public : public Case_Achetable {
protected:
    int loyer; ///< Loyer de la case, déterminé par des règles dynamiques.

public:
    /**
     * @brief Constructeur de la classe Service_Public.
     * 
     * @param loyer Loyer initial du service public.
     */
    Service_Public(int loyer);

    /**
     * @brief Réalise l'action à effectuer lorsqu'un joueur arrive sur cette case.
     * 
     * Si le service a un propriétaire, calcule le loyer dû et transfère les fonds. 
     * Sinon, propose au joueur d'acheter la propriété.
     * 
     * @param joueur Référence au joueur actif.
     * @param joueurs Liste des joueurs du jeu.
     */
    void actioncase(Joueur& joueur, vector<Joueur>& joueurs);
};

#endif  // SERVICE_PUBLIC_H
