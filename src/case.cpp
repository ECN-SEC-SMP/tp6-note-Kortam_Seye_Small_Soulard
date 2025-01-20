
#include "Case.hpp"
#include <iostream>

using namespace std;


Case::Case(const string& nom) : nom(nom) {}
Case::Case() : nom("") {}
void Case::action() const {
    cout << "Case neutre : aucun effet.\n";
}

string Case::getNom() const {
    return nom;
}

