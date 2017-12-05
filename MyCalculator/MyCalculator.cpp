// MyCalculator.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "MyLexical.h"
#include "MyParser.h"
//#include <iostream>

using namespace std;

int main()
{
	MyLexical lexical("(-3/4)*(-8.5334+2/3-1/3)");
	//lexical.Print();
	MyParser myparser(lexical);
	cout << myparser.print() << endl;


	system("pause");
    return 0;
}