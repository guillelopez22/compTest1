#ifndef _PARSER_H
#define _PARSER_H

#include <iosfwd>
#include "expr_lexer.h"
#include "expr_symbols.h"
#include "expr_parser.h"

class Parser
{
public:
    Parser(Lexer& lexer, std::ostream& out): lexer(lexer), out(out)
    {}

    void parse() {
        curr_token = lexer.getNextToken();
        input();
    }

private:
    Lexer& lexer;
    Symbol curr_token;

    void input();
    void stmt_list();
    void stmt();
    void assign();
    void expr();
    void exprp();
    void term();
    void termp();
    void factor();
    std::ostream& out;
};

#endif
