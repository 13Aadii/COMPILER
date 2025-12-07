#include<iostream>
#include<vector>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

int main(){
    std::string program = "print 30;";
    Lexer lex(program);
    std::vector<Token> tokens;
    while(true){
        Token t = lex.nextToken();
        tokens.push_back(t);
        if(t.kind == TokenKind::EndOfFile) break;
    }
    Parser parser(tokens);
    Stmt* stmt = parser.parsestatement();
    Interpreter interp;
    interp.run(stmt);
    return 0;
}