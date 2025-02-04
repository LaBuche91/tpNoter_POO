#include "headers/Constante.h"

// Constructor
Constante::Constante(int v) : valeur(v) {}

// Getter for valeur
int Constante::getValeur() const {
    return valeur;
}

// Setter for valeur
void Constante::setValeur(int v) {
    valeur = v;
}

// Assignment operator
Constante& Constante::operator=(const Constante &c) {
    if (this != &c) {
        valeur = c.valeur;
    }
    return *this;
}

// Equality operator
bool Constante::operator==(const Constante &c) const {
    return valeur == c.valeur;
}

// Destructor
Constante::~Constante() {}