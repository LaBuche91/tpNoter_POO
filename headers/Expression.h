#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    virtual ~Expression() = default;

    // Méthode virtuelle pure pour évaluer une expression
    virtual int evaluate() const = 0;

    // Méthode optionnelle pour l'affichage (débogage)
    virtual void afficher() const = 0;
};

#endif // EXPRESSION_H