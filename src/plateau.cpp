#include "case.hpp"
#include "CaseTerrain.hpp"
#include "Case_nonAchetable.hpp"
#include "Gare.hpp"
#include "Service_Public.hpp"
#include "joueur.hpp"
#include "plateau.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

void Plateau::initialiser(const vector<Joueur> &Joueurs,const vector<Case> &Cases)
{
    joueurs = Joueurs; // initialise le tableau de joueurs
    
    
    cases = Cases;     // initialise le tableau de cases
    /*
    // Case 0: Départ
    cases[0] = Case_NonAchetable("Depart", Case_NonAchetable::TypeCaseNonAchetable::DEPART);
    
    // Case 1: Boulevard de Belleville
    cases[1] = CaseTerrain(60, 1, 0);
    cases[1].setNom("Boulevard de Belleville");
    cases[1].setPrix(60);
    cases[1].setProprio("");
    cases[1].setHypo(false);
    
    // Case 2: Caisse de Communauté
    cases[2] = Case_NonAchetable("Caisse de Communauté", Case_NonAchetable::TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE);
    
    // Case 3: Rue Lecourbe
    cases[3] = CaseTerrain(60, 1, 0);
    cases[3].setNom("Rue Lecourbe");
    cases[3].setPrix(60);
    cases[3].setProprio("");
    cases[3].setHypo(false);

    // Case 4: Impôts
    cases[4] = Case_NonAchetable("Impôts", Case_NonAchetable::TypeCaseNonAchetable::IMPOT);
    
    // Case 5: Gare Montparnasse
    cases[5] = Gare(200);
    cases[5].setNom("Gare Montparnasse");
    cases[5].setPrix(200);
    cases[5].setProprio("");
    cases[5].setHypo(false);

    // Case 6: Rue de Vaugirard
    cases[6] = CaseTerrain(100, 2, 0);
    cases[6].setNom("Rue de Vaugirard");
    cases[6].setPrix(100);
    cases[6].setProprio("");
    cases[6].setHypo(false);

    // Case 7: Carte Chance
    cases[7] = Case_NonAchetable("Carte Chance", Case_NonAchetable::TypeCaseNonAchetable::CHANCE);
    
    // Case 8: Rue de Courcelles
    cases[8] = CaseTerrain(100, 2, 0);
    cases[8].setNom("Rue de Courcelles");
    cases[8].setPrix(100);
    cases[8].setProprio("");
    cases[8].setHypo(false);

    // Case 9: Avenue de la République
    cases[9] = CaseTerrain(120, 2, 0);
    cases[9].setNom("Avenue de la République");
    cases[9].setPrix(120);
    cases[9].setProprio("");
    cases[9].setHypo(false);

    // Case 10: Prison
    cases[10] = Case_NonAchetable("Prison", Case_NonAchetable::TypeCaseNonAchetable::PRISON);
    
    // Case 11: Boulevard de la Villette
    cases[11] = CaseTerrain(140, 3, 0);
    cases[11].setNom("Boulevard de la Villette");
    cases[11].setPrix(140);
    cases[11].setProprio("");
    cases[11].setHypo(false);

    // Case 12: Compagnie de l'Électricité
    cases[12] = Service_Public(150);
    cases[12].setNom("Compagnie de l'Électricité");
    cases[12].setPrix(150);
    cases[12].setProprio("");
    cases[12].setHypo(false);

    // Case 13: Avenue de Neuilly
    cases[13] = CaseTerrain(140, 3, 0);
    cases[13].setNom("Avenue de Neuilly");
    cases[13].setPrix(140);
    cases[13].setProprio("");
    cases[13].setHypo(false);

    // Case 14: Rue du Paradis
    cases[14] = CaseTerrain(160, 3, 0);
    cases[14].setNom("Rue du Paradis");
    cases[14].setPrix(160);
    cases[14].setProprio("");
    cases[14].setHypo(false);

    // Case 15: Gare de Lyon
    cases[15] = Gare(200);
    cases[15].setNom("Gare de Lyon");
    cases[15].setPrix(200);
    cases[15].setProprio("");
    cases[15].setHypo(false);

    // Case 16: Avenue Mozart
    cases[16] = CaseTerrain(180, 4, 0);
    cases[16].setNom("Avenue Mozart");
    cases[16].setPrix(180);
    cases[16].setProprio("");
    cases[16].setHypo(false);

    // Case 17: Caisse de Communauté
    cases[17] = Case_NonAchetable("Caisse de Communauté", Case_NonAchetable::TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE);
    
    // Case 18: Boulevard Saint-Michel
    cases[18] = CaseTerrain(180, 4, 0);
    cases[18].setNom("Boulevard Saint-Michel");
    cases[18].setPrix(180);
    cases[18].setProprio("");
    cases[18].setHypo(false);

    // Case 19: Place Pigalle
    cases[19] = CaseTerrain(200, 4, 0);
    cases[19].setNom("Place Pigalle");
    cases[19].setPrix(200);
    cases[19].setProprio("");
    cases[19].setHypo(false);

    // Case 20: Parc Gratuit
    cases[20] = Case_NonAchetable("Parc Gratuit", Case_NonAchetable::TypeCaseNonAchetable::PARC_GRATUIT);
    
    // Case 21: Avenue Matignon
    cases[21] = CaseTerrain(220, 5, 0);
    cases[21].setNom("Avenue Matignon");
    cases[21].setPrix(220);
    cases[21].setProprio("");
    cases[21].setHypo(false);

    // Case 22: Carte Chance
    cases[22] = Case_NonAchetable("Carte Chance", Case_NonAchetable::TypeCaseNonAchetable::CHANCE);
    
    // Case 23: Boulevard Malesherbes
    cases[23] = CaseTerrain(220, 5, 0);
    cases[23].setNom("Boulevard Malesherbes");
    cases[23].setPrix(220);
    cases[23].setProprio("");
    cases[23].setHypo(false);

    // Case 24: Avenue Henri-Martin
    cases[24] = CaseTerrain(240, 5, 0);
    cases[24].setNom("Avenue Henri-Martin");
    cases[24].setPrix(240);
    cases[24].setProprio("");
    cases[24].setHypo(false);

    // Case 25: Gare du Nord
    cases[25] = Gare(200);
    cases[25].setNom("Gare du Nord");
    cases[25].setPrix(200);
    cases[25].setProprio("");
    cases[25].setHypo(false);

    // Case 26: Faubourg Saint-Honoré
    cases[26] = CaseTerrain(260, 6, 0);
    cases[26].setNom("Faubourg Saint-Honoré");
    cases[26].setPrix(260);
    cases[26].setProprio("");
    cases[26].setHypo(false);

    // Case 27: Place de la Bourse
    cases[27] = CaseTerrain(260, 6, 0);
    cases[27].setNom("Place de la Bourse");
    cases[27].setPrix(260);
    cases[27].setProprio("");
    cases[27].setHypo(false);

    // Case 28: Compagnie des Eaux
    cases[28] = Service_Public(150);
    cases[28].setNom("Compagnie des Eaux");
    cases[28].setPrix(150);
    cases[28].setProprio("");
    cases[28].setHypo(false);

    // Case 29: Rue La Fayette
    cases[29] = CaseTerrain(280, 6, 0);
    cases[29].setNom("Rue La Fayette");
    cases[29].setPrix(280);
    cases[29].setProprio("");
    cases[29].setHypo(false);

    // Case 30: Allez en Prison
    cases[30] = Case_NonAchetable("Allez en Prison", Case_NonAchetable::TypeCaseNonAchetable::ALLEZ_EN_PRISON);
    
    // Case 31: Avenue de Breteuil
    cases[31] = CaseTerrain(300, 7, 0);
    cases[31].setNom("Avenue de Breteuil");
    cases[31].setPrix(300);
    cases[31].setProprio("");
    cases[31].setHypo(false);

    // Case 32: Avenue Foch
    cases[32] = CaseTerrain(300, 7, 0);
    cases[32].setNom("Avenue Foch");
    cases[32].setPrix(300);
    cases[32].setProprio("");
    cases[32].setHypo(false);

    // Case 33: Caisse de Communauté
    cases[33] = Case_NonAchetable("Caisse de Communauté", Case_NonAchetable::TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE);
    
    // Case 34: Boulevard des Capucines
    cases[34] = CaseTerrain(320, 7, 0);
    cases[34].setNom("Boulevard des Capucines");
    cases[34].setPrix(320);
    cases[34].setProprio("");
    cases[34].setHypo(false);

    // Case 35: Gare Saint-Lazare
    cases[35] = Gare(200);
    cases[35].setNom("Gare Saint-Lazare");
    cases[35].setPrix(200);
    cases[35].setProprio("");
    cases[35].setHypo(false);

    // Case 36: Carte Chance
    cases[36] = Case_NonAchetable("Carte Chance", Case_NonAchetable::TypeCaseNonAchetable::CHANCE);
    
    // Case 37: Avenue des Champs-Élysées
    cases[37] = CaseTerrain(350, 8, 0);
    cases[37].setNom("Avenue des Champs-Élysées");
    cases[37].setPrix(350);
    cases[37].setProprio("");
    cases[37].setHypo(false);

    // Case 38: Taxe de Luxe
    cases[38] = Case_NonAchetable("Taxe de Luxe", Case_NonAchetable::TypeCaseNonAchetable::TAXE_DE_LUXE);
    
    // Case 39: Rue de la Paix
    cases[39] = CaseTerrain(400, 8, 0);
    cases[39].setNom("Rue de la Paix");
    cases[39].setPrix(400);
    cases[39].setProprio("");
    cases[39].setHypo(false);
    
    */
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
        jeuTermine = true;
    }


}
