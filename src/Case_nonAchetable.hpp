#ifndef CASE_NONACHETABLE_H
#define CASE_NONACHETABLE_H

#include <string>
#include <iostream>
#include "joueur.hpp" 
#include <vector>

class Case_NonAchetable: public Case 
{
public:
    // Enum interne representant les types de cases non achetables
    enum class TypeCaseNonAchetable {
        DEPART,
        PRISON,
        ALLEZ_EN_PRISON,
        CHANCE,
        CAISSE_DE_COMMUNAUTE,
        IMPOT,
        TAXE_DE_LUXE,
        PARC_GRATUIT
    };

    Case_NonAchetable(const std::string& nom, TypeCaseNonAchetable type_case);
    void actioncase(Joueur& joueur, vector<Joueur>& joueurs);

private:
    TypeCaseNonAchetable type_case;
    static const char* typeToString(TypeCaseNonAchetable type);  // Methode utilitaire pour afficher les types de cases
};

#endif
