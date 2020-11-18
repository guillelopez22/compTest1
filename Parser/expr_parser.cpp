#include <iostream>
#include <fstream>
#include "expr_lexer.h"
#include "expr_parser.h"
#include <string>


void Parser::input() {
    stmt_list();
}

void Parser::stmt_list() {
    stmt_list();
    stmt();
}

void Parser::stmt() {
    if (curr_token == Symbol::Print) {
        curr_token = lexer.getNextToken();
        expr();
    } else {
        assign();
    }
}

void Parser::assign() {
    if (curr_token == Symbol::Ident) {
        curr_token = lexer.getNextToken();
        if (curr_token == Symbol::OpAssign) {
            curr_token = lexer.getNextToken();
            expr();
        }
    }
}

void Parser::expr() {
    term();
    exprp();
}

void Parser::exprp() {
    if (curr_token == Symbol::OpAdd) {
        curr_token = lexer.getNextToken();
        term();
        exprp();
    }
}

void Parser::term() {
    factor();
    termp();
}

void Parser::termp() {
    if (curr_token == Symbol::OpMul) {
        curr_token = lexer.getNextToken();
        termp();
    }
}

void Parser::factor() {
    if (curr_token == Symbol::Ident) {
        curr_token = lexer.getNextToken();
    } else if (curr_token == Symbol::Number) {
        curr_token = lexer.getNextToken();
    } else if (curr_token == Symbol::OpenPar) {
        curr_token = lexer.getNextToken();
        expr();
        if (curr_token == Symbol::ClosePar) {
            curr_token = lexer.getNextToken();
        } else {
            throw std::string("Error");
        }
    } else if (curr_token == Symbol::ClosePar) {
        throw std::string("Error");
    }
}