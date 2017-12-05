#pragma once

#include "MyLexical.h"

class MyParser
{
public:
	MyParser();
	MyParser(MyLexical &lexical);
	~MyParser();
	void Parser();
	double E();
	double E_();
	double T();
	double T_();
	double F();
	double N();
	double N_();
	double M();
	double match(char c);
	Token readnext();
	Token readnow();
	double print();
private:
	MyLexical lexical;
	int currentpos;
	double result;
};

