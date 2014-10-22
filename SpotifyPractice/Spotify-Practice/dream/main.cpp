//
//  main.cpp
//  dream
//
//  Created by Haoquan Guo on 2/15/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main (int argc, const char * argv[])
{
    map<string, int> strmap;
    vector<string> strstack;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        string opt;
        cin >> opt;
        if (opt.at(0) == 'E' || opt.at(0) == 'e') {
            string str;
            cin >> str;
            strmap[str] = (int) strstack.size();
            strstack.push_back(str);
        }
        if (opt.at(0) == 'D' || opt.at(0) == 'd') {
            int dream;
            cin >> dream;
            for (int j = 0; j < dream; j ++) {
                strmap.erase(strstack.back());
                strstack.pop_back();
            }
        }
        if (opt.at(0) == 'S' || opt.at(0) == 's') {
            int scenario;
            int head = -1;
            int tail = n + 1;
            cin >> scenario;
            for (int j = 0; j < scenario; j ++) {
                string check;
                cin >> check;
                if (check.at(0) != '!') {
                    map<string, int>::iterator k = strmap.find(check);
                    if (k == strmap.end()) {
                        tail = -1;
                    }
                    else {
                        if (head < k->second) {
                            head = k->second;
                        }
                    }
                }
                else {
                    string check1 = check.substr(1);
                    map<string, int>::iterator k = strmap.find(check1);
                    if (k != strmap.end() && tail > k->second) {
                        tail = k->second;
                    }
                }
                //cout << check << "----- " << status << "\n";
            }
            if (tail == n + 1) {
                cout << "Yes\n";
                continue;
            }
            if (head >= tail) {
                cout << "Plot Error\n";
                continue;
            }
            cout << strstack.size() - tail << " Just A Dream\n";
        }
    }
    return 0;
}

