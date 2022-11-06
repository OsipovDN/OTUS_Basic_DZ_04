#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
public:
    Variable(std::string name)
        : ASTNode(name){}

};
