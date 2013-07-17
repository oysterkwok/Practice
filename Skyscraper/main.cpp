//
//  main.cpp
//  Skyscraper
//
//  Created by Haoquan Guo on 7/16/13.
//  Copyright 2013 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class board {
public:	
	int n;
	vector<vector<int> > grid;
	vector<vector<vector<bool> > > avail;	
	void init() {
		cout << "Size : ";
		cin >> n;
		grid.resize(n+2);
		for (int i = 0; i < n+2; i ++) {
			grid[i].resize(n+2, 0);
		}
		avail.resize(n+2);
		for (int i = 0; i < n+2; i ++) {
			avail[i].resize(n+2);
			for (int j = 0; j < n+2; j ++) {
				avail[i][j].resize(n+2, true);
			}
		}
		cout << "Edges: ";
		for (int i = 1; i <= n; i ++) {
			cin >> grid[0][i];
		}
		for (int i = 1; i <= n; i ++) {
			cin >> grid[i][n+1];
		}
		for (int i = 1; i <= n; i ++) {
			cin >> grid[n+1][n-i+1];
		}
		for (int i = 1; i <= n; i ++) {
			cin >> grid[n-i+1][0];
		}
		print();
	}
	
	void print() {
		for (int i = 0; i < n+2; i ++) {
			for (int j = 0; j < n+2; j ++) {
				cout << grid[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	
	bool fill(int x, int y, int z) {
		if (grid[x][y] > 0) {
			return false;
		}
		grid[x][y] = z;
		for (int i = 1; i <= n; i ++) {
			avail[x][i][z] = false;
			avail[i][y][z] = false;
			avail[x][y][i] = false;
		}
		avail[x][y][z] = true;
		return true;
	}
	
	bool unavail(int x, int y, int z) {
		if (avail[x][y][z]) {
			avail[x][y][z] = false;
			return true;
		}
		else {
			return false;
		}		
	}
	
	bool rule00() {
		// pick the only choice
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (grid[i][j] == 0) {
					int count = 0;
					int ans = 0;
					for (int k = 1; k <= n; k ++) {
						if (avail[i][j][k]) {
							count ++;
							ans = k;
						}
					}
					if (count == 1) {
						updated |= fill(i, j, ans);
					}
				}
			}
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				int count = 0;
				int ans = 0;
				for (int k = 1; k <= n; k ++) {
					if (avail[i][k][j]) {
						count ++;
						ans = k;
					}
				}
				if (count == 1) {
					updated |= fill(i, ans, j);
				}
				count = 0;
				ans = 0;
				for (int k = 1; k <= n; k ++) {
					if (avail[k][i][j]) {
						count ++;
						ans = k;
					}
				}
				if (count == 1) {
					updated |= fill(ans, i, j);
				}
			}
		}
		return updated;
	}
	
	bool rule01() {
		// 1 on edge
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			if (grid[0][i] == 1 && grid[1][i] == 0) {
				fill(1, i, n);
				updated = true;
			}
			if (grid[n+1][i] == 1 && grid[n][i] == 0) {
				fill(n, i, n);
				updated = true;
			}
			if (grid[i][0] == 1 && grid[i][1] == 0) {
				fill(i, 1, n);
				updated = true;
			}
			if (grid[i][n+1] == 1 && grid[i][n] == 0) {
				fill(i, n, n);
				updated = true;
			}
		}
		return updated;
	}
	
	bool rule02() {
		// all accdening to peak, i.e 4: 0 0 0 5 2 -> 4: 1 3 4 5 2
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			if (grid[0][i] > 1 && grid[grid[0][i]][i] == n) {
				bool flag = true;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				appeared[0] = true;
				appeared[n] = true;
				for (int j = grid[0][i]+1; j <= n; j ++) {
					if (grid[j][i] == 0) {
						flag = false;
						break;
					}
					else {
						appeared[grid[j][i]] = true;
					}
				}
				if (flag) {
					int k = 0;
					for (int j = 1; j < grid[0][i]; j ++) {
						while (appeared[k]) {
							k ++;
						}
						updated |= fill(j, i, k);
						appeared[k] = true;
					}
				}
			}
			
			if (grid[n+1][i] > 1 && grid[n+1-grid[n+1][i]][i] == n) {
				bool flag = true;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				appeared[0] = true;
				appeared[n] = true;
				for (int j = n-grid[n+1][i]; j >= 1; j --) {
					if (grid[j][i] == 0) {
						flag = false;
						break;
					}
					else {
						appeared[grid[j][i]] = true;
					}
				}
				if (flag) {
					int k = 0;
					for (int j = n; j > n+1-grid[n+1][i]; j --) {
						while (appeared[k]) {
							k ++;
						}
						updated |= fill(j, i, k);
						appeared[k] = true;
					}
				}
			}

			if (grid[i][0] > 1 && grid[i][grid[i][0]] == n) {
				bool flag = true;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				appeared[0] = true;
				appeared[n] = true;
				for (int j = grid[i][0]+1; j <= n; j ++) {
					if (grid[i][j] == 0) {
						flag = false;
						break;
					}
					else {
						appeared[grid[i][j]] = true;
					}
				}
				if (flag) {
					int k = 0;
					for (int j = 1; j < grid[i][0]; j ++) {
						while (appeared[k]) {
							k ++;
						}
						updated |= fill(i, j, k);
						appeared[k] = true;
					}
				}
			}

			if (grid[i][n+1] > 1 && grid[i][n+1-grid[i][n+1]] == n) {
				bool flag = true;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				appeared[0] = true;
				appeared[n] = true;
				for (int j = n-grid[i][n+1]; j >= 1; j --) {
					if (grid[i][j] == 0) {
						flag = false;
						break;
					}
					else {
						appeared[grid[i][j]] = true;
					}
				}
				if (flag) {
					int k = 0;
					for (int j = n; j > n+1-grid[i][n+1]; j --) {
						while (appeared[k]) {
							k ++;
						}
						updated |= fill(i, j, k);
						appeared[k] = true;
					}
				}
			}
		}
		return updated;
	}
	
	bool rule03() {
		// second peak to peak, i.e 2: 0 0 0 5 4 -> 4: 3 0 0 5 4
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			if (grid[0][i] == 2 && grid[1][i] == 0) {
				bool flag = false;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				for (int j = n; j >= 2; j --) {
					if (grid[j][i] == 0) {
						break;
					}
					else {
						appeared[grid[j][i]] = true;
					}
					if (grid[j][i] == n) {
						flag = true;
						break;
					}
				}
				if (flag) {
					int k = n;
					while (appeared[k]) {
						k --;
					}
					updated |= fill(1, i, k);
				}
			}
			
			if (grid[n+1][i] == 2 && grid[n][i] == 0) {
				bool flag = false;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				for (int j = 1; j <= n-1; j ++) {
					if (grid[j][i] == 0) {
						break;
					}
					else {
						appeared[grid[j][i]] = true;
					}
					if (grid[j][i] == n) {
						flag = true;
						break;
					}
				}
				if (flag) {
					int k = n;
					while (appeared[k]) {
						k --;
					}
					updated |= fill(n, i, k);
				}
			}
			
			if (grid[i][0] == 2 && grid[i][1] == 0) {
				bool flag = false;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				for (int j = n; j >= 2; j --) {
					if (grid[i][j] == 0) {
						break;
					}
					else {
						appeared[grid[i][j]] = true;
					}
					if (grid[i][j] == n) {
						flag = true;
						break;
					}
				}
				if (flag) {
					int k = n;
					while (appeared[k]) {
						k --;
					}
					updated |= fill(i, 1, k);
				}
			}
			
			if (grid[i][n+1] == 2 && grid[i][n] == 0) {
				bool flag = false;
				vector<bool> appeared;
				appeared.resize(n+2, false);
				for (int j = 1; j <= n-1; j ++) {
					if (grid[i][j] == 0) {
						break;
					}
					else {
						appeared[grid[i][j]] = true;
					}
					if (grid[i][j] == n) {
						flag = true;
						break;
					}
				}
				if (flag) {
					int k = n;
					while (appeared[k]) {
						k --;
					}
					updated |= fill(i, n, k);
				}
			}
		}
		return updated;
	}

	bool rule04() {
		// sum of edge == n+1, i.e 3| 0 0 0 0 |2 -> 3| 0 0 4 0 |2
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			if (grid[0][i] + grid[n+1][i] == n+1 && grid[grid[0][i]][i] == 0) {
				updated |= fill(grid[0][i], i, n);
			}
			if (grid[i][0] + grid[i][n+1] == n+1 && grid[i][grid[i][0]] == 0) {
				updated |= fill(i, grid[i][0], n);
			}
		}
		return updated;
	}
	
	bool rule05() {
		// big num not at large edge's side, i.e 3| 0 0 0 0 |0 -> avail[i][1][4] = false; avail[i][2][4] = false; avail[i][1][3] = false;
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				for (int k = 1; k <= n; k ++) {
					if (grid[0][j] > 0 && k + grid[0][j] - i > n) {
						updated |= unavail(i, j, k);
					}
					if (grid[n+1][j] > 0 && k + grid[n+1][j] - (n+1-i) > n) {
						updated |= unavail(i, j, k);
					}
					if (grid[i][0] > 0 && k + grid[i][0] - j > n) {
						updated |= unavail(i, j, k);
					}
					if (grid[i][n+1] > 0 && k + grid[i][n+1] - (n+1-j) > n) {
						updated |= unavail(i, j, k);
					}
				}
			}
		}
		cout << updated << '\n';
		return updated;
	}
	
	bool rule06() {
		// try to fill the remaining biggest digit in the row/column, i.e 3| 1 0 0 5 4 |0 -> 2| 1 3 0 5 4 |0
		bool updated = false;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (grid[i][j] == n) {
					cout << "## " << i << " " << j << '\n';
					if (grid[0][j] > 0) {
						bool flag = true;
						for (int k = i; k <= n; k ++) {
							if (grid[k][j] == 0) {
								flag = false;
								break;
							}
						}
						vector<bool> appeared;
						appeared.resize(n+2, false);
						for (int k = 1; k <= n; k ++) {
							appeared[grid[k][j]] = true;
						}
						if (flag) {
							int q = 0;
							for (int p = 1; p <= n; p ++) {
								if (grid[p][j] == 0) {
									q = p;
									break;
								}
							}
							if (q == 0) {
								flag = false;
							}
							int k = n;
							while (appeared[k]) {
								k --;
							}
							int count = 0;
							int r = 0;
							for (int p = 1; p < q; p ++) {
								if (grid[p][j] > r) {
									count ++;
									r = grid[p][j];
								}
							}
							if (r > k) {
								flag = false;
							}
							else {
								r = k;
								count ++;
							}
							for (int p = q+1; p <= n; p ++) {
								if (grid[p][j] > r) {
									count ++;
									r = grid[p][j];
								}
							}
							cout << "count=" << count << '\n';
							if (flag && count == grid[0][j]) {
								updated |= fill(q, j, k);
							}
						}						
					}
					if (grid[n+1][j] > 0) {
						bool flag = true;
						for (int k = i; k >= 1; k --) {
							if (grid[k][j] == 0) {
								flag = false;
								break;
							}
						}
						vector<bool> appeared;
						appeared.resize(n+2, false);
						for (int k = 1; k <= n; k ++) {
							appeared[grid[k][j]] = true;
						}
						if (flag) {
							int q = 0;
							for (int p = 1; p <= n; p ++) {
								if (grid[n+1-p][j] == 0) {
									q = p;
									break;
								}
							}
							if (q == 0) {
								flag = false;
							}
							int k = n;
							while (appeared[k]) {
								k --;
							}
							cout << ">> " << i << ", " << j << ": " << q << ", " << k << '\n';
							int count = 0;
							int r = 0;
							for (int p = 1; p < q; p ++) {
								if (grid[n+1-p][j] > r) {
									count ++;
									r = grid[n+1-p][j];
								}
							}
							if (r > k) {
								flag = false;
							}
							else {
								r = k;
								count ++;
							}
							for (int p = q+1; p <= n; p ++) {
								if (grid[n+1-p][j] > r) {
									count ++;
									r = grid[n+1-p][j];
								}
							}
							cout << count << '\n';
							if (flag && count == grid[n+1][j]) {
								updated |= fill(n+1-q, j, k);
							}
						}						
					}
					if (grid[i][0] > 0) {
						bool flag = true;
						for (int k = i; k <= n; k ++) {
							if (grid[i][k] == 0) {
								flag = false;
								break;
							}
						}
						vector<bool> appeared;
						appeared.resize(n+2, false);
						for (int k = 1; k <= n; k ++) {
							appeared[grid[i][k]] = true;
						}
						if (flag) {
							int q = 0;
							for (int p = 1; p <= n; p ++) {
								if (grid[i][p] == 0) {
									q = p;
									break;
								}
							}
							if (q == 0) {
								flag = false;
							}
							int k = n;
							while (appeared[k]) {
								k --;
							}
							int count = 0;
							int r = 0;
							for (int p = 1; p < q; p ++) {
								if (grid[i][p] > r) {
									count ++;
									r = grid[i][p];
								}
							}
							if (r > k) {
								flag = false;
							}
							else {
								r = k;
								count ++;
							}
							for (int p = q+1; p <= n; p ++) {
								if (grid[i][p] > r) {
									count ++;
									r = grid[i][p];
								}
							}
							if (flag && count == grid[0][j]) {
								updated |= fill(i, q, k);
							}
						}						
					}
					if (grid[i][n+1] > 0) {
						bool flag = true;
						for (int k = i; k >= 1; k --) {
							if (grid[i][k] == 0) {
								flag = false;
								break;
							}
						}
						vector<bool> appeared;
						appeared.resize(n+2, false);
						for (int k = 1; k <= n; k ++) {
							appeared[grid[i][k]] = true;
						}
						if (flag) {
							int q = 0;
							for (int p = 1; p <= n; p ++) {
								if (grid[i][n+1-p] == 0) {
									q = p;
									break;
								}
							}
							if (q == 0) {
								flag = false;
							}
							int k = n;
							while (appeared[k]) {
								k --;
							}
							int count = 0;
							int r = 0;
							for (int p = 1; p < q; p ++) {
								if (grid[i][n+1-p] > r) {
									count ++;
									r = grid[i][n+1-p];
								}
							}
							if (r > k) {
								flag = false;
							}
							else {
								r = k;
								count ++;
							}
							for (int p = q+1; p <= n; p ++) {
								if (grid[i][n+1-p] > r) {
									count ++;
									r = grid[i][n+1-p];
								}
							}
							if (flag && count == grid[i][n+1]) {
								updated |= fill(i, n+1-q, k);
							}
						}						
					}
				}
			}
		}
		return updated;
	}
	
	void solve() {
		int iter = 0;
		bool updated = true;
		while (updated) {
			cout << "iter: " << iter++ << '\n';
			updated = false;
			updated |= rule00();
			updated |= rule01();
			updated |= rule02();
			//			updated |= rule03();
			updated |= rule04();
			updated |= rule05();
			updated |= rule06();
			print();
		}
	}
};

int main () {
	board b;
	b.init();
	b.solve();
    return 0;
}

