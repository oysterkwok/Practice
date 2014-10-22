//
//  main.cpp
//  Hedgedog
//
//  Created by Oyster Kwok on 8/30/14.
//  Finally completed on 10/18/14. 
//  Copyright (c) 2014 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class board {
public:
	int n;
	vector<vector<int> > grid;
	vector<pair<int, int> > cord;
	
	void init(int _n) {
		n = _n;
		grid.resize(n);
		for (int i = 0; i < n; i++) {
			grid[i].resize(n, 0);
		}
		cord.resize(n*n+1, pair<int, int>(-1, -1));
	}

	void copy(board & _b) {
		n = _b.n;
		grid = _b.grid;
		cord = _b.cord;
	}
	
	void print() {
		for (int i = 0; i < n; i++) {
			if (i*2 == n) {
				cout << '\n';
			}
			for (int j = 0; j < n; j++) {
				if (j*2 == n) {
					cout << "|\t";
				}
				cout << grid[i][j] << '\t';
			}
			cout << '\n';
		}
	}
	
	void fill(int x, int y, int v) {
		if (grid[x][y] > 0) {
			cout << "Error in Fill: grid occupied\n";
			print();
			cout << "Try to Fill " << x << ',' << y << " -> " << v << '\n';
			string s;
			cin >> s;
		}
		grid[x][y] = v;
		if (cord[v].first >= 0) {
			cout << "Error in Fill: cord occupied\n";
		}
		cord[v] = pair<int, int>(x, y);
	}
	
	void erase(int x, int y) {
		if (cord[grid[x][y]].first < 0) {
			cout << "Error in Erase: cord empty\n";
		}
		cord[grid[x][y]] = pair<int, int>(-1, -1);
		if (grid[x][y] <= 0) {
			cout << "Error in Erase: grid empty\n";
		}
		grid[x][y] = 0;
	}
	
	// [0,0] [0,1]
	// [1,0] [1,1]
	vector<pair<int, int> > get_move(int x, int y, int v) {
		// cout << "GM " << x << ',' << y << '-' << v << '\n';
		vector<pair<int, int> > moves;
		if (x*2 < n && y*2 < n) {
			for (int i = n/2; i < n; i++) {
				if (grid[x][i] == 0) {
					moves.push_back(pair<int, int>(x, i));
				}
				if (grid[x][i] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
				
				if (grid[i][y] == 0) {
					moves.push_back(pair<int, int>(i, y));
				}
				if (grid[i][y] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
			}
		}
		else if (x*2 < n) {
			for (int i = n/2; i < n; i++) {
				if (grid[i][y] == 0) {
					moves.push_back(pair<int, int>(i, y));
				}
				if (grid[i][y] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
				
				if (grid[x][i-n/2] == 0) {
					moves.push_back(pair<int, int>(x, i-n/2));
				}
				if (grid[x][i-n/2] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
			}
		}
		else if (y*2 >= n) {
			for (int i = 0; i < n/2; i++) {
				if (grid[x][i] == 0) {
					moves.push_back(pair<int, int>(x, i));
				}
				if (grid[x][i] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
				
				if (grid[i][y] == 0) {
					moves.push_back(pair<int, int>(i, y));
				}
				if (grid[i][y] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
			}
		}
		else {
			for (int i = 0; i < n/2; i++) {
				if (grid[i][y] == 0) {
					moves.push_back(pair<int, int>(i, y));
				}
				if (grid[i][y] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
				
				if (grid[x][i+n/2] == 0) {
					moves.push_back(pair<int, int>(x, i+n/2));
				}
				if (grid[x][i+n/2] == v) {
					moves.clear();
					moves.push_back(cord[v]);
					return moves;
				}
			}
		}
		if (cord[v].first >= 0) {
			moves.clear();
		}
		return moves;
	}
	
	vector<set<pair<int, int> > > paths;
	vector<pair<int, int> > current_path;
	
	void dfs(int s, int v, int t) {
		if (t <= v) {
			vector<pair<int, int> > moves = get_move(current_path[t-1].first, current_path[t-1].second, t);
			// cout << "#moves: " << moves.size() << '\n';
			for (int i = 0; i < moves.size(); i++) {
				if (cord[t].first < 0) {
					current_path[t] = moves[i];
					fill(moves[i].first, moves[i].second, t);
					dfs(s, v, t+1);
					erase(moves[i].first, moves[i].second);
					current_path[t] = pair<int, int>(-1, -1);
				}
				else {
					current_path[t] = moves[i];
					dfs(s, v, t+1);
					current_path[t] = pair<int, int>(-1, -1);
				}
			}
		}
		else {
			cout << "[+]\n";
			for (int i = s; i < v; i++) {
				paths[i].insert(current_path[i]);
			}
		}
	}
	
	int iterate() {
		int added = 0;
		int s = 0;
		int v = 1;
		while (true) {
			while (s <= n*n && cord[s].first < 0) {
				// cout << s << '~' << cord[s].first << 'x' << cord[s].second << '\n';
				s++;
			}
			// cout << "s=" << s << '\n';
			v = s+1;
			while (v <= n*n && cord[v].first < 0) {
				v++;
			}
			// cout << "v=" << v << '\n';
			if (v > n*n) {
				break;
			}
			if (v - s > 1) {
				// cout << "Running " << s << " -> " << v << '\n';
				paths.clear();
				paths.resize(n*n+1);
				current_path.clear();
				current_path.resize(n*n+1);
				current_path[s] = cord[s];
				dfs(s, v, s+1);
				// cout << 's' << s << 'v' << v << '\n';
				for (int i = s; i < v; i++) {
					if (cord[i].first < 0 && paths[i].size() == 1) {
						added++;
						set<pair<int, int> >::iterator iter = paths[i].begin();
						cout << "+Add: " << i << '\n';
						fill(iter->first, iter->second, i);
					}
				}
				// print();
			}
			s = v;
			// cout << "s=v=" << s << '\n';
		}
		cout << "Add: " << added << '\n';
		// print();
		return added;
	}
	
	int iterate_deep() {
		int added = 0;
		int v = n*n;
		int s = 1;
		paths.clear();
		paths.resize(v-s);
		current_path.clear();
		current_path.resize(n*n+1);
		current_path[s] = cord[s];
		
		cout << s << " to " << v << '\n';
		dfs(s, v, s+1);
		
		for (int i = s; i < v; i++) {
			if (cord[i].first < 0 && paths[i].size() == 1) {
				added++;
				set<pair<int, int> >::iterator iter = paths[i].begin();
				cout << "++Add: " << i << '\n';
				fill(iter->first, iter->second, i);
			}
		}
		// print();
		cout << "[Add]: " << added << '\n';
		if (added == 0) {
			map<pair<int, int>, set<int> > avail;
			for (int i = s; i < v; i++) {
				for (set<pair<int, int> >::iterator j = paths[i].begin(); j != paths[i].end(); j++) {
					avail[*j].insert(i);
				}
			}
			for (map<pair<int, int>, set<int> >::iterator iter = avail.begin(); iter != avail.end(); iter++) {
				if (iter->second.size() == 1) {
					cout << "......" << '[' << iter->first.first << ',' << iter->first.second << ']' << ' ' << *iter->second.begin() << '\n';
				}
			}
			/*
			for (int i = s; i < v; i++) {
				cout << "cord[" << i << "] = " << cord[i].first << ',' << cord[i].second << '\t';
				cout << paths[i].size() << '\n';
				if (cord[i].first < 0 && paths[i].size() > 0) {
					added++;
					set<pair<int, int> >::iterator iter = paths[i].begin();
					cout << "++Add: " << i << '\n';
					fill(iter->first, iter->second, i);
				}
			}
			 */
		}
		return added;
	}
	
	void solve() {
		while (true) {
			print();
			if (iterate() > 0) {
				continue;
			}
			if (iterate_deep() > 0) {
				continue;
			}
			return;
		}
	}
};

int main()
{
	board b;
	b.init(8);
	
	b.fill(0, 0, 59);
	
	b.fill(0, 4, 34);
	b.fill(0, 5, 36);
	b.fill(0, 7, 16);
	
	b.fill(1, 0, 61);
	b.fill(1, 1, 3);
	b.fill(1, 2, 39);
	b.fill(1, 3, 1);
	
	b.fill(1, 4, 62);
	b.fill(1, 6, 28);
	b.fill(1, 7, 2);
	
	b.fill(2, 0, 57);
	b.fill(2, 2, 41);
	b.fill(2, 3, 55);
		
	b.fill(3, 0, 31);
	b.fill(3, 1, 45);
	
	b.fill(3, 4, 44);
	b.fill(3, 5, 52);
	b.fill(3, 6, 24);
	b.fill(3, 7, 20);
	
	b.fill(4, 0, 60);
	b.fill(4, 1, 4);
	b.fill(4, 2, 40);
	
	b.fill(5, 2, 38);
	
	b.fill(5, 4, 33);
	b.fill(5, 5, 11);
	b.fill(5, 6, 25);
	b.fill(5, 7, 17);
	
	b.fill(6, 0, 58);
	b.fill(6, 1, 46);
	b.fill(6, 3, 22);
	
	b.fill(6, 4, 7);
	
	b.fill(7, 1, 14);
	b.fill(7, 3, 64);
	
	b.fill(7, 4, 63);
	b.fill(7, 6, 29);

	cout << "#Board# b:\n";
	b.print();
	cout << "\n\n";
	b.solve();
	cout << "#Solution# b:\n";
	b.print();
	cout << "\n\n";
}

