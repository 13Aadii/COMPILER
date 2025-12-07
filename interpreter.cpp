#include "interpreter.h"
#include<iostream>

double Interpreter::eval(Expr* expr){
    if(auto num = dynamic_cast<NumberExpr*>(expr)) return num ->value;
    return 0;
}
void Interpreter::run(Stmt* stmt){
    if(auto p = dynamic_cast<Printstmt*>(stmt)){
        std::cout << eval(p->expr) << "\n";
    }
}