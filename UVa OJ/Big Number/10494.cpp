#include <iostream>
#include <vector>

using namespace std;

int main() {
	string num1;
	char op;
	unsigned long long num2;
	
	while (cin >> num1 >> op >> num2) {
		unsigned long long modresult = 0;
		vector<int> divresult;
		int head = 0;
		while (head < num1.length()) {
			modresult *= 10;
			modresult += num1[head] - '0';
			divresult.push_back(modresult / num2);
			modresult %= num2;
			head ++;
		}
		if (op == '/') {
			head = 0;
			while (divresult[head] == 0 && head < divresult.size()-1) {
				head ++;
			}
			for (int i = head; i < divresult.size(); i ++) {
				cout << divresult[i];
			}
			cout << '\n';
		}
		else {
			cout << modresult << '\n';
		}
	}
	return 0;
}