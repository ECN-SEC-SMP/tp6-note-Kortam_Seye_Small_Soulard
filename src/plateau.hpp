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
 * @brief This class manages the game board, player actions, and the game flow.
 */
class Plateau {
public:
    /**
     * @brief Initializes the game board with predefined cases and players.
     * 
     * @param Joueurs A list of players for the game.
     */
    void initialiser(const vector<Joueur> &Joueurs);

    /**
     * @brief Starts the game and manages the flow of turns for each player.
     * 
     * The game continues until there is a winner or all players are bankrupt.
     */
    void commencerJeu();

    /**
     * @brief Retrieves a pointer to a case on the board by its index.
     * 
     * @param index The index of the desired case on the board.
     * @return Case* A pointer to the case at the specified index, or nullptr if invalid.
     */
    Case* getCase(int index) const;

private:
    vector<Joueur> joueurs;                ///< List of players in the game.
    vector<unique_ptr<Case>> cases;         ///< List of unique pointers to cases (game board tiles).
};

#endif // PLATEAU_H
