#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "Expression.h"
#include "Operator_t.h"
#include <memory>

class OperatorNode : public Expression {
private:
    Operator_t operateur;  // Opérateur du nœud
    std::unique_ptr<Expression> left;  // Sous-arbre gauche
    std::unique_ptr<Expression> right;  // Sous-arbre droit

public:
    OperatorNode(const Operator_t& op, std::unique_ptr<Expression> leftNode, std::unique_ptr<Expression> rightNode)
        : operateur(op), left(std::move(leftNode)), right(std::move(rightNode)) {}

    // Évaluation de l'opération
    int evaluate() const override {
        if (!left || !right) {
            throw std::logic_error("Les sous-arbres gauche et droit doivent être définis.");
        }
        return operateur.apply(left->evaluate(), right->evaluate());
    }

    // Affichage
    void afficher() const override {
        std::cout << "(";
        if (left) left->afficher();
        std::cout << " " << operateur.getSymbole() << " ";
        if (right) right->afficher();
        std::cout << ")";
    }
};

#endif // OPERATORNODE_H