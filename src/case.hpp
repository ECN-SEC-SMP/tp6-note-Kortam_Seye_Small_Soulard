#ifndef Case_hpp
#define Case_hpp

#include <iostream>

using namespace std; 


class Case {
protected:
    std::string nom;

public:
    explicit Case(const std::string& nom);
    virtual ~Case() = default;

    virtual void action() const;
    std::string getNom() const;
};





#endif
