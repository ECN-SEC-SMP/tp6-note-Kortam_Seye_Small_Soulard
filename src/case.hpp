#ifndef Case_hpp
#define Case_hpp

#include <iostream>

using namespace std; 


class Case {
protected:
    string nom;

public:
    explicit Case(const string& nom);
    virtual ~Case() = default;

    virtual void action() const;
    string getNom() const;
};


#endif
