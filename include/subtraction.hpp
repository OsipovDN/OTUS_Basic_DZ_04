#pragma once

#include <string>
#include "astnode.hpp"

class Sub : public ASTNode {

public:
    Sub(ASTNode* lval, ASTNode* rval)
        :ASTNode(" - ", lval, rval) {}

    Sub(const Sub& other) = delete;
    Sub& operator=(const Sub& other) = delete;
    ~Sub() = default;
};