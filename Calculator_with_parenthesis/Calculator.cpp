#include <stack>
#include <string>
#include "Calculator.h"

using namespace std;

string ExchangePostFix(string str) {
	string tmp;
	stack<char> s;

	int line = -1;

	tmp.resize(100);

	for (int i = 0; i < str.length(); i++) {
		if (IsOperand(str[i])) {
			tmp[++line] = str[i];
			if (!IsOperand(str[i + 1]))
				tmp[++line] = ' ';
		}
		else if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				tmp[++line] = s.top();
				s.pop();
			}
			s.pop();
		}
		else if (IsOperator(str[i])) {
			while (!s.empty() && OperatorLevel(str[i]) <= OperatorLevel(s.top())) {
				tmp[++line] = s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}

	while (!s.empty()) {
		tmp[++line] = s.top();
		s.pop();
	}

	tmp.resize(line + 1);

	return tmp;
}

int ExpressionPostFix(string str) {
	stack<int> s;
	int num = 0;

	for (int i = 0; i < str.length(); i++) {

		if (IsOperand(str[i])) {
			num += str[i] - '0';
			if (i + 1 < str.length()) {
				if (IsOperand(str[i + 1]))
					num *= 10;
				else if (str[i + 1] == ' ') {
					s.push(num);
					num = 0;
				}
			}
		}
		else if (IsOperator(str[i])) {
			int operand1 = s.top(); s.pop();
			int operand2 = s.top(); s.pop();

			switch (str[i]) {
			case '+':
				s.push(operand2 + operand1); break;
			case '-':
				s.push(operand2 - operand1); break;
			case '*':
				s.push(operand2 * operand1); break;
			case '/':
				s.push(operand2 / operand1); break;
			}
		}
	}

	return s.top();
}

bool IsOperator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool IsOperand(char ch) {
	return '0' <= ch && ch <= '9';
}

int OperatorLevel(char ch) {
	switch (ch) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
	return -1;
}