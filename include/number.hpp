#pragma once

#include <string>
#include "astnode.hpp"

class Number : public ASTNode {
  public:
    Number(int val)
        : ASTNode(std::to_string(val))
        , val_(val) {}

    Number(const Number& other) = delete;
    Number& operator=(const Number& other) = delete;
    ~Number() = default;

    int value() const { return val_; }

  private:
    int val_;
};
