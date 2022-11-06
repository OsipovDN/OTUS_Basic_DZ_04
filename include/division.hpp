#pragma once

#include <string>
#include "astnode.hpp"

class Div : public ASTNode {

public:
    Div(ASTNode* lval, ASTNode* rval)
        :ASTNode(" / ", lval, rval) {}

    Div(const Div& other) = delete;
    Div& operator=(const Div& other) = delete;
    ~Div() = default;
};