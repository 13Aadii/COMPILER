#pragma once
#include<vector>
#include "token.h"
#include "ast.h"

class Parser{
    std::vector<Token> tokens;
    int pos;
    public:
    Parser(const std::vector<Token>& t);
    Stmt* parsestatement();
    private:
    Token peek();
    Token advance();
    bool match(TokenKind kind);
    Expr* parseexpression();
};