#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    virtual ~Expression() = default;

    virtual void accept(class Visitor &v) const = 0;
};

#endif // EXPRESSION_H