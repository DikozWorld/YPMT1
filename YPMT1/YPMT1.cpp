// YPMT1.cpp
#include <iostream>
#include "tables.h"
#include "scanner.h"

using namespace std;

int main() {
    // No need for SetConsoleOutputCP with English text
    initKeywords();

    cout << "=== LABORATORY WORK 1 and 2 ===" << endl;
    cout << "1. Information tables" << endl;
    cout << "2. Lexical analyzer (scanner)" << endl;
    cout << "==================================" << endl;
    cout << "Language: S -> do S{;S} while B | id = E | print id" << endl;
    cout << endl;

    // Part 1: Demonstration of tables (Lab 1)
    cout << "=== PART 1: INFORMATION TABLES ===" << endl;
    cout << "1. Keywords table:" << endl;
    cout << "   find_word(\"do\") = " << find_word("do") << endl;
    cout << "   find_word(\"while\") = " << find_word("while") << endl;
    cout << "   find_word(\"print\") = " << find_word("print") << endl;
    cout << "   find_word(\"if\") = " << find_word("if") << " (not a keyword)" << endl;
    cout << endl;

    cout << "2. Identifiers table:" << endl;
    cout << "   make_id(\"x\") = " << make_id("x") << endl;
    cout << "   make_id(\"y\") = " << make_id("y") << endl;
    cout << "   make_id(\"x\") = " << make_id("x") << " (again)" << endl;
    cout << endl;

    cout << "3. Constants table:" << endl;
    cout << "   make_dig(10) = " << make_dig(10) << endl;
    cout << "   make_dig(255) = " << make_dig(255) << endl;
    cout << "   make_dig(10) = " << make_dig(10) << " (again)" << endl;
    cout << "   val_dig(1) = " << val_dig(1) << endl;
    cout << "   val_dig(2) = " << val_dig(2) << endl;
    cout << endl;

    // Part 2: Demonstration of scanner (Lab 2)
    cout << "=== PART 2: LEXICAL ANALYZER ===" << endl;

    // Example 1: Simple program
    string program1 = "do x = 10; print x while x < 20#";
    cout << "\nExample 1: \"" << program1 << "\"" << endl;
    vector<Token> tokens1 = scanner(program1);
    cout << "Token vector: ";
    print_tokens(tokens1);
    demonstrate_token_correspondence(program1, tokens1);

    // Example 2: Program with all token types
    string program2 = "do x = x + 5; y = 100; print y while y > 0#";
    cout << "\nExample 2 (all token types): \"" << program2 << "\"" << endl;
    vector<Token> tokens2 = scanner(program2);
    cout << "Token vector: ";
    print_tokens(tokens2);
    demonstrate_token_correspondence(program2, tokens2);

    // State diagram (homework)
    print_state_diagram();

    // Display table contents
    cout << "\n=== TABLE CONTENTS ===" << endl;
    cout << "\nIdentifiers table:" << endl;
    for (const auto& id : identifiers) {
        cout << "  " << id.first << " -> code " << id.second << endl;
    }

    cout << "\nConstants table:" << endl;
    for (const auto& cnst : codeToConst) {
        cout << "  code " << cnst.first << " -> value " << cnst.second << endl;
    }

    system("pause");
    return 0;
}