#include "parser.h"

Parser::Parser(const std::vector<Token>& t): tokens(t), pos(0) {}
Token Parser::peek(){ return tokens[pos];}
Token Parser::advance() { return tokens[pos++];}
bool Parser::match(TokenKind kind){return peek().kind == kind;}

Expr* Parser::parseexpression(){
    //expression = number
    Token t = advance();
    return new NumberExpr(t.number);
}

Stmt* Parser::parsestatement(){
    if(match(TokenKind::Print)){
        advance(); //consume print
        Expr* expr = parseexpression();
        if(match(TokenKind::Semicolon)) advance();
        return new Printstmt(expr);
    }
    return nullptr;
}