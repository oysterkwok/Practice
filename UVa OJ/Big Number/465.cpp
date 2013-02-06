#include <iostream>

using namespace std;

int main() {
	string exp;
	while (getline(cin, exp)) {
		unsigned long num1, num2;
		char op;
		bool b1, b2, b3;
		num1 = 0;
		num2 = 0;
		b1 = false;
		b2 = false;
		b3 = false;
		
		int head = 0;
		while (head < exp.length() && exp[head] >= '0' && exp[head] <= '9') {
			if (!b1) {
				num1 = num1 * 10 + exp[head] - '0';
				if (num1 > 2147483647) {
					b1 = true;
				}
			}
			head ++;
		}
		
		while (head < exp.length() && !(exp[head] == '+' || exp[head] == '*')) {
			head ++;
		}
		op = exp[head];
		while (head < exp.length() && (exp[head] < '0' || exp[head] > '9')) {
			head ++;
		}

		while (head < exp.length() && exp[head] >= '0' && exp[head] <= '9') {
			if (!b2) {
				num2 = num2 * 10 + exp[head] - '0';
				if (num2 > 2147483647) {
					b2 = true;
				}
			}
			head ++;
		}

		if (op == '+') {
			if (b1 || b2) {
				b3 = true;
			}
			else {
				double num3 = num1 + num2;
				if (num3 > 2147483647) {
					b3 = true;
				}
			}
		}
		else {
			if (num1 == 0 || num2 == 0) {
				b3 = false;
			}
			else if (b1 || b2) {
				b3 = true;
			}
			else {
				float num3 = num1 * num2;
				if (num3 > 2147483647) {
					b3 = true;
				}				
			}
		}
		
		cout << exp << '\n';
		if (b1) {
			cout << "first number too big\n";
		}
		if (b2) {
			cout << "second number too big\n";
		}
		if (b3) {
			cout << "result too big\n";
		}
	}
	return 0;
}
