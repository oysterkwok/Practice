#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool found;
int n;

bool play_tree(int);

bool play_tree(int sum) {
	char ch;
	cin >> ch;
	string num_buf;
	bool both_empty = true;
	while (ch != ')') {
		if (ch == '(') {
			if (!play_tree(sum + atoi(num_buf.c_str()))) {
				both_empty = false;
			}
		}
		if (ch >= '0' && ch <= '9') {
			num_buf += ch;
		}
		if (ch == '-' || ch == '+') {
			num_buf += ch;
		}
		cin >> ch;
	}
	if (num_buf.size() == 0) {
		return true;
	}
	else {
		if (both_empty && n == (sum + atoi(num_buf.c_str()))) {
			found = true;
		}
		return false;
	}
}

int main() {
	while (cin >> n) {
		char ch;
		cin >> ch;
		while (ch != '(') {
			cin >> ch;
		}
		found = false;
		play_tree(0);
		if (found) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}