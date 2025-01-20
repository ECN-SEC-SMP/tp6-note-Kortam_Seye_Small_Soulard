
#ifndef CASETERRAIN_H
#define CASETERRAIN_H

#include "Case.hpp"

class CaseTerrain : public Case {
private:
    int loyer;
    int groupe;
    int construction;
public:
    CaseTerrain(const std::string& nom, int loyer);
    
    void action() const override;
    void setProprietaire(int joueur);
    int getProprietaire() const;
    void hypothequer();
    void desHypothequer();
    
};

#endif // CASETERRAIN_H
