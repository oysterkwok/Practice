//
//  main.cpp
//  catvsdog
//  trying machine learning method.. lol
//
//  Created by Haoquan Guo on 7/28/13.
//  Copyright 2013 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

class seed {
public:
	void random_gen(int n_cats, int n_dogs, int rand_seed) {
		srand(rand_seed);
		cats.resize(n_cats);
		dogs.resize(n_dogs);
		for (int i = 0; i < n_cats; i ++) {
			cats[i] = rand() % 2;
		}
		for (int i = 0; i < n_dogs; i ++) {
			dogs[i] = rand() % 2;
		}
	}
	
	int verify(vector<vector<string> > data) {
		int score = 0;
		for (int i = 0; i < data.size(); i ++) {
			int idx1 = atoi(data[i][0].substr(1).c_str()) - 1;
			int idx2 = atoi(data[i][1].substr(1).c_str()) - 1;
			if (data[i][0][0] == 'C') {
				if (cats[idx1] && !dogs[idx2]) {
					score ++;
				}
			}
			else {
				if (dogs[idx1] && !cats[idx2]) {
					score ++;
				}				
			}
		}
		return score;
	}
	
	void get_local_maximum(vector<vector<string> > data) {
		int max = verify(data);
		bool found = true;
		while (found) {
			found = false;
			for (int i = 0; i < cats.size(); i ++) {
				cats[i] = !cats[i];
				int now = verify(data);
				if (now > max) {
					max = now;
					found = true;
				}
				else {
					cats[i] = !cats[i];
				}
			}
			for (int i = 0; i < dogs.size(); i ++) {
				dogs[i] = !dogs[i];
				int now = verify(data);
				if (now > max) {
					max = now;
					found = true;
				}
				else {
					dogs[i] = !dogs[i];
				}
			}
		}
	}
	
	void print() {
		cout << "===================\n";
		cout << "cats:\n";
		for (int i = 0; i < cats.size(); i ++) {
			cout << cats[i] << ' ';
		}
		cout << '\n';
		cout << "dogs:\n";
		for (int i = 0; i < dogs.size(); i ++) {
			cout << dogs[i] << ' ';
		}
		cout << '\n';
		cout << "<<<<<<<<<<<<<<<<<<<<<\n";
	}
	
protected:
	vector<bool> cats, dogs;
};

void data_gen(int p);

void data_gen(int p) {
	srand(p);
	ofstream file("data.txt");
	int n = p;
	file << n << '\n';
	for (int i = 0; i < n; i ++) {
		int c, d, v;
		c = 3*p/4 + rand() % (p/2);
		d = 3*p/4 + rand() % (p/2);
		v = 15*p/4 + 5 * (rand() % (p/2));
		file << c << ' ' << d << ' ' << v << '\n';
		for (int j = 0; j < v; j ++) {
			if (rand() % 2) {
				int idx1 = rand() % c + 1;
				int idx2 = rand() % d + 1;
				file << 'C' << idx1 << ' ' << 'D' << idx2 << '\n';
			}
			else {
				int idx1 = rand() % c + 1;
				int idx2 = rand() % d + 1;
				file << 'D' << idx2 << ' ' << 'C' << idx1 << '\n';				
			}
		}
	}
}

int main () {
	int k = 30;
	int n, c, d, v;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> c >> d >> v;
		vector<vector<string> > votes;
		for (int j = 0; j < v; j ++) {
			string str1, str2;
			cin >> str1 >> str2;
			vector<string> vote;
			vote.push_back(str1);
			vote.push_back(str2);
			votes.push_back(vote);
		}
		
		//		k = v*v + 5*v + 9;
		int max = 0;
		seed ss;
		for (int j = 0; j < k; j ++) {
			ss.random_gen(c, d, j);
			ss.get_local_maximum(votes);
			int now = ss.verify(votes);
			if (now > max) {
				max = now;
			}
		}
		cout << max << '\n';
	}
    return 0;
}

