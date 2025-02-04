#include "Constante.h"
#include "Variable.h"
#include "OperatorNode.h"

// Interface pour le visiteur
class Visitor {
public:
    virtual void visit(const Constante &c) = 0;
    virtual void visit(const Variable &v) = 0;
    virtual void visit(const OperatorNode &n) = 0;
};