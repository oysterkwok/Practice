#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int bin_search(int head, int tail, int e, vector<int> result);
int ext_cmp(vector<int>, vector<int>);
vector<int> ext_mult(vector<int>, vector<int>);
vector<int> ext_exp(int, int);

int bin_search(int head, int tail, int e, vector<int> result) {
	int mid = (head + tail) / 2;
	int check = ext_cmp(ext_exp(mid, e), result);
	if (check == 0) {
		return mid;
	}
	if (check < 0) {
		return bin_search(mid+1, tail, e, result);
	}
	if (check > 0) {
		return bin_search(head, mid-1, e, result);
	}
	return -1;
}

int ext_cmp(vector<int> x, vector<int> y) {
	if (x.size() > y.size()) {
		return 1;
	}
	if (x.size() < y.size()) {
		return -1;
	}
	for (int i = (int) x.size()-1; i >= 0; i --) {
		if (x[i] > y[i]) {
			return 1;
		}
		if (x[i] < y[i]) {
			return -1;
		}
	}
	return 0;
}

vector<int> ext_mult(vector<int> x, vector<int> y) {
	vector<int> result;
	result.resize(x.size()+y.size()-1, 0);
	for (int i = 0; i < x.size(); i ++) {
		for (int j = 0; j < y.size(); j ++) {
			result[i+j] += x[i] * y[j];
		}
	}
	for (int i = 0; i < result.size()-1; i ++) {
		result[i+1] += result[i] / 10;
		result[i] %= 10;
	}
	if (result[result.size()-1] > 9) {
		result.push_back(result[result.size()-1] / 10);
		result[result.size()-2] %= 10;
	}
	return result;
}

vector<int> ext_exp(int base, int e) {
	vector<int> ext_base;
	while (base > 0) {
		ext_base.push_back(base % 10);
		base /= 10;
	}
	vector<int> result;
	result.push_back(1);
	for (int i = 0; i < e; i ++) {
		result = ext_mult(result, ext_base);
	}
	return result;
}

int main() {
	string str;
	while (getline(cin, str) != 0) {
		int e = atoi(str.c_str());
		getline(cin, str);
		vector<int> result;
		for (int i = 0; i < str.length(); i ++) {
			result.push_back(str[str.length()-1-i] - '0');
		}
		int answer = bin_search(1, 1000000000, e, result);
		cout << answer << '\n';
	}
}
