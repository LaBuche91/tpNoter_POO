#include "headers/Variable.h"
#include "headers/Visitor.h"
#include <iostream>
#include <string>

void Variable::accept(Visitor &v) const { v.visit(*this); }

char Variable::getNom() const {
    return nom;
}