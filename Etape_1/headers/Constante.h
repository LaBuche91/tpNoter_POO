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

    Constante &operator=(const Constante &c);

    Constante operator+(const Constante &c) const;

    bool operator==(const Constante &c) const;

    int evaluate() const override { return valeur; }

    void afficher() const override { std::cout << valeur; }

    ~Constante();
};

#endif // CONSTANTE_H