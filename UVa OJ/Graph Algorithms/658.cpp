#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

string patch(string, string, string);
string patch(string src, string key, string value) {
	for (int i = 0; i < src.length(); i ++) {
		if (key[i] == '-' && src[i] == '+') {
			return src;
		}
		if (key[i] == '+' && src[i] == '-') {
			return src;
		}
	}
	string result;
	for (int i = 0; i < src.length(); i ++) {
		if (value[i] == '0') {
			result += src[i];
		}
		else {
			result += value[i];
		}
	}
	return result;
}

int main() {
	int m, n;
	int pn = 0;
	cin >> m >> n;
	while (m > 0 && n > 0) {
		pn ++;
		string init_stat;
		for (int i = 0; i < m; i ++) {
			init_stat += '+';
		}
		string final_stat;
		for (int i = 0; i < m; i ++) {
			final_stat += '-';
		}

		vector<int> ti;
		vector<string> ki, vi;
		for (int i = 0; i < n; i ++) {
			int t;
			string k, v;
			cin >> t >> k >> v;
			ti.push_back(t);
			ki.push_back(k);
			vi.push_back(v);
		}
		
		map<string, int> stats;
		stats[init_stat] = 0;
		
		vector<string> new_stats;
		new_stats.push_back(init_stat);
		
		int i = 0;
		while (i < new_stats.size()) {
			for (int j = 0; j < n; j ++) {
				string result = patch(new_stats[i], ki[j], vi[j]);
				map<string, int>::iterator iter = stats.find(result);
				if (iter == stats.end()) {
					new_stats.push_back(result);
					stats[result] = stats[new_stats[i]] + ti[j];
				}
				else if (stats[result] > stats[new_stats[i]] + ti[j]) {
					stats[result] = stats[new_stats[i]] + ti[j];
				}
			}
			if (strcmp(final_stat.c_str(), new_stats[i].c_str()) == 0) {
				break;
			}
			i ++;
		}
		
		cout << "Product " << pn << '\n';
		if (stats.find(final_stat) == stats.end()) {
			cout << "Bugs cannot be fixed.\n";
		}
		else {
			cout << "Fastest sequence takes " << stats[final_stat] << " seconds.\n";
		}
		cout << '\n';
		cin >> m >> n;
	}
}
