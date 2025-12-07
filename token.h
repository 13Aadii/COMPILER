#pragma once
#include<string>

//to understand what type of tokens we have
enum class TokenKind{
    Print, //print keyword
    Number, //number
    Semicolon, //semicolon
    EndOfFile //end of file
};

//the basic that an individual token must have
struct Token{
    TokenKind kind; //what type of token it is
    double number; //storing number
    int line, col; //line and column number
};