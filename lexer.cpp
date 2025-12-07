#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string&s) : src(s), index(0), line(1), col(1) {}
char Lexer::peek(){
    return isAtEnd() ? '\0':src[index];
}
char Lexer::advance(){
    char c=peek();
    index++;
    col++;
    return c;
}
bool Lexer::isAtEnd(){
    return index >=src.size();
}
Token Lexer::nextToken(){
    while(!isAtEnd()){
        char c= advance();

        //skip whitespace
        if(isspace(c)){
            if(c=='\n'){line++; col=1;}
            continue;
        }
        //Number
        if(isdigit(c)){
            std::string num;
            num.push_back(c);

            while(isdigit(peek())){
                num.push_back(advance());
            }
            return Token{TokenKind::Number, std::stod(num),line,col};
        }

        //keyword print
        if(c=='p'){
            if(peek()=='r') advance();
            if(peek() =='i') advance();
            if(peek() =='n') advance();
            if(peek()=='t') advance();
            return Token{TokenKind::Print, 0, line,col};
        }
        if(c==';') {return Token{TokenKind::Semicolon, 0, line,col};}
    }

    return Token{TokenKind::EndOfFile,0,line,col};
}