// tables.cpp
#include "tables.h"
#include <iostream>

using namespace std;

// Variable definitions
map<string, int> keywords;
map<string, int> identifiers;
map<int, int> constToCode;
map<int, int> codeToConst;
int nextId = 1;
int nextConstCode = 1;

// Function implementations
void initKeywords() {
    keywords["do"] = 1;
    keywords["while"] = 2;
    keywords["print"] = 3;
}

int find_word(const string& word) {
    auto it = keywords.find(word);
    return (it != keywords.end()) ? it->second : 0;
}

int make_id(const string& name) {
    if (identifiers.find(name) != identifiers.end()) {
        return identifiers[name];
    }
    identifiers[name] = nextId;
    return nextId++;
}

int make_dig(int value) {
    if (constToCode.find(value) != constToCode.end()) {
        return constToCode[value];
    }
    constToCode[value] = nextConstCode;
    codeToConst[nextConstCode] = value;
    return nextConstCode++;
}

int val_dig(int code) {
    return (codeToConst.find(code) != codeToConst.end()) ? codeToConst[code] : -1;
}