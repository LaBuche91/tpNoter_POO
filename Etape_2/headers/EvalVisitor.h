#include "OperatorNode.h"
#include <map>

class EvalVisitor : public Visitor {
public:
    std::map<char, int> varValues;
    int result;
    void visit(const Constante &c) override { result = c.getValeur(); }
    void visit(const Variable &v) override { result = varValues[v.getNom()]; }
    void visit(const OperatorNode &n) override {
        EvalVisitor leftEval, rightEval;
        leftEval.varValues = varValues;
        rightEval.varValues = varValues;
        n.left->accept(leftEval);
        n.right->accept(rightEval);
        result = n.op.apply(leftEval.result, rightEval.result);
    }
};