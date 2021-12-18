#pragma once

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <map>

void replaceC(char* str, char c1, char c2);
int countWord(char* str);
char* asSentens(char* str);
char* tolower(char* str);
char* toupper(char* str);
char* beginWordUp(char* str);
char* changeRegistr(char* str);
std::map<char, int> vocabulary(char* str);
char* street(char* str);
struct cleanT {
	int countDelSpace = 0, countInsSpace = 0;
	char newStr[100] = { '\0' };
};
cleanT cleanText(char* str);
char* delSpacePunctAndUp(char* str);
bool isPolindrom(const char* str);
const char* convertDot(char* str, char symbol, char* s);