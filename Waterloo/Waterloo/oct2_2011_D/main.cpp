//
//  main.cpp
//  oct2_2011_D
//
//  Created by Haoquan Guo on 3/8/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main (int argc, const char * argv[])
{
    map<char, int> convertmap;
    convertmap['a'] = 2;
    convertmap['b'] = 2;
    convertmap['c'] = 2;
    convertmap['d'] = 3;
    convertmap['e'] = 3;
    convertmap['f'] = 3;
    convertmap['g'] = 4;
    convertmap['h'] = 4;
    convertmap['i'] = 4;
    convertmap['j'] = 5;
    convertmap['k'] = 5;
    convertmap['l'] = 5;
    convertmap['m'] = 6;
    convertmap['n'] = 6;
    convertmap['o'] = 6;
    convertmap['p'] = 7;
    convertmap['q'] = 7;
    convertmap['r'] = 7;
    convertmap['s'] = 7;
    convertmap['t'] = 8;
    convertmap['u'] = 8;
    convertmap['v'] = 8;
    convertmap['w'] = 9;
    convertmap['x'] = 9;
    convertmap['y'] = 9;
    convertmap['z'] = 9;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string str;
        cin >> str;
        bool ok = true;
        for (int j = 0; j < str.length() / 2; j ++) {
            char c1 = str[j];
            char c2 = str[str.length() - j - 1];
            if (c1 >= 'A' && c1 <= 'Z') {
                c1 += 'a' - 'A';
            }
            if (c2 >= 'A' && c2 <= 'Z') {
                c2 += 'a' - 'A';
            }
            if (convertmap.find(c1)->second != convertmap.find(c2)->second) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

