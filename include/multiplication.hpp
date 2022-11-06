#pragma once

#include <string>
#include "astnode.hpp"

class Mul: public ASTNode {

public:
    Mul(ASTNode* lval, ASTNode* rval)
        :ASTNode(" * ",lval,rval) {}

    Mul(const Mul& other) = delete;
    Mul& operator=(const Mul& other) = delete;
    ~Mul() = default;
};