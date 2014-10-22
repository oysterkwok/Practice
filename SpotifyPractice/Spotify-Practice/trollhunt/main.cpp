//
//  main.cpp
//  trollhunt
//
//  Created by Haoquan Guo on 2/18/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{
    int b, k, g;
    cin >> b >> k >> g;
    int t = k / g;
    int ans = (b - 1) / t;
    if ((b - 1) % t > 0) {
        ans ++;
    }
    cout << ans << "\n";
    return 0;
}

