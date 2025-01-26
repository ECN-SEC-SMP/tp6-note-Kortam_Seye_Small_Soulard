#include "Case_NonAchetable.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

/**
 * @brief Constructeur de la classe Case_NonAchetable.
 *
 * Initialise une case non achetable avec un nom et un type spécifique.
 *
 * @param nom Le nom de la case.
 * @param type_case Le type de la case.
 */
Case_NonAchetable::Case_NonAchetable(const string &nom, TypeCaseNonAchetable type_case)
    : Case(nom), type_case(type_case) {}

/**
 * @brief Convertit un type de case en une chaîne de caractères lisible.
 *
 * @param type Le type de la case.
 * @return Une chaîne de caractères représentant le type de la case.
 */
const char *Case_NonAchetable::typeToString(TypeCaseNonAchetable type)
{
    switch (type)
    {
    case TypeCaseNonAchetable::DEPART:
        return "Depart";
    case TypeCaseNonAchetable::PRISON:
        return "Prison";
    case TypeCaseNonAchetable::ALLEZ_EN_PRISON:
        return "Allez en Prison";
    case TypeCaseNonAchetable::CHANCE:
        return "Chance";
    case TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE:
        return "Caisse de Communaute";
    case TypeCaseNonAchetable::IMPOT:
        return "Impot";
    case TypeCaseNonAchetable::TAXE_DE_LUXE:
        return "Taxe de Luxe";
    case TypeCaseNonAchetable::PARC_GRATUIT:
        return "Parc Gratuit";
    default:
        return "Inconnu";
    }
}

/**
 * @brief Effectue l'action associée à la case.
 *
 * En fonction du type de la case, cette méthode applique un effet
 * spécifique au joueur actif ou, dans certains cas, à l'ensemble des joueurs.
 *
 * @param joueur Le joueur actif.
 * @param joueurs La liste de tous les joueurs.
 */
