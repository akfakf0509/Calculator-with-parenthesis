#pragma once
#include <string>

using namespace std;

string ExchangePostFix(string);
int ExpressionPostFix(string);
bool IsOperator(char);
bool IsOperand(char);
int OperatorLevel(char);