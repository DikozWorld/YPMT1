#include "scanner.h"
#include "tables.h"
#include <iostream>
#include <cctype>
#include <map>

using namespace std;

map<char, int> operators = {
    {'=', 4}, {'<', 5}, {'>', 6},
    {'+', 7}, {'-', 8}, {';', 9}
};

vector<Token> scanner(const string& input) {
    vector<Token> tokens;
    int i = 0;
    int n = input.length();

    while (i < n) {
        char c = input[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (c == '#') {
            tokens.push_back({ TOKEN_END, 0 });
            break;
        }

        if (isalpha(c)) {
            string ident;
            while (i < n && (isalnum(input[i]))) {
                ident += input[i];
                i++;
            }

            int kw_code = find_word(ident);
            if (kw_code > 0) {
                tokens.push_back({ TOKEN_WORD, kw_code });
            }
            else {
                int id_code = make_id(ident);
                tokens.push_back({ TOKEN_ID, id_code });
            }
            continue;
        }

        if (isdigit(c)) {
            string num_str;
            while (i < n && isdigit(input[i])) {
                num_str += input[i];
                i++;
            }
            int value = stoi(num_str);
            int const_code = make_dig(value);
            tokens.push_back({ TOKEN_DIG, const_code });
            continue;
        }

        auto op_it = operators.find(c);
        if (op_it != operators.end()) {
            tokens.push_back({ TOKEN_WORD, op_it->second });
            i++;
            continue;
        }

        cout << "Error: unknown character '" << c << "'" << endl;
        i++;
    }

    return tokens;
}

void print_tokens(const vector<Token>& tokens) {
    for (const auto& token : tokens) {
        switch (token.type) {
        case TOKEN_ID:
            cout << "(ID," << token.code << ") ";
            break;
        case TOKEN_DIG:
            cout << "(DIG," << token.code << ") ";
            break;
        case TOKEN_WORD:
            cout << "(WORD," << token.code << ") ";
            break;
        case TOKEN_END:
            cout << "(END,0) ";
            break;
        }
    }
    cout << endl;
}

void demonstrate_token_correspondence(const string& input, const vector<Token>& tokens) {
    cout << "\nToken to source code correspondence:" << endl;

    vector<string> token_strings;
    int i = 0;
    int n = input.length();

    while (i < n && input[i] != '#') {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        if (isalpha(input[i])) {
            string ident;
            while (i < n && isalnum(input[i])) {
                ident += input[i];
                i++;
            }
            token_strings.push_back(ident);
            continue;
        }

        if (isdigit(input[i])) {
            string num;
            while (i < n && isdigit(input[i])) {
                num += input[i];
                i++;
            }
            token_strings.push_back(num);
            continue;
        }

        if (operators.find(input[i]) != operators.end()) {
            token_strings.push_back(string(1, input[i]));
            i++;
            continue;
        }

        i++;
    }

    for (size_t j = 0; j < tokens.size() && j < token_strings.size(); j++) {
        string token_type;
        switch (tokens[j].type) {
        case TOKEN_ID: token_type = "ID"; break;
        case TOKEN_DIG: token_type = "DIG"; break;
        case TOKEN_WORD:
            if (keywords.find(token_strings[j]) != keywords.end()) {
                token_type = "KEYWORD";
            }
            else {
                token_type = "OPERATOR";
            }
            break;
        case TOKEN_END: token_type = "END"; break;
        }

        cout << token_strings[j] << " \t-> (" << token_type << "," << tokens[j].code << ")" << endl;
    }
}
