#pragma once

#include <string>
#include "astnode.hpp"

class Mul: public ASTNode {
public:
    Mul(int lval, int rval)
        :ASTNode('*', lval, rval),
        lhs_(lval),rhs_(rval) {}

    int lvalue() const { return lhs_; }
    int rvalue() const { return rhs_; }

private:
    int lhs_;
    int rhs_;
};