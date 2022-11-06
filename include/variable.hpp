#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
public:
    Variable(std::string name)
        : ASTNode(name){}

    Variable(const Variable& other) = delete;
    Variable& operator=(const Variable& other) = delete;
    ~Variable() = default;

};
