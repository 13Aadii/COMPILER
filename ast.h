#pragma once

struct Expr{
    virtual ~Expr() {}
};
struct NumberExpr:Expr{
    double value;
    NumberExpr(double v):value(v){}
};
struct Stmt{
    virtual ~Stmt(){}
};
struct Printstmt:Stmt{
    Expr* expr;
    Printstmt(Expr* e): expr(e){}
};