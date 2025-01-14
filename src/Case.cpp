
#include "Case.hpp"
#include <iostream>

using namespace std;


Case::Case(const std::string& nom) : nom(nom) {}

void Case::action() const {
    std::cout << "Case neutre : aucun effet.\n";
}

string Case::getNom() const {
    return nom;
}

