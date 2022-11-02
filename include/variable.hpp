#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
public:
    Variable(std::string name)
        : ASTNode(name)
        , name_(name) {}

    std::string name() const { return name_; }

private:
    std::string name_;
};
