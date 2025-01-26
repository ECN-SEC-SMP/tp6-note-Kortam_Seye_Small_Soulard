#ifndef PLATEAU_H
#define PLATEAU_H

#include "case.hpp"
#include "joueur.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace std;

/**
 * @class Plateau
 * @brief Classe représentant le plateau de jeu Monopoly.
 * 
 * Gère les cases du plateau ainsi que les joueurs, et contrôle le déroulement du jeu.
 */
class Plateau {
public:
    /**
     * @brief Initialise le plateau de jeu avec les joueurs donnés.
     * 
     * @param joueurs Vecteur des joueurs participants.
     */
    void initialiser(const vector<Joueur>& joueurs);

    /**
     * @brief Commence la boucle principale du jeu, permettant aux joueurs de jouer leurs tours.
     */
    void commencerJeu();

    /**
     * @brief Récupère une case par son index.
     * 
     * @param index Index de la case à récupérer.
     * @return Pointeur vers la case si l'index est valide, sinon nullptr.
     */
    Case* getCase(int index) const;

private:
    vector<Joueur> joueurs; ///< Liste des joueurs participants.
    vector<unique_ptr<Case>> cases; ///< Liste des cases du plateau.
};

#endif // PLATEAU_H
