#ifndef joueur_hpp
#define joueur_hpp

#include <stdexcept>
#include <iostream>

using namespace std;

class Joueur{

    private :

    bool en_vie;
    string nom;
    int solde;
    int position;
    int nb_cartes_liberte;
    bool en_prison;


    public : 
    
    Joueur(bool en_vie, string nom, int solde, int position, int nb_cartes_liberte, bool en_prison);



}

#endif joueur_hpp
