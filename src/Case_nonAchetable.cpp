#include "Case_NonAchetable.hpp"
#include <vector>

// Constructeur
Case_NonAchetable::Case_NonAchetable(const std::string& nom, TypeCaseNonAchetable type_case)
    : Case(nom), type_case(type_case) {}

// Methode pour convertir l'enumeration en chaîne de caractères
const char* Case_NonAchetable::typeToString(TypeCaseNonAchetable type) {
    switch (type) {
        case TypeCaseNonAchetable::DEPART: return "Depart";
        case TypeCaseNonAchetable::PRISON: return "Prison";
        case TypeCaseNonAchetable::ALLEZ_EN_PRISON: return "Allez en Prison";
        case TypeCaseNonAchetable::CHANCE: return "Chance";
        case TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE: return "Caisse de Communaute";
        case TypeCaseNonAchetable::IMPOT: return "Impot";
        case TypeCaseNonAchetable::TAXE_DE_LUXE: return "Taxe de Luxe";
        case TypeCaseNonAchetable::PARC_GRATUIT: return "Parc Gratuit";
        default: return "Inconnu";
    }
}

// Methode action
void Case_NonAchetable::actioncase(Joueur& joueur, vector<Joueur>& joueurs) {
    switch (type_case) {
        case TypeCaseNonAchetable::DEPART:
            joueur.addSolde(200);
            std::cout << joueur.getNom() << " passe par la case Depart et gagne 200 monos." << std::endl;
            break;
        case TypeCaseNonAchetable::PRISON:
            std::cout << joueur.getNom() << " est en prison !" << std::endl;
            break;
        case TypeCaseNonAchetable::CHANCE:
            std::cout << joueur.getNom() << " pioche une carte Chance." << std::endl;
            break;
        case TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE:
            std::cout << joueur.getNom() << " pioche une carte Caisse de Communaute." << std::endl;
            break;
        case TypeCaseNonAchetable::IMPOT:
            joueur.addSolde(-200);
            std::cout << joueur.getNom() << " paie 200 monos pour l'Impot." << std::endl;
            break;
        case TypeCaseNonAchetable::TAXE_DE_LUXE:
            joueur.addSolde(-75);
            std::cout << joueur.getNom() << " paie 75 monos pour la Taxe de Luxe." << std::endl;
            break;
        case TypeCaseNonAchetable::PARC_GRATUIT:
            std::cout << joueur.getNom() << " se repose sur le Parc Gratuit. Rien ne se passe." << std::endl;
            break;
        case TypeCaseNonAchetable::ALLEZ_EN_PRISON:
            std::cout << joueur.getNom() << " va directement en prison !" << std::endl;
            joueur.setEnPrison(true);
            break;
        default:
            break;
    }
}
