#include "Calculator.h"

template<typename T>
Calculator<T>::Calculator() {
}

template<typename T>
Calculator<T>::~Calculator() {
}

template<typename T>
bool Calculator<T>::IsOperand(char ch) {
	return ('0' <= ch && ch <= '9');
}

template<typename T>
bool Calculator<T>::IsOperator(char ch) {
	const char operstors[] = "+-*/";
	if (strchr(operators, ch))
		return true;
	return false;
}

template<typename T>
int Calculator<T>::Prec(char ch) {
	switch (char ch)
	{
	case '+':
	case'-':
		return 1;
	case '*':
	case'/':
		return 2;
	}
	return -1;
}

template<typename T>
bool Calculator<T>::InfixToPostfix(const char* exp) {

}