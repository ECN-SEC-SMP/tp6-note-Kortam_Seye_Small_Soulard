#ifndef CASE_NONACHETABLE_H
#define CASE_NONACHETABLE_H

#include <string>
#include <iostream>
#include "Joueur.h"  // Inclure votre classe Joueur si nécessaire

class Case_NonAchetable : public Case {
public:
    // Enum interne représentant les types de cases non achetables
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

    NonAchetable(const std::string& nom, TypeCaseNonAchetable type_case);
    void action(Joueur& joueur);

private:
    TypeCaseNonAchetable type_case;
    static const char* typeToString(TypeCaseNonAchetable type);  // Méthode utilitaire pour afficher les types de cases
};

#endif
