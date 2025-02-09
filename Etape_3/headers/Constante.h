#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "Expression.h"
#include <iostream>

class Constante : public Expression
{

private:
    int valeur;

public:
    Constante(int v);

    int getValeur() const;

    void setValeur(int v);
    
    void accept(Visitor &v) const override;
};

#endif // CONSTANTE_H