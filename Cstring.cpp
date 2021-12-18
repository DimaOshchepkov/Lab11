

#include "Cstring.h"

void replaceC(char* str, char c1, char c2)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c1)
			str[i] = c2;
}
int countWord(char* str)
{
	
	char newStr[100] = {'\0'};
	newStr[0] = ' ';
	int i = 0;
	for (; str[i]!= '\0'; i++)
		newStr[i + 1] = str[i];
	int k = strlen(newStr);
	newStr[i] = ' ';
	newStr[i+1 ] = '\0';

	int count = 0;
	for (int i = 1; newStr[i] != '\0'; i++)
		if (newStr[i] != newStr[i-1] && (newStr[i] == ' ' || newStr[i - 1] == ' '))
			count++;
	return count/2;
}
char* asSentens(char* str)
{
	char newStr[100] = { '\0' };
	bool dot = false;
	newStr[0] = toupper(str[0]);
	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i] == '.') { dot = true; }
		if (dot && str[i] != '.' && str[i] != ' ') {
			dot = false;
			newStr[i] = toupper(str[i]);
		}
		else
			newStr[i] = str[i];
	}
	return newStr;
}
char* tolower(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
	return str;
}
char* toupper(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
	return str;
}
char* beginWordUp(char* str)
{
	str[0] = toupper(str[0]);
	for (int i = 1; str[i] != '\0'; i++)
		if (str[i] != ' ' && str[i - 1] == ' ')
			str[i] = toupper(str[i]);
		else
			str[i] = tolower(str[i]);
	return str;
}
char* changeRegistr(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == toupper(str[i]))
			str[i] = tolower(str[i]);
		else
			str[i] = toupper(str[i]);
	return str;
}
std::map<char, int> vocabulary(char* str)
{
	std::map <char, int> voc;
	std::map <char, int> :: iterator it;
	for (int i = 0; str[i] != '\0'; i++)
	{
		it = voc.find(str[i]);
		if (it == voc.end())
			voc[str[i]] = 1;
		else
			it->second += 1;
	}
	return voc;
}
char* street(char* str)
{
	char newStr[100] = { '\0' };
	int countUp = 0, countDot = 0;
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isupper(str[i]))
			countUp++;
		if (str[i] == '.')
			countDot++;
		if (countUp == 2 && countDot == 0)
		{
			newStr[j] = str[i];
			j++;
		}
	}
	newStr[j] = '.';
	return newStr;
}

cleanT cleanText(char* str)
{
	cleanT c;
	int i = 0;
	int j = 0;
	int spaceIns = 0, spaceAll = 0;
	c.newStr[0] = str[0];
	for (int i = 1; str[i] != '\0'; i++)
	{
		if (ispunct(c.newStr[j]) && str[i] != ' ')
		{
			j++;
			c.newStr[j] = ' ';
			c.countInsSpace += 1;
		}
		if (c.newStr[j] != ' ' && str[i] == ' ')
		{
			j++;
			c.newStr[j] = str[i];
			spaceIns++;
		}
		if (c.newStr[j] == ' ' && ispunct(str[i]))
		{
			c.newStr[j] = str[i];
		}
		if (c.newStr[j] != ' ' && ispunct(str[i]))
		{
			j++;
			c.newStr[j] = str[i];
		}
		if (isalpha(str[i]))
		{
			j++;
			c.newStr[j] = str[i];
		}
		if (str[i] == ' ')
			spaceAll++;
	}
	c.countDelSpace = spaceAll - spaceIns;
	return c;
}
char* delSpacePunctAndUp(char* str)
{
	char newStr[100] = { '\0' };
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (isalpha(str[i]))
		{
			newStr[j] = toupper(str[i]);
			j++;
		}
	return newStr;
}
bool isPolindrom(const char* str)
{
	bool cond = true;
	for (int i = 0; i < strlen(str) / 2; i++)
		cond *= (str[i] == str[strlen(str) - i - 1]);
	return cond;
}
const char* convertDot(char* str, char symbol, char* s)
{
	int j = 0;
	char newStr[100] = { '\0' };
	for(int i = 0; str[i] != '\0'; i++)
		if(str[i] == symbol)
			for (int k = 0; s[k] != '\0'; k++)
			{
				newStr[j] = s[k];
				j++;
			}
		else
		{
			newStr[j] = str[i];
			j++;
		}
	return newStr;
}