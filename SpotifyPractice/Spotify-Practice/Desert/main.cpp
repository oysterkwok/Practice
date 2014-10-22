//
//  main.cpp
//  Desert
//
//  Created by Haoquan Guo on 2/20/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"
#define INT_MAX 2147483647

using namespace std;

vector<pair<int, int> > oasis;

int head, n, m, min_food;

vector<double *> states;
vector<int> position;

void bfs();

void bfs() {
    while (head < states.size() && head < 10000) {
        int i = position[head];
        double * cur_state = states[head];
        if (i == 0) {
            for (int j = 1; j < n; j ++) {
                double dist = sqrt(1.0 * pow((oasis[i].first - oasis[j].first), 2) + pow(oasis[i].second - oasis[j].second, 2));
                if (dist * 2 <= m) {
                    double * next_state = new double[n];
                    for (int k = 0; k < n; k ++) {
                        next_state[k] = cur_state[k];
                    }
                    next_state[i] += m - dist;
                    next_state[j] += m - dist * 2;
                    states.push_back(next_state);
                    position.push_back(j);
                }
            }
        }
        if (i == n-1) {
            if (min_food > cur_state[0] - cur_state[n-1]) {
                min_food = ceil(cur_state[0] - cur_state[n-1]);
            }
        }
        if (i > 0 && i < n-1) {
            int j = 0;
            double dist = sqrt(1.0 * pow((oasis[i].first - oasis[j].first), 2) + pow(oasis[i].second - oasis[j].second, 2));
            if (dist * 2 <= m && cur_state[i] >= dist) {
                double * next_state = new double[n];
                for (int k = 0; k < n; k ++) {
                    next_state[k] = cur_state[k];
                }
                next_state[i] -= dist;
                states.push_back(next_state);
                position.push_back(j);
            }
            for (int j = 1; j < n; j ++) {
                if (i != j) {
                    dist = sqrt(1.0 * pow((oasis[i].first - oasis[j].first), 2) + pow(oasis[i].second - oasis[j].second, 2));
                    if (dist * 2 <= m) {
                        if (cur_state[i] >= dist && cur_state[i] <= m - dist) {
                            double * next_state = new double[n];
                            for (int k = 0; k < n; k ++) {
                                next_state[k] = cur_state[k];
                            }
                            next_state[i] = 0;
                            next_state[j] += cur_state[i] - dist;
                            states.push_back(next_state);
                            position.push_back(j);
                        }
                        if (cur_state[i] > m - dist) {
                            double * next_state = new double[n];
                            for (int k = 0; k < n; k ++) {
                                next_state[k] = cur_state[k];
                            }
                            next_state[i] -= m - dist;
                            next_state[j] += m - 2 * dist;
                            states.push_back(next_state);
                            position.push_back(j);
                        }
                    }
                }
            }
        }
        head ++;
    }
}

int main (int argc, const char * argv[])
{
    cin >> n >> m;
    int t = 0;
    while (n > 0 || m > 0) {
        t ++;
        oasis.clear();
        states.clear();
        min_food = INT_MAX;
        for (int i = 0; i < n; i ++) {
            int x, y;
            cin >> x >> y;
            oasis.push_back(pair<int, int> (x, y));
        }
        head = 0;
        double * init_state = new double[n];
        for (int i = 0; i < n; i ++) {
            init_state[i] = 0;
        }
        states.push_back(init_state);
        position.push_back(0);
        bfs();
        cout << "Trial " << t << ": ";
        if (min_food == INT_MAX) {
            cout << "Impossible\n\n";
        }
        else {
            cout << min_food << " units of food\n\n";
        }
        cin >> n >> m;
    }
    return 0;
}

