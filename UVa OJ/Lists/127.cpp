#include<iostream>
#include<vector>

using namespace std;

vector<vector<string> > deck;

int main() {
	string str;
	cin >> str;
	while (str[0] != '#') {
		deck.clear();
		deck.resize(52);
		deck[0].push_back(str);
		for (int i = 1; i < 52; i ++) {
			cin >> str;
			deck[i].push_back(str);
		}
		
		bool moved = true;
		while (moved) {
			moved = false;
			for (int pos = 0; pos < deck.size(); pos ++) {
				if (pos > 2 && (deck[pos-3][deck[pos-3].size()-1][0] == deck[pos][deck[pos].size()-1][0] || deck[pos-3][deck[pos-3].size()-1][1] == deck[pos][deck[pos].size()-1][1])) {
					moved = true;
					deck[pos-3].push_back(deck[pos][deck[pos].size()-1]);
					deck[pos].erase(deck[pos].end());
					if (deck[pos].empty()) {
						deck.erase(deck.begin() + pos);
					}
					break;
				}
				if (pos > 0 && (deck[pos-1][deck[pos-1].size()-1][0] == deck[pos][deck[pos].size()-1][0] || deck[pos-1][deck[pos-1].size()-1][1] == deck[pos][deck[pos].size()-1][1])) {
					moved = true;
					deck[pos-1].push_back(deck[pos][deck[pos].size()-1]);
					deck[pos].erase(deck[pos].end());
					if (deck[pos].empty()) {
						deck.erase(deck.begin() + pos);
					}
					break;
				}
			}
		}
		if (deck.size() == 1) {
			cout << "1 pile remaining: 52\n";
		}
		else {
			cout << deck.size() << " piles remaining:";
			for (int i = 0; i < deck.size(); i ++) {
				cout << ' ' << deck[i].size();
			}
			cout << '\n';
		}
		cin >> str;
	}
}
