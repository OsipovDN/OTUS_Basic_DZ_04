#pragma once

#include <istream>

#include "astnode.hpp"
#include "lexer.hpp"

class Parser {
  public:
    explicit Parser(Lexer &lexer)
        : lexer_(lexer) {}

    Parser(const Parser &other) = delete;

    Parser &operator=(const Parser &other) = delete;

    ~Parser() = default;

    ASTNode *parse();

  private:
    void next_token();

    ASTNode *expr();        //Метод разбора выражения

    ASTNode *term();        //Метод считывания первого слагаемого

    ASTNode *prim();        //Метод определния (число или имя переменной)

    Lexer &lexer_;
    Lexer::Token tok_;
};
