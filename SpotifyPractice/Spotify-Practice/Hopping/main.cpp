//
//  main.cpp
//  Hopping
//
//  Created by Haoquan Guo on 2/21/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include "math.h"

using namespace std;


int main (int argc, const char * argv[])
{
    int n, t = 0;
    cin >> n;
    while (n > 0) {
        t ++;
        vector<int *> info;
        info.clear();
        for (int i = 0; i < n; i ++) {
            int * cur_info = new int[3];
            cin >> cur_info[0] >> cur_info[1] >> cur_info[2];
            info.push_back(cur_info);
        }
        map<int, int> linked;
        linked.clear();
        linked[0] = 0;
        for (int l = 1; l < n; l ++) {
            int x = -1, y = -1;
            for (map<int, int>::iterator i = linked.begin(); i != linked.end(); i ++) {
                for (int j = 1; j < n; j ++) {
                    if (i->first != j && linked.find(j) == linked.end()) {
                        int dist = pow(info[i->first][0] - info[j][0], 2) + pow(info[i->first][1] - info[j][1], 2);
                        if (x == -1 || y == -1) {
                            x = i->first;
                            y = j;
                            continue;
                        }
                        else {
                            int dist_g = pow(info[x][0] - info[y][0], 2) + pow(info[x][1] - info[y][1], 2);
                            if (dist_g == dist && info[j][2] > info[y][2]) {
                                x = i->first;
                                y = j;
                                continue;
                            }
                            if (dist_g > dist) {
                                x = i->first;
                                y = j;
                                continue;
                            }
                        }
                    }
                }
            }
            int dist_g = pow(info[x][0] - info[y][0], 2) + pow(info[x][1] - info[y][1], 2);
            map<int, int>::iterator z = linked.find(x);
            if (z->second > dist_g) {
                linked[y] = z->second;
            }
            else {
                linked[y] = dist_g;
            }
        }
        double score = 0;
        int inh_sum = 0;
        for (map<int, int>::iterator iter = linked.begin(); iter != linked.end(); iter ++) {
            score += sqrt(1.0 * iter->second) * info[iter->first][2];
        }
        for (int i = 0; i < n; i ++) {
            inh_sum += info[i][2];
        }
        score /= inh_sum;
        cout.precision(2);
        cout << "Island Group: " << t << " Average " << fixed << score << "\n\n";
        cin >> n;
    }
    return 0;
}

