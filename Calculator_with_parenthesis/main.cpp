#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

int main() {
	string str;

	getline(cin, str);

	str = ExchangePostFix(str);
	cout << str << endl;
	cout << ExpressionPostFix(str) << endl;
}