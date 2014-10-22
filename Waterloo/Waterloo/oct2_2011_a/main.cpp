//
//  main.cpp
//  oct2_2011_a
//
//  Created by Haoquan Guo on 3/1/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    int * dist_s = new int[n+1];
    for (int i = 0; i <= n; i ++) {
        cin >> dist_s[i];
    }
    map<int, map<int, int> > edges;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        map<int, map<int, int> >::iterator ei = edges.find(x);
        map<int, int> new_edge;
        if (ei != edges.end()) {
            new_edge = ei->second;
        }
        new_edge[y] = z;
        edges[x] = new_edge;
        sum += 2*z;
    }
    int * dist_o = new int[n+1];
    int * queue = new int[n+1];
    int head = 0, tail = 1;
    queue[0] = 0;
    dist_o[0] = 0;
    while (head < tail) {
        int x = queue[head];
        map<int, map<int, int> >::iterator ei = edges.find(x);
        if (ei != edges.end()) {
            for (map<int, int>::iterator ej = ei->second.begin(); ej != ei->second.end(); ej ++) {
                int y = ej->first;
                int z = dist_o[x] + ej->second;
                dist_o[y] = z;
                queue[tail] = y;
                tail ++;
            }
        }
        head ++;
    }
    int min_dist = sum + dist_s[0];
    for (int i = 0; i <= n; i ++) {
        int dist = sum - dist_o[i] + dist_s[i];
        if (dist < min_dist) {
            min_dist = dist;
        }
    }
    cout << min_dist << "\n";
    return 0;
}

