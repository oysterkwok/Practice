#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int sum[105];
	for (int i = 0; i < 105; i ++) {
		sum[i] = 0;
	}
	string str;
	getline(cin, str);
	while (strcmp(str.c_str(), "0") != 0) {
		for (int i = 0; i < str.length(); i ++) {
			sum[i] += str[str.length()-i-1] - '0';
			sum[i+1] += sum[i] / 10;
			sum[i] %= 10;
		}
		getline(cin, str);
	}
	int tail = 104;
	while (sum[tail] == 0 && tail > 0) {
		tail --;
	}
	for (int i = tail; i >= 0; i --) {
		cout << sum[i];
	}
	cout << '\n';
	return 0;
}