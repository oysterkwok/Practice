//
//  main.cpp
//  stl-sample
//
//  Created by Haoquan Guo on 2/21/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
int main (int argc, const char * argv[])
{
    set<double> ds;
    ds.clear();
    ds.insert(1.2);
    ds.insert(5.2);
    ds.insert(6.2);
    ds.insert(8.2);
    ds.insert(10.2);
    ds.insert(1.2);
    ds.insert(1.3);
    ds.insert(4.2);
    
    ds.erase(8.2);
    
    set<double>::iterator it = ds.find(5.2);
    if (it != ds.end()) {
        cout << *it << "\n";
    }
    
    for (set<double>::iterator itt = ds.begin(); itt != ds.end(); itt ++) {
        cout << *itt << " ";
    }
    cout << "\n";
    
//    map<string, int> dict;
//    for (map<string, int>::iterator iter = dict.begin(); iter != dict.end(); iter ++) {
//        cout << iter->first << "\n";
//    }
//    
//    map<string, int>::iterator iter = dict.find("apple");
//    if (iter == dict.end()) {
//        
//    }
//    
//    vector<int> intv(3,5);
//    cout << intv.size() << "\n";
//    for (int i = 0; i < intv.size(); i ++) {
//        cout << intv[i] << " ";
//    }
//    
//    for (int i = 0; i < intv.size() - 1; i ++) {
//        for (int j = i + 1; j < intv.size(); j ++) {
//            if (intv[i] > intv[j]) {
//                intv[i] = intv[i] xor intv[j];
//                intv[j] = intv[i] xor intv[j];
//                intv[i] = intv[i] xor intv[j];
//            }
//        }
//    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

