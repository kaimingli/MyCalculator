// MyCalculator.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "MyLexical.h"
//#include <iostream>

using namespace std;

int main()
{
	MyLexical lexical("(-3/4)*(-.8.5334.3.+2/3-1/3)");
	lexical.Print();

	system("pause");
    return 0;
}

