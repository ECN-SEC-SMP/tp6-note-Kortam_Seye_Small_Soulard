#ifndef Case_hpp
#define Case_hpp

#include <iostream>

using namespace std; 


class Case {
protected:
    string nom;
    int numero;
public:
    explicit Case(const string& nom);
    Case();
    virtual ~Case() = default;
    virtual void action() const;
    string getNom() const;
    void setNom(string nom);
    int getNumero() const;
    void setNumero(int numero);
};


#endif
