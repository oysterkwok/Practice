//
//  main.cpp
//  bilateral
//
//  Created by Haoquan Guo on 2/14/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;

multimap<int, int> edges, redges;
set<int> lnodes, rnodes, checked;
map<int, int> path, rpath;

bool findpath(int x);
void findbadpath(int x);

bool findpath(int x) {
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ranger;
    ranger = edges.equal_range(x);
    for (multimap<int, int>::iterator i = ranger.first; i != ranger.second; i ++) {
        int y = i->second;
        if (checked.find(y) == checked.end()) {
            checked.insert(y);
            map<int, int>::iterator z = rpath.find(y);
            if (z == rpath.end() || findpath(z->second)) {
                path[x] = y;
                rpath[y] = x;
                return true;
            }
        }
    }
    return false;
}

void findbadpath(int x) {
    checked.insert(x);
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ranger;
    ranger = edges.equal_range(x);
    map<int, int>::iterator j = path.find(x);
    for (multimap<int, int>::iterator i = ranger.first; i != ranger.second; i ++) {
        if (j == path.end() || j->second != i->second) {
            if (checked.find(i->second) == checked.end()) {
                checked.insert(i->second);
                map<int, int>::iterator k = rpath.find(i->second);
                if (k != rpath.end()) {
                    findbadpath(k->second);
                }
            }
        }
    }
}

int main (int argc, const char * argv[])
{
    int n_edge;
    cin >> n_edge;
    for (int i = 0; i < n_edge; i ++) {
        int x, y;
        cin >> x >> y;
        edges.insert(pair<int, int> (x, y));
        redges.insert(pair<int, int> (y, x));
        lnodes.insert(x);
        rnodes.insert(y);
    }
    
    int n_result = 0;
    for (set<int>::iterator i = lnodes.begin(); i != lnodes.end(); i ++) {
        checked.clear();
        if (findpath(*i)) {
            n_result ++;
        }
    }
        
    checked.clear();
    for (set<int>::iterator i = lnodes.begin(); i != lnodes.end(); i ++) {
        if (path.find(*i) == path.end()) {
            findbadpath(*i);
        }
    }
    
    set<int> result;
    result.clear();

    for (set<int>::iterator i = lnodes.begin(); i != lnodes.end(); i ++) {
        if (checked.find(*i) == checked.end()) {
            result.insert(*i);
        }
    }
    for (set<int>::iterator i = rnodes.begin(); i != rnodes.end(); i ++) {
        if (checked.find(*i) != checked.end()) {
            result.insert(*i);
        }
    }
    
    cout << result.size() << "\n";
    for (set<int>::iterator i = result.begin(); i != result.end(); i ++) {
        cout << *i << "\n";
    }
    return 0;
}

