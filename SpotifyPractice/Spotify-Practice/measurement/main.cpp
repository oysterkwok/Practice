//
//  main.cpp
//  measurement
//
//  Created by Haoquan Guo on 2/15/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main (int argc, const char * argv[])
{
    int v;
    string u, str, mu;
    map<string, int> table;
    table["th"] = 1;
    table["in"] = 1000;
    table["ft"] = 1000*12;
    table["fo"] = 1000*12;
    table["fe"] = 1000*12;
    table["yd"] = 1000*12*3;
    table["ya"] = 1000*12*3;
    table["ch"] = 1000*12*3*22;
    table["fu"] = 1000*12*3*22*10;
    table["mi"] = 1000*12*3*22*10*8;
    table["le"] = 1000*12*3*22*10*8*3;
    
    cin >> v >> u >> str >> mu;
    int x = table.find(u.substr(0,2))->second;
    int y = table.find(mu.substr(0,2))->second;
    
    cout.precision(10);
    cout << 1.0 * v * x / y << "\n";
    return 0;
}

