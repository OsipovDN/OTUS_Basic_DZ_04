// OTUS C++ Basic course homework skeleton.
// Lexer implementation

#include "lexer.hpp"

#include <cctype>

Lexer::Token Lexer::next_token() {
    for (;;) {
        switch (state_) {
            //Проверяем статус линкера
        case State::End:
            //если считывание завершилось
            return Token::End;
            //вернуть значение токена END
        case State::ReadNumber:
            //Если статус соответствуюет считыванию цифры
            if (end()) {
                //Если данных больше нет или строка символов закончилась
                state_ = State::End;    //Установить маркер конца считывания
                return Token::Number;   //Обозначить токен как число оповещая, что было прочитано число
            }
            if (std::isdigit(ch_)) {
                //Если считанный символ число
                number_ = 10 * number_ + (ch_ - '0');   //Записываем считанную цифру
                state_ = State::ReadNumber;     //Меняем статус 
                next_char();        //Считываем следующий символ
                break;
            }
            state_ = State::Empty;
            return Token::Number;
        case State::ReadName:
            if (end()) {
                state_ = State::End;
                return Token::Name;
            }
            if (std::isalpha(ch_) || std::isdigit(ch_)) {
                name_ += ch_;
                next_char();
                break;
            }
            state_ = State::Empty;
            return Token::Name;
        case State::Empty:
            if (end()) {
                state_ = State::End;
                return Token::End;
            }
            if (std::isspace(ch_)) {
                next_char();
                break;
            }
            if (isoperator(ch_)) {
                operator_ = ch_;
                next_char();
                return Token::Operator;
            }
            if (ch_ == '(') {
                next_char();
                return Token::Lbrace;
            }
            if (ch_ == ')') {
                next_char();
                return Token::Rbrace;
            }
            if (std::isdigit(ch_)) {
                number_ = ch_ - '0';
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            if (std::isalpha(ch_)) {
                name_ = ch_;
                state_ = State::ReadName;
                next_char();
                break;
            }
        }
    }
}
