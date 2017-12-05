#include "stdafx.h"
#include "MyLexical.h"

using namespace std;

MyLexical::MyLexical()
{
}

MyLexical::MyLexical(string s)
{
	this->s = s;
	Lexical();
}

MyLexical::~MyLexical()
{
}

void MyLexical::Lexical()
{
	int pos = 0;
	Token token;
	while (getToken(s,pos,token) == true) {
		tokens.push_back(token);
	}
	tokens.push_back(Token("END",TokenKind::END_TOKEN));
}

void MyLexical::Print()
{
	for (auto i = 0; i < tokens.size(); i++) {
		cout << tokens.at(i).Print() << endl;
	}
}

int MyLexical::sum()
{
	return s.size();
}

Token MyLexical::at(int i)
{
	return tokens.at(i);
}

//从string的pos位置开始，找到下一个token，函数运行后pos指向token之后第一个位置，token保存得到的token值，返回值表示是否寻找成功
bool MyLexical::getToken(string s, int& pos, Token& token)
{
	if (pos >= s.size())
		return false;
	string s_token = "";
	char current_char = s.at(pos);
	while (current_char == ' ') {
		current_char = s.at(++pos);
	}
	if (current_char == '/n')
		return false;
	while(isdigit(current_char) || current_char == '.'){
		s_token.append(1,current_char);
		token.set(s_token, TokenKind::NUMBER_TOKEN);
		pos++;
		if (pos == s.size()) {
			return true;
		}
		current_char = s.at(pos);
		if(!isdigit(current_char) && current_char != '.')
			return true;
	}
	if (current_char == '+') {
		s_token.append(1,current_char);
		token.set(s_token, TokenKind::ADD_OPERATER_TOKEN);
		++pos;
		return true;
	}
	else if (current_char == '-') {
		s_token.append(1,current_char);
		token.set(s_token, TokenKind::SUB_OPERATER_TOKEN);
		++pos;
		return true;
	}
	else if (current_char == '*') {
		s_token.append(1,current_char);
		token.set(s_token, TokenKind::MUL_OPERATER_TOKEN);
		++pos;
		return true;
	}
	else if (current_char == '/') {
		s_token.append(1,current_char);
		token.set(s_token, TokenKind::DIV_OPERATER_TOKEN);
		++pos;
		return true;
	}
	else if (current_char == '^') {
		s_token.append(1, current_char);
		token.set(s_token, TokenKind::POWER_OPERATER_TOKEN);
		++pos;
		return true;
	}
	else if (current_char == '(') {
		s_token.append(1, current_char);
		token.set(s_token, TokenKind::LEFT_BRACKET_TOKEN);
		++pos;
		return true;
	}
	else if (current_char == ')') {
		s_token.append(1, current_char);
		token.set(s_token, TokenKind::RIGHT_BRACKET_TOKEN);
		++pos;
		return true;
	}
	else{
		s_token.append(1, current_char);
		token.set(s_token,TokenKind::BAD_TOKEN);
		++pos;
		return true;
	}
}

Token::Token()
{
}

Token::Token(std::string s, TokenKind tokenkind)
{
	this->s = s;
	this->token = tokenkind;
}

void Token::set(std::string s, TokenKind tokenkind)
{
	this->s = s;
	this->token = tokenkind;
}

string Token::Print()
{
	return this->getstr();
}

string Token::getstr()
{
	return s;
}

int Token::gettype()
{
	return token;
}

Token::~Token()
{
}
