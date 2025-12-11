// tables.h
#ifndef TABLES_H
#define TABLES_H

#include <map>
#include <string>

// Function declarations for tables
void initKeywords();
int find_word(const std::string& word);
int make_id(const std::string& name);
int make_dig(int value);
int val_dig(int code);

// External variables
extern std::map<std::string, int> keywords;
extern std::map<std::string, int> identifiers;
extern std::map<int, int> constToCode;
extern std::map<int, int> codeToConst;
extern int nextId;
extern int nextConstCode;

#endif