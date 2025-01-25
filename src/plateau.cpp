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
#include <memory>
#include <random>
#include <chrono>
using namespace std;


/*Case* Plateau::getCase(int index) const {
    if (index >= 0 && index < static_cast<int>(cases.size())) {
        return cases[index].get();
    }
    return nullptr;
}*/

Case* Plateau::getCase(int index) const {
    if (index >= 0 && index < static_cast<int>(cases.size())) {
        return cases[index].get();
    }
    return nullptr;
}

void Plateau::initialiser(const vector<Joueur> &Joueurs)
{
    joueurs = Joueurs; // initialise le tableau de joueurs

    // Initialise le tableau de cases avec des pointeurs intelligents
    cases.resize(40);  // Exemple : on prevoit 40 cases, adaptables selon votre jeu.

    // Case 0: Depart
    cases[0] = make_unique<Case_NonAchetable>("Depart", Case_NonAchetable::TypeCaseNonAchetable::DEPART);
    
    // Case 1: Boulevard de Belleville
    auto case1 = make_unique<CaseTerrain>(60, 1, 0);
    case1->setNom("Boulevard de Belleville");
    case1->setPrix(60);
    case1->setProprio("");
    case1->setHypo(false);
    cases[1] = move(case1);
    
    // Case 2: Caisse de Communaute
    cases[2] = make_unique<Case_NonAchetable>("Caisse de Communaute", Case_NonAchetable::TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE);
    
    // Case 3: Rue Lecourbe
    auto case3 = make_unique<CaseTerrain>(60, 1, 0);
    case3->setNom("Rue Lecourbe");
    case3->setPrix(60);
    case3->setProprio("");
    case3->setHypo(false);
    cases[3] = move(case3);

    // Case 4: Impôts
    cases[4] = make_unique<Case_NonAchetable>("Impots", Case_NonAchetable::TypeCaseNonAchetable::IMPOT);
    
    // Case 5: Gare Montparnasse
    auto case5 = make_unique<Gare>(200);
    case5->setNom("Gare Montparnasse");
    case5->setPrix(200);
    case5->setProprio("");
    case5->setHypo(false);
    cases[5] = move(case5);

    // Case 6: Rue de Vaugirard
    auto case6 = make_unique<CaseTerrain>(100, 2, 0);
    case6->setNom("Rue de Vaugirard");
    case6->setPrix(100);
    case6->setProprio("");
    case6->setHypo(false);
    cases[6] = move(case6);

    // Case 7: Carte Chance
    cases[7] = make_unique<Case_NonAchetable>("Carte Chance", Case_NonAchetable::TypeCaseNonAchetable::CHANCE);
    
    // Case 8: Rue de Courcelles
    auto case8 = make_unique<CaseTerrain>(100, 2, 0);
    case8->setNom("Rue de Courcelles");
    case8->setPrix(100);
    case8->setProprio("");
    case8->setHypo(false);
    cases[8] = move(case8);

    // Case 9: Avenue de la Republique
    auto case9 = make_unique<CaseTerrain>(120, 2, 0);
    case9->setNom("Avenue de la Republique");
    case9->setPrix(120);
    case9->setProprio("");
    case9->setHypo(false);
    cases[9] = move(case9);

    // Case 10: Prison
    cases[10] = make_unique<Case_NonAchetable>("Prison", Case_NonAchetable::TypeCaseNonAchetable::PRISON);
    
    // Case 11: Boulevard de la Villette
    auto case11 = make_unique<CaseTerrain>(140, 3, 0);
    case11->setNom("Boulevard de la Villette");
    case11->setPrix(140);
    case11->setProprio("");
    case11->setHypo(false);
    cases[11] = move(case11);

    // Case 12: Compagnie de l'electricite
    auto case12 = make_unique<Service_Public>(150);
    case12->setNom("Compagnie de l'electricite");
    case12->setPrix(150);
    case12->setProprio("");
    case12->setHypo(false);
    cases[12] = move(case12);

    // Case 13: Avenue de Neuilly
    auto case13 = make_unique<CaseTerrain>(140, 3, 0);
    case13->setNom("Avenue de Neuilly");
    case13->setPrix(140);
    case13->setProprio("");
    case13->setHypo(false);
    cases[13] = move(case13);

    // Case 14: Rue du Paradis
    auto case14 = make_unique<CaseTerrain>(160, 3, 0);
    case14->setNom("Rue du Paradis");
    case14->setPrix(160);
    case14->setProprio("");
    case14->setHypo(false);
    cases[14] = move(case14);

    // Case 15: Gare de Lyon
    auto case15 = make_unique<Gare>(200);
    case15->setNom("Gare de Lyon");
    case15->setPrix(200);
    case15->setProprio("");
    case15->setHypo(false);
    cases[15] = move(case15);

    // Case 16: Avenue Mozart
    auto case16 = make_unique<CaseTerrain>(180, 4, 0);
    case16->setNom("Avenue Mozart");
    case16->setPrix(180);
    case16->setProprio("");
    case16->setHypo(false);
    cases[16] = move(case16);

    // Case 17: Caisse de Communaute
    cases[17] = make_unique<Case_NonAchetable>("Caisse de Communaute", Case_NonAchetable::TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE);
    
    // Case 18: Boulevard Saint-Michel
    auto case18 = make_unique<CaseTerrain>(180, 4, 0);
    case18->setNom("Boulevard Saint-Michel");
    case18->setPrix(180);
    case18->setProprio("");
    case18->setHypo(false);
    cases[18] = move(case18);

    // Case 19: Place Pigalle
    auto case19 = make_unique<CaseTerrain>(200, 4, 0);
    case19->setNom("Place Pigalle");
    case19->setPrix(200);
    case19->setProprio("");
    case19->setHypo(false);
    cases[19] = move(case19);

    // Case 20: Parc Gratuit
    cases[20] = make_unique<Case_NonAchetable>("Parc Gratuit", Case_NonAchetable::TypeCaseNonAchetable::PARC_GRATUIT);
    
    // Case 21: Avenue Matignon
    auto case21 = make_unique<CaseTerrain>(220, 5, 0);
    case21->setNom("Avenue Matignon");
    case21->setPrix(220);
    case21->setProprio("");
    case21->setHypo(false);
    cases[21] = move(case21);

    // Case 22: Carte Chance
    cases[22] = make_unique<Case_NonAchetable>("Carte Chance", Case_NonAchetable::TypeCaseNonAchetable::CHANCE);
    
    // Case 23: Boulevard Malesherbes
    auto case23 = make_unique<CaseTerrain>(220, 5, 0);
    case23->setNom("Boulevard Malesherbes");
    case23->setPrix(220);
    case23->setProprio("");
    case23->setHypo(false);
    cases[23] = move(case23);

    // Case 24: Avenue Henri-Martin
    auto case24 = make_unique<CaseTerrain>(240, 5, 0);
    case24->setNom("Avenue Henri-Martin");
    case24->setPrix(240);
    case24->setProprio("");
    case24->setHypo(false);
    cases[24] = move(case24);

    // Case 25: Gare du Nord
    auto case25 = make_unique<Gare>(200);
    case25->setNom("Gare du Nord");
    case25->setPrix(200);
    case25->setProprio("");
    case25->setHypo(false);
    cases[25] = move(case25);

    // Case 26: Faubourg Saint-Honore
    auto case26 = make_unique<CaseTerrain>(260, 6, 0);
    case26->setNom("Faubourg Saint-Honore");
    case26->setPrix(260);
    case26->setProprio("");
    case26->setHypo(false);
    cases[26] = move(case26);

    // Case 27: Place de la Bourse
    auto case27 = make_unique<CaseTerrain>(260, 6, 0);
    case27->setNom("Place de la Bourse");
    case27->setPrix(260);
    case27->setProprio("");
    case27->setHypo(false);
    cases[27] = move(case27);

    // Case 28: Compagnie des Eaux
    auto case28 = make_unique<Service_Public>(150);
    case28->setNom("Compagnie des Eaux");
    case28->setPrix(150);
    case28->setProprio("");
    case28->setHypo(false);
    cases[28] = move(case28);

    // Case 29: Rue La Fayette
    auto case29 = make_unique<CaseTerrain>(280, 6, 0);
    case29->setNom("Rue La Fayette");
    case29->setPrix(280);
    case29->setProprio("");
    case29->setHypo(false);
    cases[29] = move(case29);

    // Case 30: Allez en Prison
    cases[30] = make_unique<Case_NonAchetable>("Allez en Prison", Case_NonAchetable::TypeCaseNonAchetable::ALLEZ_EN_PRISON);
    
    // Case 31: Avenue de Breteuil
    auto case31 = make_unique<CaseTerrain>(300, 7, 0);
    case31->setNom("Avenue de Breteuil");
    case31->setPrix(300);
    case31->setProprio("");
    case31->setHypo(false);
    cases[31] = move(case31);

    // Case 32: Avenue Foch
    auto case32 = make_unique<CaseTerrain>(300, 7, 0);
    case32->setNom("Avenue Foch");
    case32->setPrix(300);
    case32->setProprio("");
    case32->setHypo(false);
    cases[32] = move(case32);

    // Case 33: Caisse de Communaute
    cases[33] = make_unique<Case_NonAchetable>("Caisse de Communaute", Case_NonAchetable::TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE);
    
    // Case 34: Boulevard des Capucines
    auto case34 = make_unique<CaseTerrain>(320, 7, 0);
    case34->setNom("Boulevard des Capucines");
    case34->setPrix(320);
    case34->setProprio("");
    case34->setHypo(false);
    cases[34] = move(case34);

    // Case 35: Gare Saint-Lazare
    auto case35 = make_unique<Gare>(200);
    case35->setNom("Gare Saint-Lazare");
    case35->setPrix(200);
    case35->setProprio("");
    case35->setHypo(false);
    cases[35] = move(case35);

    // Case 36: Carte Chance
    cases[36] = make_unique<Case_NonAchetable>("Carte Chance", Case_NonAchetable::TypeCaseNonAchetable::CHANCE);
    
    // Case 37: Avenue des Champs-elysees
    auto case37 = make_unique<CaseTerrain>(350, 8, 0);
    case37->setNom("Avenue des Champs-elysees");
    case37->setPrix(350);
    case37->setProprio("");
    case37->setHypo(false);
    cases[37] = move(case37);

    // Case 38: Taxe de Luxe
    cases[38] = make_unique<Case_NonAchetable>("Taxe de Luxe", Case_NonAchetable::TypeCaseNonAchetable::TAXE_DE_LUXE);
    
    // Case 39: Rue de la Paix
    auto case39 = make_unique<CaseTerrain>(400, 8, 0);
    case39->setNom("Rue de la Paix");
    case39->setPrix(400);
    case39->setProprio("");
    case39->setHypo(false);
    cases[39] = move(case39);


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
            joueur.jouerTour(*this);

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

        /*if (tour >= 10)
        {
            jeuTermine = true;
        }*/
    }


}
