#include <iostream>

using namespace std;

int main() {
	string x;
	int y;
	while (cin >> x >> y) {
		int num[6];
		for (int i = 0; i < 6; i ++) {
			num[i] = 0;
		}
		int e = (int) x.length() - 6;
		int head = 0;
		for (int i = 0; i < x.length(); i ++) {
			if (x[i] == '.') {
				e = i - 6;
			}
			else {
				num[head] = x[i] - '0';
				head ++;
			}
		}
		int pud[1000];
		for (int i = 0; i < 1000; i ++) {
			pud[i] = 0;
		}
		pud[0] = 1;
		e *= y;
		for (int i = 0; i < y; i ++) {
			int newpud[1000];
			for (int j = 0; j < 1000; j ++) {
				newpud[j] = 0;
			}
			for (int j = 0; j < 1000; j ++) {
				for (int k = 0; k < 6; k ++) {
					newpud[j+k] += pud[j] * num[6-k-1];
				}
			}
			for (int j = 0; j < 1000-1; j ++) {
				newpud[j+1] += newpud[j] / 10;
				newpud[j] %= 10;
			}
			for (int j = 0; j < 1000; j ++) {
				pud[j] = newpud[j];
			}
		}
		head = 999;
		while (head > 0 && pud[head] == 0) {
			head --;
		}
		int tail = 0;
		while (e < 0 && pud[tail] == 0) {
			tail ++;
			e ++;
		}
		for (int i = head; i >= tail-e; i --) {
			cout << pud[i];
		}
		if (e < 0) {
			cout << '.';
		}
		for (int i = tail-e-1; i >= tail; i --) {
			cout << pud[i];
		}
		cout << '\n';
	}
	return 0;
}

