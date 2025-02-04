#include "Visitor.h"


// Visiteur pour afficher l'expression
class DisplayVisitor : public Visitor {
public:
    std::string result;
    void visit(const Constante &c) override { result += std::to_string(c.getValeur()); }
    void visit(const Variable &v) override { result += v.getNom(); }
    void visit(const OperatorNode &n) override {
        result += "(";
        n.left->accept(*this);
        result += " " + std::string(1, n.op.symbol) + " ";  // Ajout correct de l'opérateur
        n.right->accept(*this);
        result += ")";
    }
};