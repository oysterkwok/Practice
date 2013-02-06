#include <iostream>

using namespace std;

int main() {
	string num1, num2;
	while (cin >> num1 >> num2) {
		int sum[600];
		for (int i = 0; i < 600; i ++) {
			sum[i] = 0;
		}
		for (int i = 0; i < num1.length(); i ++) {
			for (int j = 0; j < num2.length(); j ++) {
				sum[i+j] += (num1[num1.length()-i-1]-'0') * (num2[num2.length()-j-1]-'0');
			}
		}
		for (int i = 0; i < 599; i ++) {
			sum[i+1] += sum[i] / 10;
			sum[i] %= 10;
		}
		int tail = 599;
		while (tail > 0 && sum[tail] == 0) {
			tail --;
		}
		for (int i = tail; i >= 0; i --) {
			cout << sum[i];
		}
		cout << '\n';
	}
	return 0;
}