#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include <iostream>
#include <unordered_map>

class Variable : public Expression {
private:
    char nom;  // Nom de la variable
    const std::unordered_map<char, int>& contexte;  // Référence vers un contexte

public:
    Variable(char n, const std::unordered_map<char, int>& ctx) : nom(n), contexte(ctx) {}

    // Évaluation de la variable en fonction du contexte
    int evaluate() const override {
        auto it = contexte.find(nom);
        if (it == contexte.end()) {
            throw std::runtime_error("Variable non définie dans le contexte.");
        }
        return it->second;
    }

    // Affichage
    void afficher() const override {
        std::cout << nom;
    }
};

#endif // VARIABLE_H