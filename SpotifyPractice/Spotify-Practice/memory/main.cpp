//
//  main.cpp
//  memory
//
//  Created by Haoquan Guo on 2/18/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

map<string, int> table;

string bian(string str1);

int loop(string str1);

int loop2(string str1);

int loop2(string str1) {
    int tail = (int) str1.length() - 1;
    int head = 0;
    while (str1[head] != '1' && head <= tail) {
        head ++;
    }
    while (str1[tail] != '0' && tail >= head) {
        tail --;
    }
    if (head > tail) {
        return 1;
    }
    string str2 = str1.substr(head, tail - head + 1);
    int ans1 = loop2(str2.substr(1));
}

string bian(string str1) {
    string str2;
    int head = 0;
    int tail = (int) str1.size();
    while (tail > 0 && str1[tail - 1] == '1') {
        tail --;
    }
    if (tail == 0) {
        cout << "!";
    }
    while (head < tail && str1[head] == '0') {
        head ++;
    }
    while (head < tail) {
        str2.append("0");
        while (head < tail && str1[head] == '1') {
            head ++;
            str2.append("2");
        }
        head ++;
        while (head < tail && str1[head] == '0') {
            head ++;
            str2.append("0");
        }
    }
    return str2;
}

int loop(string str1) {
    int tail = (int) str1.length() - 1;
    int head = 0;
    while (str1[head] != '1' && head <= tail) {
        head ++;
    }
    while (str1[tail] != '0' && tail >= head) {
        tail --;
    }
    if (head > tail) {
        return 1;
    }
    string str2 = str1.substr(head, tail - head + 1);
    map<string, int>::iterator ti = table.find(str2);
    if (ti == table.end()) {
        string str3 = str2.substr(0, str2.length() - 1);
        int ans1 = loop(str3);
        int j = (int) str3.length() - 1;
        while (str3[j] == '0') {
            str3[j] = '1';
            j --;
        }
        str3[j] = '0';
        int ans2 = loop(str3);
        int ans = (ans1 + ans2) % 1000000009;
        if (table.size() < 10000) {
            table[str2] = ans;
        }
        return ans;
    } else{
        return ti->second;
    }
}

int main (int argc, const char * argv[])
{
    string str;
    cin >> str;
    table["0"] = 1;
    cout << loop(str) << "\n";
//    cout << bian(str) << "\n";
    return 0;
}

