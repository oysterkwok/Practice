//
//  main.cpp
//  oct2_2011_c
//
//  Created by Haoquan Guo on 3/1/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int main (int argc, const char * argv[])
{
    double x, y;
    vector<pair<double, double> > cords, oris;
    while (!(cin >> x >> y).eof()) {
        cords.push_back(pair<int, int> (x, y));
    }
    
    for (int i = 0; i < cords.size(); i ++) {
        for (int j = 0; j < cords.size(); j ++) {
            double dist = sqrt(pow((cords[i].first - cords[j].first), 2) + pow((cords[i].second - cords[j].second), 2));
            double k = 2.51*2.51 - pow(dist/2, 2);
            if (k < 0) {
                cout << k << "\n";
                continue;
            }
            pair<double, double> mid, ori;
            mid.first = (cords[i].first + cords[j].first) * .5;
            mid.second = (cords[i].second + cords[j].second) * .5;
            ori.first = mid.first - sqrt(k) * (cords[i].second - cords[j].second) / dist;
            ori.second = mid.second + sqrt(k) * (cords[i].first - cords[j].first) / dist;
            if (ori.first >= 0 && ori.first <= 50 && ori.second >= 0 && ori.second <= 50) {
                cout << ori.first << "," << ori.second << "\n";
                oris.push_back(ori);
            }
            ori.first = mid.first + sqrt(k) * (cords[i].second - cords[j].second) / dist;
            ori.second = mid.second - sqrt(k) * (cords[i].first - cords[j].first) / dist;
            if (ori.first >= 0 && ori.first <= 50 && ori.second >= 0 && ori.second <= 50) {
                cout << ori.first << "," << ori.second << "\n";
                oris.push_back(ori);
            }
        }
    }
    
    int bigest = 0;
    for (int i = 0; i < oris.size(); i ++) {
        int count = 0;
        for (int j = 0; j < cords.size(); j ++) {
            double dist = pow((oris[i].first - cords[j].first), 2) + pow((oris[i].second - cords[j].second), 2);
            if (dist <= 2.51 * 2.51) {
                count ++;
            }
            else {
                cout << dist << "\n";
            }
        }
        if (count > bigest) {
            bigest = count;
        }
    }
    cout << bigest << "\n";
    return 0;
}

