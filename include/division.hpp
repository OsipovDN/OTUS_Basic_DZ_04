#pragma once

#include <string>
#include "astnode.hpp"

class Div : public ASTNode {

public:
    Div(ASTNode* lval, ASTNode* rval)
        :ASTNode(" / ", lval, rval) {}
};