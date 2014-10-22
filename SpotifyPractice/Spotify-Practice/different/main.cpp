//
//  main.cpp
//  different
//
//  Created by Haoquan Guo on 2/15/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{
    long long x, y;
    cin >> x;
    while (!cin.eof()) {
        cin >> y;
        if (x >= y) {
            cout << x - y << "\n";
        }
        else {
            cout << y - x << "\n";
        }
        cin >> x;
    }
    return 0;
}

