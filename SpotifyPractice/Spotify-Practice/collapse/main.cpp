//
//  main.cpp
//  collapse
//
//  Created by Haoquan Guo on 2/18/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    bool * sur = new bool[n];
    for (int i = 1; i < n; i ++) {
        sur[i] = true;
    }
    sur[0] = false;
    set<int> newsup;
    vector<map<int, int> > big;
    map<int, set<int> > effect;
    
    for (int i = 1; i < n; i ++) {
        newsup.insert(i);
    }
    
    int * need = new int[n];
    for (int i = 0; i < n; i ++) {
        int ti, ki;
        cin >> ti >> ki;
        need[i] = ti;
        map<int, int> _big;
        for (int j = 0; j < ki; j ++) {
            int sij, vij;
            cin >> sij >> vij;
            _big[sij-1] = vij;
            
            set<int> eff;
            map<int, set<int> >::iterator iter = effect.find(sij-1);
            if (iter != effect.end()) {
                eff = iter->second;
            }
            eff.insert(i);
            effect[sij-1] = eff;
        }
        big.push_back(_big);
    }
    
    bool change = true;
    while (change) {
        change = false;
        set<int> sup = newsup;
        newsup.clear();
        for (set<int>::iterator iters = sup.begin(); iters != sup.end(); iters ++) {
            int i = * iters;
            if (sur[i]) {
                int feed = 0;
                map<int, int> _big = big[i];
                for (map<int, int>::iterator iter=_big.begin(); iter != _big.end(); iter ++) {
                    if (sur[iter->first] && feed < need[i]) {
                        feed += iter->second;
                    }
                }
                if (feed < need[i]) {
                    sur[i] = false;
                    change = true;
                    map<int, set<int> >::iterator iterm = effect.find(i);
                    if (iterm != effect.end()) {
                        for (set<int>::iterator ii = iterm->second.begin(); ii != iterm->second.end(); ii ++) {
                            if (sur[*ii]) {
                                newsup.insert(*ii);
                            }
                        }
                    }
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        if (sur[i]) {
            sum ++;
        }
    }
    cout << sum << "\n";
    return 0;
}

