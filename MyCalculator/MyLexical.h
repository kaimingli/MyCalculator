#pragma once

#include "stdafx.h"

enum TokenKind{
	BAD_TOKEN,
	NUMBER_TOKEN,
	ADD_OPERATER_TOKEN,
	SUB_OPERATER_TOKEN,
	MUL_OPERATER_TOKEN,
	DIV_OPERATER_TOKEN,
	END_TOKEN
};

enum ReadStatus {
	INITIAL_STATUS,
	NUM_STATUS,
	DOT_STATUS,
	OPE_STATUS
};

class Token
{
public:
	Token();
	Token(std::string s, TokenKind tokenkind);
	void set(std::string s, TokenKind tokenkind);
	std::string Print();
	~Token();
private:
	std::string s;
	TokenKind token;
};

class MyLexical
{
public:
	MyLexical(std::string s);
	~MyLexical();
	void Lexical();
	void Print();
private:
	bool getToken(std::string s, int& pos, Token& token);
	std::vector<Token> tokens;
	std::string s;
};