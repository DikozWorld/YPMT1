#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include "scanner.h"

// Node types for parse tree
enum NodeType {
    NODE_PROGRAM,
    NODE_DO_WHILE,
    NODE_ASSIGNMENT,
    NODE_PRINT,
    NODE_BINARY_OP,
    NODE_COMPARISON,
    NODE_IDENTIFIER,
    NODE_CONSTANT,
    NODE_EXPRESSION,
    NODE_TERM,
    NODE_FACTOR
};

// Parse tree node structure
struct ParseTreeNode {
    NodeType type;
    std::string value;
    std::vector<ParseTreeNode*> children;

    ParseTreeNode(NodeType t, const std::string& v = "") : type(t), value(v) {}
    ~ParseTreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

// Parser class
class Parser {
private:
    std::vector<Token> tokens;
    size_t currentPos;
    ParseTreeNode* root;
    bool errorFlag;
    std::string errorMessage;

    // Helper functions
    Token currentToken() const;
    Token peekToken() const;
    void consumeToken();
    void match(TokenTypeEnum expectedType, int expectedCode = -1);
    void error(const std::string& message);

    // Grammar rule functions
    ParseTreeNode* parseS();          // S → do S{;S} while B | id = E | print id
    ParseTreeNode* parseB();          // B → E < E | E > E
    ParseTreeNode* parseE();          // E → T {+T | -T}
    ParseTreeNode* parseT();          // T → num | id

    // Multiple statements handling
    std::vector<ParseTreeNode*> parseStatementList();

public:
    Parser(const std::vector<Token>& tokenList);
    ~Parser();

    bool parse();
    void printParseTree() const;
    void printErrors() const;
    bool hasErrors() const { return errorFlag; }

    // Optional: Get parse tree root for further processing
    ParseTreeNode* getParseTree() const { return root; }
};

#endif