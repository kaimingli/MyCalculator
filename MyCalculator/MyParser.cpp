#include "stdafx.h"
#include "MyParser.h"

using namespace std;

MyParser::MyParser()
{
}

MyParser::MyParser(MyLexical &lexical)
{
	this->lexical = lexical;
	this->currentpos = 0;
	Parser();
}


MyParser::~MyParser()
{
}

void MyParser::Parser()
{
	result = E();
}

double MyParser::E()
{
	cout << "enter E" << endl;
	Token token = readnow();
	switch (token.gettype())
	{
	case TokenKind::NUMBER_TOKEN:
		return T() + E_();
	case TokenKind::SUB_OPERATER_TOKEN:
		return T() + E_();
	case TokenKind::LEFT_BRACKET_TOKEN:
		return T() + E_();
	default:
		cout << " ------------------------wrong-----------------------E" << endl;
		break;
	}
	return 0.0;
}

double MyParser::E_()
{
	cout << "enter E_" << endl;
	Token token = readnow();
	switch (token.gettype())
	{
	case TokenKind::ADD_OPERATER_TOKEN:
		match('+');
		return T() + E_();
	case TokenKind::SUB_OPERATER_TOKEN:
		match('-');
		return -T() + E_();
	case TokenKind::RIGHT_BRACKET_TOKEN:
	case TokenKind::END_TOKEN:
	default:
		break;
	}
	return 0.0;
}

double MyParser::T()
{
	cout << "enter T" << endl;
	Token token = readnow();
	switch (token.gettype())
	{
	case TokenKind::NUMBER_TOKEN:
	case TokenKind::SUB_OPERATER_TOKEN:
	case TokenKind::LEFT_BRACKET_TOKEN:
		return F() * T_();
	default:
		cout << " ------------------------wrong-----------------------T" << endl;
		break;
	}
	return 0.0;
}

double MyParser::T_()
{
	cout << "enter T_" << endl;
	Token token = readnow();
	switch (token.gettype())
	{
	case TokenKind::MUL_OPERATER_TOKEN:
		match('*');
		return F() * T_();
	case TokenKind::DIV_OPERATER_TOKEN:
		match('/');
		return 1/(F() / T_());
	case TokenKind::ADD_OPERATER_TOKEN:
	case TokenKind::SUB_OPERATER_TOKEN:
	case TokenKind::RIGHT_BRACKET_TOKEN:
	case TokenKind::END_TOKEN:
		return 1;
	default:
		break;
	}
	return 0;
}

double MyParser::F()
{
	cout << "enter F" << endl;
	Token token = readnow();
	switch (token.gettype())
	{
	case TokenKind::SUB_OPERATER_TOKEN:
		match('-');
		return -N();
	case TokenKind::NUMBER_TOKEN:
	case TokenKind::LEFT_BRACKET_TOKEN:
		return N();
	default:
		cout << " ------------------------wrong-----------------------F" << endl;
		break;
	}
	return 0.0;
}

double MyParser::N()
{
	cout << "enter N" << endl;
	Token token = readnow();
	double m;
	double n_;
	switch (token.gettype())
	{
	case TokenKind::NUMBER_TOKEN:
	case TokenKind::LEFT_BRACKET_TOKEN:
		m = M();
		n_ = N_();
		return pow(m, n_);
	default:
		cout << " ------------------------wrong-----------------------N" << endl;
		break;
	}
	return 0.0;
}

double MyParser::N_()
{
	cout << "enter N_" << endl;
	Token token = readnow();
	switch (token.gettype())
	{
	case TokenKind::POWER_OPERATER_TOKEN:
		match('^');
		return N();
	case TokenKind::ADD_OPERATER_TOKEN:
	case TokenKind::SUB_OPERATER_TOKEN:
	case TokenKind::MUL_OPERATER_TOKEN:
	case TokenKind::DIV_OPERATER_TOKEN:
	case TokenKind::RIGHT_BRACKET_TOKEN:
	case TokenKind::END_TOKEN:
		return 1;
	default:
		cout << " ------------------------wrong-----------------------N_" << endl;
		break;
	}
}

double MyParser::M()
{
	cout << "enter M" << endl;
	double temp = 0.0;
	Token token = readnow();
	switch (token.gettype())
	{
	case TokenKind::NUMBER_TOKEN:
		return match('1');
	case TokenKind::LEFT_BRACKET_TOKEN:
		match('(');
		temp = E();
		match(')');
		return temp;
	default:
		cout << " ------------------------wrong-----------------------M" << endl;
		break;
	}
}

double MyParser::match(char c)
{
	cout << "match ------  " << c << endl;
	string s = lexical.at(currentpos).getstr();
	//传入-1表示是数字，做数字格式的判断
	if (c == '1') {
		double d = atof(s.c_str());
		currentpos ++;
		return d;
	}
	string temp;
	temp.append(1,c);
	if (s == temp) {
		currentpos++;
		return 0.0;
	}
	cout << " ------------------------wrong-----------------------match" << endl;
	return -1;
	
}

Token MyParser::readnext()
{
	if (currentpos == lexical.sum()-1) {
		Token token("",TokenKind::END_TOKEN);
		return token;
	}
	return lexical.at(currentpos+1);
}

Token MyParser::readnow()
{
	cout << "getin" << lexical.at(currentpos).getstr() << lexical.at(currentpos).gettype() <<endl;
	return lexical.at(currentpos);
}

double MyParser::print()
{
	return result;
}
