#pragma once
#include "ast.h"

class Interpreter{
    public:
    void run(Stmt* stmt);
    private:
    double eval(Expr* expr);
};