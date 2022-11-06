#pragma once

#include <string>
#include "astnode.hpp"

class Sub : public ASTNode {

public:
    Sub(ASTNode* lval, ASTNode* rval)
        :ASTNode(" - ", lval, rval) {}

};