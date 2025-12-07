#pragma once
#include<string>
#include "token.h"

class Lexer{
    std::string src; //it takes the input code statement
    int index, line, col; //to maintain index of the current character
    public:
    Lexer(const std::string& s);
    Token nextToken();
    private:
    char peek(); //see the next character only
    char advance(); //see and move plus one to the next character
    bool isAtEnd();
};
