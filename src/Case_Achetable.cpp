#ifndef Case_Achetable_hpp
#define Case_Achetable_hpp

#include "Case.hpp"
#include "Case_Achetable.hpp"
#include <string>
#include <iostream>

using namespace std;


/// @brief 
/// @param proprio 
/// @param prix 
/// @param hypo 

Case_Achetable::Case_Achetable() : proprio(""), prix(0), hypo(false) {}

Case_Achetable::Case_Achetable(string proprio, int prix, bool hypo):proprio(proprio), prix(prix), hypo(hypo){} //string

Case_Achetable::~Case_Achetable(){}

void Case_Achetable::setProprio(string _proprio) {
    proprio = _proprio;
}

string Case_Achetable::getProprio() const {
    return proprio;
}

void Case_Achetable::setPrix(int _prix) {
    prix = _prix;
}

int Case_Achetable::getPrix() const {
    return prix;
}

void Case_Achetable::setHypo(bool _hypo) {
    hypo = _hypo;
}

bool Case_Achetable::getHypo() const {
    return hypo;
}





#endif