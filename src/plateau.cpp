
#include "case.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void Plateau::initialiser(const vector<Joueur> &Joueurs)
{
    joueurs = Joueurs; // initialise le tableau de joueurs

    // ici faut recuperer les cases
    cout << "Plateau initialise avec " << cases.size() << " cases." << endl;
}


void Plateau::commencerJeu()
{
    bool jeuTermine = false;
    int tour = 0;

    while (!jeuTermine)
    {
        cout << "\n\n======== Tour " << tour + 1 << " ========" << endl;
        for (auto &joueur : joueurs)
        { // pour chaque joueur
            if (joueur.geten_vie())
            {
                continue;
            }
            cout <<"\n"<< joueur.getNom() << ", c'est votre tour." << endl;
            joueur.jouerTour();

            if (joueur.getSolde() <= 0)
            {
                joueur.seten_vie(false);
                cout << joueur.getNom() << " est en faillite !" << endl;
                int joueursRestants = 0; // compte le nombre de joueurs restants
                for (const auto &joueur : joueurs)
                {
                    if (joueur.geten_vie())
                    {
                        ++joueursRestants;
                    }
                }
                // si il reste un joueur ou moins, le jeu est termine
                if (joueursRestants <= 1)
                {
                    jeuTermine = true;
                    for (const auto &joueur : joueurs)
                    {
                        if (joueur.geten_vie())
                        { // si le joueur n'est pas en faillite
                            cout << "\nFelicitations, " << joueur.getNom() << " a gagne la partie !" << endl;
                            break;
                        }
                    }
                }

            }


        }
        ++tour;
        cout << "\n"<< "Fin du tour " << tour << ". ";
        for (const auto &joueur : joueurs)
        {
            cout <<"\n"<< joueur.getNom() << " a " << joueur.getSolde() << "monos ";
        }
        cout << endl;
    }


}
