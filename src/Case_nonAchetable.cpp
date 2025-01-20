#include "Case_NonAchetable.hpp"

// Constructeur
NonAchetable::NonAchetable(const std::string& nom, TypeCaseNonAchetable type_case)
    : Case(nom), type_case(type_case) {}

// Méthode pour convertir l'énumération en chaîne de caractères
const char* NonAchetable::typeToString(TypeCaseNonAchetable type) {
    switch (type) {
        case TypeCaseNonAchetable::DEPART: return "Départ";
        case TypeCaseNonAchetable::PRISON: return "Prison";
        case TypeCaseNonAchetable::ALLEZ_EN_PRISON: return "Allez en Prison";
        case TypeCaseNonAchetable::CHANCE: return "Chance";
        case TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE: return "Caisse de Communauté";
        case TypeCaseNonAchetable::IMPOT: return "Impôt";
        case TypeCaseNonAchetable::TAXE_DE_LUXE: return "Taxe de Luxe";
        case TypeCaseNonAchetable::PARC_GRATUIT: return "Parc Gratuit";
        default: return "Inconnu";
    }
}

// Méthode action
void NonAchetable::action(Joueur& joueur) {
    switch (type_case) {
        case TypeCaseNonAchetable::DEPART:
            joueur.recevoir(200);
            std::cout << joueur.getNom() << " passe par la case Départ et gagne 200 monos." << std::endl;
            break;
        case TypeCaseNonAchetable::PRISON:
            std::cout << joueur.getNom() << " est en prison !" << std::endl;
            break;
        case TypeCaseNonAchetable::CHANCE:
            std::cout << joueur.getNom() << " pioche une carte Chance." << std::endl;
            break;
        case TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE:
            std::cout << joueur.getNom() << " pioche une carte Caisse de Communauté." << std::endl;
            break;
        case TypeCaseNonAchetable::IMPOT:
            joueur.payer(200);
            std::cout << joueur.getNom() << " paie 200 monos pour l'Impôt." << std::endl;
            break;
        case TypeCaseNonAchetable::TAXE_DE_LUXE:
            joueur.payer(75);
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
