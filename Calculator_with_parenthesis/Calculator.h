#pragma once
#include <stack>

template<typename T>
class Calculator
{
	std::stack<T> stack;
public:
	Calculator();
	~Calculator();

	bool IsOperand(char ch);
	bool IsOperator(char ch);

	int Prec(char ch);

	bool InfixToPostfix(const char* exp);
};