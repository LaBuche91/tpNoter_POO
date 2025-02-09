#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"
#include <iostream>
#include <unordered_map>

class Variable : public Expression {
private:
    char nom;  // Nom de la variable

public:
    Variable(char n) : nom(n){}

    char getNom() const;
    void accept(Visitor &v) const override;
};

#endif // VARIABLE_H