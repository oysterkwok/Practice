//
//  main.cpp
//  oct2_2011_e
//
//  Created by Haoquan Guo on 3/8/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int c, t, l;
        cin >> c >> t >> l;
        map<int, int> cost;
        cost[0] = 0;
        for (int j = 0; j < c; j ++) {
            map<int, int> next_cost;
            for (int k = 0; k < t; k ++) {
                int loc, eng;
                cin >> loc >> eng;
                int min_next_eng = -1;
                for (map<int, int>::iterator mi = cost.begin(); mi != cost.end(); mi ++) {
                    int next_eng = mi->second + abs(mi->first - loc);
                    if (min_next_eng == -1 || min_next_eng > next_eng) {
                        min_next_eng = next_eng;
                    }
                }
                next_cost[loc] = min_next_eng + eng;
            }
            cost = next_cost;
        }
        int min_next_eng = -1;
        for (map<int, int>::iterator mi = cost.begin(); mi != cost.end(); mi ++) {
            int next_eng = mi->second + abs(mi->first - l);
            if (min_next_eng == -1 || min_next_eng > next_eng) {
                min_next_eng = next_eng;
            }
        }
        cout << min_next_eng << "\n";
    }
    return 0;
}

