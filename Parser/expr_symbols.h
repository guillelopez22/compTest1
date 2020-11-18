#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum class Symbol {
    Ident,
    Eof,
    OpAssign,
    OpenPar,
    Number,
    OpAdd,
    ClosePar,
    OpMul,
    Print,
    Eol,
};

// struct SymbolInfo {
//     Symbol symbol_id;
//     std::string symbol_text;
// };