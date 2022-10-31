// OTUS C++ Basic course homework skeleton.
// Lexer interface

#pragma once

#include <istream>
#include <string>

class Lexer {
  public:
      //Маркировка типа токенов на выходе из лексера
    enum class Token {
        Number,
        Operator,
        End,
        Lbrace,
        Rbrace,
        Name,
    };

    explicit Lexer(std::istream &in);   //Конструктор лексера принимающий в качестве аргумента входной поток символов
    Lexer(const Lexer &other) = delete;
    Lexer &operator=(const Lexer &other) = delete;
    Token next_token();
    int get_number() const { return number_; }
    std::string get_operator() const { return operator_; }
    std::string get_name() const { return name_; }

  protected:
    bool isbrace(char ch) const;
    bool isoperator(char ch) const;

  private:
      //Внутреннее состояние лексера при обработке входных символов
    enum class State {
        Empty,      //Начальное состояние лексера
        ReadNumber, //Производится считывание цифр из входного потока
        ReadName,   //Производится считывание символа (включая цифры) из входного потока
        End,        //Заключительное состояние лексера если считывание символов завершилось
    };
    char next_char();   //Считывание следующего символа из потока
    bool end() const;   //Флаг достижения конца символьного потока

    State state_;       //Статус состояния лексера
    std::string name_;  
    int number_;        //Переменная для хранения считываемого числа
    std::string operator_;
    char ch_;       //Символ считанный с входного потока
    std::istream &in_;  //Входной поток символов поступающий в лексер
};

inline Lexer::Lexer(std::istream &in)
    : state_(State::Empty)
    , number_(0)
    , in_(in) {
    next_char();
}

inline char Lexer::next_char() {
    in_.get(ch_);
    return ch_;
}

inline bool Lexer::end() const { return in_.eof() || ch_ == '\n'; }

inline bool Lexer::isbrace(char ch) const { return ch == '(' || ch == ')'; }

inline bool Lexer::isoperator(char ch) const {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
