#include <iostream>
#include <vector>
#include <set>

using namespace std;

class shot {
public:
	int n;
	int grid[8][8];
	vector<pair<int, int> > flooded_area;
	vector<pair<int, int> > bounded_area;
	set<int> next_color;
	
	void readit(int _n) {
		n = _n;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cin >> grid[i][j];
			}
		}
		flooded_area.clear();
		bounded_area.clear();
		flooded_area.push_back(pair<int, int>(0, 0));
		update_flood();
	}
	
	void update_flood() {
		next_color.clear();
		int color = grid[0][0];
		grid[0][0] = 9;
		int head = 0;
		while (head < flooded_area.size()) {
			int x = flooded_area[head].first;
			int y = flooded_area[head].second;
			
			if (grid[x][y] == 10) {
				head ++;
				continue;
			}
			
			bool is_bound = false;
			if (x+1 < n) {
				if (grid[x+1][y] == color) {
					grid[x+1][y] = 9;
					flooded_area.push_back(pair<int, int>(x+1, y));
				}
				if (grid[x+1][y] < 9) {
					is_bound = true;
					next_color.insert(grid[x+1][y]);
				}
			}
			if (x-1 >= 0) {
				if (grid[x-1][y] == color) {
					grid[x-1][y] = 9;
					flooded_area.push_back(pair<int, int>(x-1, y));
				}
				if (grid[x-1][y] < 9) {
					is_bound = true;
					next_color.insert(grid[x-1][y]);
				}
			}
			if (y+1 < n) {
				if (grid[x][y+1] == color) {
					grid[x][y+1] = 9;
					flooded_area.push_back(pair<int, int>(x, y+1));
				}
				if (grid[x][y+1] < 9) {
					is_bound = true;
					next_color.insert(grid[x][y+1]);
				}
			}
			if (y-1 >= 0) {
				if (grid[x][y-1] == color) {
					grid[x][y-1] = 9;
					flooded_area.push_back(pair<int, int>(x, y-1));
				}
				if (grid[x][y-1] < 9) {
					is_bound = true;
					next_color.insert(grid[x][y-1]);
				}
			}
			if (!is_bound) {
				grid[x][y] = 10;
			}
			else {
				bounded_area.push_back(flooded_area[head]);
			}
			head ++;
		}
	}
	
	shot changeto(int k) {
		shot result;
		result.n = n;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				result.grid[i][j] = grid[i][j];
			}
		}
		result.grid[0][0] = k;
		result.flooded_area.clear();
		for (int i = 0; i < flooded_area.size(); i ++) {
			result.flooded_area.push_back(flooded_area[i]);
		}
		result.update_flood();
		return result;
	}
	
	bool is_done() {
		if (next_color.size() == 0) {
			return true;
		}
		return false;
	}
	
	bool is_sub_to(shot another) {
		if (flooded_area.size() > another.flooded_area.size()) {
			return false;
		}
		for (int i = 0; i < bounded_area.size(); i ++) {
			int x = bounded_area[i].first;
			int y = bounded_area[i].second;
			if (grid[x][y] == 9) {
				if (another.grid[x][y] < 9) {
					return false;
				}
			}
		}		
		return true;
	}
};

int main() {
	int nsize;
	cin >> nsize;
	while (nsize > 0) {
		shot init;
		init.readit(nsize);
		int move = 0;
		if (init.is_done()) {
			cout << move << '\n';
		}
		else {
			vector<shot> shot_bin;
			shot_bin.push_back(init);
			bool found_best = false;
			int head = 0;
			int tail = 1;
			double sot1, sot2, sot3;
			
			bool touch[8][8];
			for (int i = 0; i < nsize; i ++) {
				for (int j = 0; j < nsize; j ++) {
					touch[i][j] = false;
				}
			}
			int n_touch = 0;
			
			while (!found_best) {

				move ++;
				for (int i = head; i < tail; i ++) {
					if (found_best) {
						break;
					}
					for (int k = 0; k < 6; k ++) {
						if (shot_bin[i].next_color.find(k) == shot_bin[i].next_color.end()) {
							continue;
						}
						shot new_shot = shot_bin[i].changeto(k);
						if (new_shot.is_done()) {
							found_best = true;
							break;
						}
						
						bool is_sub = false;
						if (new_shot.next_color.size() < shot_bin[i].next_color.size()) {
							is_sub = true;
						}
//						else if (n_touch < nsize * nsize - nsize * 2) {
//							for (int j = 0; j < new_shot.bounded_area.size(); j ++) {
//								int x = new_shot.bounded_area[j].first;
//								int y = new_shot.bounded_area[j].second;
//								if (!touch[x][y] && new_shot.grid[x][y] >= 9) {
//									is_sub = true;
//									touch[x][y] = true;
//									n_touch ++;
//								}
//							}
//						}
						else {
							is_sub = true;
							for (int j = 0; j < shot_bin.size(); j ++) {
								if (new_shot.is_sub_to(shot_bin[shot_bin.size() - j - 1])) {
									is_sub = false;
									break;
								}
							}
						}
						if (is_sub) {
							shot_bin.push_back(new_shot);
						}
					}
				}
				head = tail;
				tail = (int) shot_bin.size();
			}
			cout << move << '\n';
		}
		cin >> nsize;
	}
}