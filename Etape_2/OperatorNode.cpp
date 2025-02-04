#include "headers/OperatorNode.h"
#include "headers/Visitor.h"

void OperatorNode::accept(Visitor &v) const { v.visit(*this); }