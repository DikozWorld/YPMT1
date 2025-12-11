// scanner.h
#ifndef SCANNER_H
#define SCANNER_H

#include <vector>
#include <string>

// Token types
enum TokenTypeEnum {
    TOKEN_ID,      // identifier
    TOKEN_DIG,     // number
    TOKEN_WORD,    // keyword or operator
    TOKEN_END      // end of program #
};

// Token structure
struct Token {
    TokenTypeEnum type;
    int code;      // code in the corresponding table
};

// Scanner functions
std::vector<Token> scanner(const std::string& input);
void print_tokens(const std::vector<Token>& tokens);
void demonstrate_token_correspondence(const std::string& input,
    const std::vector<Token>& tokens);
void print_state_diagram();

#endif