void Case_NonAchetable::actioncase(Joueur &joueur, vector<Joueur> &joueurs)
{
    switch (type_case)
    {
    case TypeCaseNonAchetable::DEPART:
        cout << joueur.getNom() << " passe par la case Depart et gagne 200 monos." << endl;
        break;
    case TypeCaseNonAchetable::PRISON:
        cout << joueur.getNom() << " est en prison !" << endl;
        break;
    case TypeCaseNonAchetable::CHANCE : {
        cout << joueur.getNom() << " pioche une carte Chance." << endl;

        vector<string> cartes_chance = {
            "Rendez-vous à la Rue de la Paix",
            "Avancer jusqu'à la case départ",
            "Rendez-vous à l'Avenue Henri-Martin. Si vous passez par la case départ, recevez 200 monos",
            "Avancez au Boulevard de La Villette. Si vous passez par la case départ, recevez 200 monos",
            "Vous êtes imposé pour les réparations de voirie à raison de 40 monos par maison et 115 monos par hôtel",
            "Avancez jusqu'à la Gare de Lyon. Si vous passez par la case départ, recevez 200 monos",
            "Vous avez gagné le prix de mots croisés. Recevez 100 monos",
            "La banque vous verse un dividende de 50 monos",
            "Vous êtes libéré de prison. Cette carte peut être conservée jusqu'à ce qu'elle soit utilisée ou vendue.",
            "Reculez de trois cases",
            "Allez en prison. Rendez-vous directement en prison. Ne franchissez pas la case départ, ne touchez pas 200 monos",
            "Faites des réparations dans toutes vos maisons. Versez pour chaque maison 40 monos. Versez pour chaque hôtel 115 monos",
            "Amende pour excès de vitesse 15 monos",
            "Payez pour frais de scolarité 150 monos",
            "Amende pour ivresse 20 monos",
            "Votre immeuble et votre prêt rapportent. Vous devez toucher 150 monos"};

        srand(time(0));
        int index = rand() % cartes_chance.size();

        cout << "Carte Chance: " << cartes_chance[index] << endl;

        string carte = cartes_chance[index];
        if (carte == "Rendez-vous à la Rue de la Paix")
        {
            joueur.setPosition(39);
        }
        else if (carte == "Avancer jusqu'à la case départ")
        {
            joueur.setPosition(0);
            joueur.addSolde(200);
        }
        else if (carte == "Rendez-vous à l'Avenue Henri-Martin. Si vous passez par la case départ, recevez 200 monos")
        {
            if (joueur.getPosition() > 24)
                joueur.addSolde(200);
            joueur.setPosition(24);
        }
        else if (carte == "Avancez au Boulevard de La Villette. Si vous passez par la case départ, recevez 200 monos")
        {
            if (joueur.getPosition() > 11)
                joueur.addSolde(200);
            joueur.setPosition(11);
        }
        else if (carte == "Avancez jusqu'à la Gare de Lyon. Si vous passez par la case départ, recevez 200 monos")
        {
            if (joueur.getPosition() > 15)
                joueur.addSolde(200);
            joueur.setPosition(15);
        }
        else if (carte == "Vous avez gagné le prix de mots croisés. Recevez 100 monos")
        {
            joueur.addSolde(100);
        }
        else if (carte == "La banque vous verse un dividende de 50 monos")
        {
            joueur.addSolde(50);
        }
        else if (carte == "Vous êtes libéré de prison. Cette carte peut être conservée jusqu'à ce qu'elle soit utilisée ou vendue.")
        {
            joueur.setNbCartesLiberte(joueur.getNbCartesLiberte() + 1);
        }
        else if (carte == "Reculez de trois cases")
        {
            joueur.setPosition(joueur.getPosition() - 3);
        }
        else if (carte == "Allez en prison. Rendez-vous directement en prison. Ne franchissez pas la case départ, ne touchez pas 200 monos")
        {
            joueur.setPosition(10);
            joueur.setEnPrison(true);
        }
        else if (carte == "Amende pour excès de vitesse 15 monos")
        {
            joueur.addSolde(-15);
        }
        else if (carte == "Payez pour frais de scolarité 150 monos")
        {
            joueur.addSolde(-150);
        }
        else if (carte == "Amende pour ivresse 20 monos")
        {
            joueur.addSolde(-20);
        }
        else if (carte == "Votre immeuble et votre prêt rapportent. Vous devez toucher 150 monos")
        {
            joueur.addSolde(150);
        }
        break;
    }
    case TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE : {
        cout << joueur.getNom() << " pioche une carte Caisse de Communauté." << endl;
        vector<string> cartes_communaute = {
            "Placez-vous sur la case départ",
            "Erreur de la banque en votre faveur. Recevez 200 monos",
            "Payez la note du médecin 50 monos",
            "La vente de votre stock vous rapporte 50 monos",
            "Vous êtes libéré de prison. Cette carte peut être conservée jusqu'à ce qu'elle soit utilisée ou vendue.",
            "Aller en prison. Rendez-vous directement à la prison. Ne franchissez pas par la case départ, ne touchez pas 200 monos",
            "Retournez à Belleville",
            "Recevez votre revenu annuel 100 monos",
            "C'est votre anniversaire. Chaque joueur doit vous donner 10 monos",
            "Les contributions vous remboursent la somme de 200 monos",
            "Recevez votre intérêt sur l'emprunt à 7% 250 monos",
            "Payez votre Police d'Assurance 50 monos",
            "Payez une amende de 10 monos ou bien tirez une carte « CHANCE »",
            "Rendez-vous à la gare la plus proche. Si vous passez par la case départ, recevez 200 monos",
            "Vous avez gagné le deuxième Prix de Beauté. Recevez 10 monos",
            "Vous héritez 100 monos"};

        srand(time(0));
        int index2 = rand() % cartes_communaute.size();

        cout << "Carte Caisse de Communauté: " << cartes_communaute[index2] << endl;

        string cartecdc = cartes_communaute[index2];
        if (cartecdc == "Placez-vous sur la case départ")
        {
            joueur.setPosition(0);
            joueur.addSolde(200);
        }
        else if (cartecdc == "Erreur de la banque en votre faveur. Recevez 200 monos")
        {
            joueur.addSolde(200);
        }
        else if (cartecdc == "Payez la note du médecin 50 monos")
        {
            joueur.addSolde(-50);
        }
        else if (cartecdc == "La vente de votre stock vous rapporte 50 monos")
        {
            joueur.addSolde(50);
        }
        else if (cartecdc == "Vous êtes libéré de prison. Cette carte peut être conservée jusqu'à ce qu'elle soit utilisée ou vendue.")
        {
            joueur.setNbCartesLiberte(joueur.getNbCartesLiberte() + 1);
        }
        else if (cartecdc == "Aller en prison. Rendez-vous directement à la prison. Ne franchissez pas par la case départ, ne touchez pas 200 monos")
        {
            joueur.setPosition(10);
            joueur.setEnPrison(true);
        }
        else if (cartecdc == "Retournez à Belleville")
        {
            joueur.setPosition(1);
        }
        else if (cartecdc == "Recevez votre revenu annuel 100 monos")
        {
            joueur.addSolde(100);
        }
        else if (cartecdc == "C'est votre anniversaire. Chaque joueur doit vous donner 10 monos")
        {
            for (auto &j : joueurs)
            {
                if (&j != &joueur)
                {
                    j.addSolde(-10);
                    joueur.addSolde(10);
                }
            }
        }
        else if (cartecdc == "Les contributions vous remboursent la somme de 200 monos")
        {
            joueur.addSolde(200);
        }
        else if (cartecdc == "Recevez votre intérêt sur l'emprunt à 7% 250 monos")
        {
            joueur.addSolde(250);
        }
        else if (cartecdc == "Payez votre Police d'Assurance 50 monos")
        {
            joueur.addSolde(-50);
        }
        else if (cartecdc == "Payez une amende de 10 monos ou bien tirez une carte « CHANCE »")
        {
            joueur.addSolde(-10);
        }
        else if (cartecdc == "Rendez-vous à la gare la plus proche. Si vous passez par la case départ, recevez 200 monos")
        {
            if (joueur.getPosition() > 35 || joueur.getPosition() <= 5)
            {
                if (joueur.getPosition() > 35)
                    joueur.addSolde(200);
                joueur.setPosition(5);
            }
            else if (joueur.getPosition() > 5 && joueur.getPosition() <= 15)
            {
                joueur.setPosition(15);
            }
            else if (joueur.getPosition() > 15 && joueur.getPosition() <= 25)
            {
                joueur.setPosition(25);
            }
            else if (joueur.getPosition() > 25 && joueur.getPosition() <= 35)
            {
                joueur.setPosition(35);
            }
        }
        else if (cartecdc == "Vous avez gagné le deuxième Prix de Beauté (derrière Tommy). Recevez 10 monos")
        {
            joueur.addSolde(10);
        }
        else if (cartecdc == "Vous héritez 100 monos")
        {
            joueur.addSolde(100);
        }

        break;
    }
    case TypeCaseNonAchetable::IMPOT:
        joueur.addSolde(-200);
        cout << joueur.getNom() << " paie 200 monos pour l'Impôt." << endl;
        break;
    case TypeCaseNonAchetable::TAXE_DE_LUXE:
        joueur.addSolde(-75);
        cout << joueur.getNom() << " paie 75 monos pour la Taxe de Luxe." << endl;
        break;
    case TypeCaseNonAchetable::PARC_GRATUIT:
        cout << joueur.getNom() << " se repose sur le Parc Gratuit. Rien ne se passe." << endl;
        break;
    case TypeCaseNonAchetable::ALLEZ_EN_PRISON:
        cout << joueur.getNom() << " va directement en prison !" << endl;
        joueur.setEnPrison(true);
        break;
    default:
        break;
    }
}
