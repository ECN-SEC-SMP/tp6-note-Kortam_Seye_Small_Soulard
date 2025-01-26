#ifndef GARE_H
#define GARE_H

#include "case.hpp"
#include "Case_Achetable.hpp"
#include "joueur.hpp"
#include <vector>
#include <iostream>

using namespace std;

/**
 * @class Gare
 * @brief Classe représentant une gare, une case achetable dans le jeu.
 * 
 * Les gaires ont un loyer qui dépend du nombre de gares possédées par un joueur.
 */
class Gare : public Case_Achetable {
protected:
    int loyer; ///< Le montant du loyer.

public:
    /**
     * @brief Constructeur de la classe Gare.
     * 
     * @param loyer Le montant du loyer associé à la gare.
     */
    Gare(int loyer);

    /**
     * @brief Gère l'action d'un joueur lorsqu'il atterrit sur la gare.
     * 
     * Si le joueur atterrit sur une gare déjà possédée, il doit payer un loyer au propriétaire.
     * Si la gare n'est pas encore achetée, le joueur peut choisir de l'acheter.
     * 
     * @param joueur Le joueur qui atterrit sur la gare.
     * @param joueurs Liste des joueurs du jeu.
     */
    void actioncase(Joueur& joueur, vector<Joueur>& joueurs);
};

#endif // GARE_H
