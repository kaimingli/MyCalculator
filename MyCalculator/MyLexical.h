#pragma once

#include "stdafx.h"

enum TokenKind{
	BAD_TOKEN = 0,
	NUMBER_TOKEN = 1,
	ADD_OPERATER_TOKEN = 2,
	SUB_OPERATER_TOKEN = 3,
	MUL_OPERATER_TOKEN = 4,
	DIV_OPERATER_TOKEN = 5,
	POWER_OPERATER_TOKEN = 6,
	LEFT_BRACKET_TOKEN = 7,
	RIGHT_BRACKET_TOKEN = 8,
	END_TOKEN = 9
};


class Token
{
public:
	Token();
	Token(std::string s, TokenKind tokenkind);
	void set(std::string s, TokenKind tokenkind);
	std::string Print();
	std::string getstr();
	int gettype();
	~Token();
private:
	std::string s;
	TokenKind token;
};

class MyLexical
{
public:
	MyLexical();
	MyLexical(std::string s);
	~MyLexical();
	void Lexical();
	void Print();
	int sum();
	Token at(int i);
private:
	bool getToken(std::string s, int& pos, Token& token);
	std::vector<Token> tokens;
	std::string s;
};