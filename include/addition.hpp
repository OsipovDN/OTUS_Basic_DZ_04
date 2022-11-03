#pragma once

#include <string>
#include "astnode.hpp"

class Add : public ASTNode {

public:
    Add(ASTNode* lval, ASTNode* rval)
        :ASTNode(" + ", lval, rval) {}
};