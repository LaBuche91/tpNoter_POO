#include "headers/Constante.h"
#include "headers/Visitor.h"

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

void Constante::accept(Visitor &v) const { v.visit(*this); }
