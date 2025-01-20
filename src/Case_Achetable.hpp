#ifndef CASEACHETABLE_HPP
#define CASEACHETABLE_HPP

#include "Case.hpp"
#include <string>
#include <iostream>

using namespace std; 

class Case_Achetable: public Case
{
private:
    string proprio;
    int prix;
    bool hypo;
public:
    Case_Achetable();
    Case_Achetable(string proprio, int prix, bool hypo);
    ~Case_Achetable();
    void setProprio(string proprio);
    string getProprio() const;
    void setPrix(int prix);
    int getPrix() const;
    void setHypo(bool hypo);
    bool getHypo() const;
};

#endif // CASEACHETABLE_HPP