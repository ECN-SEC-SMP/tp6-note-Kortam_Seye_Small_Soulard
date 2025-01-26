#include "Case_NonAchetable.hpp"
#include <vector>

using namespace std;

/**
 * @brief Constructeur de la classe Case_NonAchetable.
 * 
 * Initialise une case non achetable avec un nom et un type spécifique.
 * 
 * @param nom Le nom de la case.
 * @param type_case Le type de la case.
 */
Case_NonAchetable::Case_NonAchetable(const string& nom, TypeCaseNonAchetable type_case)
    : Case(nom), type_case(type_case) {}

/**
 * @brief Convertit un type de case en une chaîne de caractères lisible.
 * 
 * @param type Le type de la case.
 * @return Une chaîne de caractères représentant le type de la case.
 */
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

/**
 * @brief Effectue l'action associée à la case.
 * 
 * En fonction du type de la case, cette méthode applique un effet
 * spécifique au joueur actif ou, dans certains cas, à l'ensemble des joueurs.
 * 
 * @param joueur Le joueur actif.
 * @param joueurs La liste de tous les joueurs.
 */
void Case_NonAchetable::actioncase(Joueur& joueur, vector<Joueur>& joueurs) {
    switch (type_case) {
        case TypeCaseNonAchetable::DEPART:
            cout << joueur.getNom() << " passe par la case Depart et gagne 200 monos." << endl;
            break;
        case TypeCaseNonAchetable::PRISON:
            cout << joueur.getNom() << " est en prison !" << endl;
            break;
        case TypeCaseNonAchetable::CHANCE:
            cout << joueur.getNom() << " pioche une carte Chance." << endl;
            break;
        case TypeCaseNonAchetable::CAISSE_DE_COMMUNAUTE:
            cout << joueur.getNom() << " pioche une carte Caisse de Communauté." << endl;
            break;
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
