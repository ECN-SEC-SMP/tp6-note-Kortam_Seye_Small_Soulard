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

Case_Achetable::Case_Achetable() : proprio_m(""), prix_m(0), hypo_m(false) {}

Case_Achetable::Case_Achetable(string proprio, int prix, bool hypo):proprio_m(proprio), prix_m(prix), hypo_m(hypo){} //string

Case_Achetable::~Case_Achetable()
{
}




#endif