//
//  main.cpp
//  ferries
//
//  Created by Haoquan Guo on 2/25/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "string.h"

using namespace std;

int main (int argc, const char * argv[])
{
    int n, t = 0;
    cin >> n;
    while (n > 0) {
        t ++;
        map<string, string> edges;
        map<string, vector<int> > factors;
        set<string> dst_set;
        edges.clear();
        factors.clear();
        dst_set.clear();
        for (int i = 0; i < n; i ++) {
            string src, dst, media;
            cin >> src >> dst >> media;
            dst_set.insert(dst);
            edges[src] = dst;
            if (strcmp(media.c_str(), "road") == 0) {
                int road_length;
                cin >> road_length;
                vector<int> fact (1, road_length);
                factors[src] = fact;
            }
            if (strcmp(media.c_str(), "ferry") == 0) {
                int ferry_time, ferry_freq;
                vector<int> fact;
                cin >> ferry_time >> ferry_freq;
                fact.push_back(ferry_time);
                fact.push_back(ferry_freq);
                for (int j = 0; j < ferry_freq; j ++) {
                    int ferry_board;
                    cin >> ferry_board;
                    fact.push_back(ferry_board);
                }
                factors[src] = fact;
            }
        }
        
        string str;
        for (map<string, string>::iterator ei = edges.begin(); ei != edges.end(); ei ++) {
            if (dst_set.find(ei->first) == dst_set.end()) {
                str = ei->first;
                break;
            }
        }

        vector<int> arr(1, 0);
        vector<double> spd(1, 0.00);
        
        int dist = 0;
        map<string, string>::iterator ei = edges.find(str);
        while (ei != edges.end()) {
            map<string, vector<int> >::iterator fi = factors.find(ei->first);
            vector<int> info = fi->second;
            
//            cout << "-------\n";
//            cout << "> " << ei->first << "\n";
//            cout << "> " << dist << "\n";
//            for (int i = 0; i < arr.size(); i ++) {
//                cout << ">> " << arr[i] << " \t" << spd[i] << "\n";
//            }
            
            // is road
            if (info.size() == 1) {
                dist += info[0];
            }
            // is ferry
            if (info.size() > 1) {
                vector<int> arr_new(info[1], -1);
                vector<double> spd_new(info[1], -1);
                for (int j = 0; j < info[1]; j ++) {
                    for (int k = 0; k < arr.size(); k ++) {
                        int t0 = arr[k];
                        int t1 = dist * 45;
                        int t2 = info[j+2] * 60;
                        int t3 = 3600 * ((t0 + t1) / 3600) + t2;
                        if (t3 < t0 + t1) {
                            t3 += 3600;
                        }
                        double speed = 1.0 * dist / (t3 - t0) * 3600;
                        if (spd[k] > speed) {
                            speed = spd[k];
                        }
                        t3 += info[0] * 60;
                        if (arr_new[j] == -1) {
                            arr_new[j] = t3;
                            spd_new[j] = speed;
                            continue;
                        }
                        if (arr_new[j] > t3 || (arr_new[j] == t3 && spd_new[j] > speed)) {
                            arr_new[j] = t3;
                            spd_new[j] = speed;                            
                        }
                    }
                }
                arr = arr_new;
                spd = spd_new;
                dist = 0;
            }
            string next = ei->second;
            ei = edges.find(next);
        }
        
        int final_t;
        double final_s;
        if (dist > 0) {
            int j = 0;
            for (int i = 1; i < arr.size(); i ++) {
                if (arr[i] < arr[j]) {
                    j = i;
                }
            }
            final_t = arr[j] + dist * 45;
            final_s = 80;
        }
        else {
            int j = 0;
            for (int i = 1; i < arr.size(); i ++) {
                if (arr[i] < arr[j] || (arr[i] == arr[j] && spd[i] < spd[j])) {
                    j = i;
                }
            }
            final_t = arr[j];
            final_s = spd[j];
        }
        int hh, mm, ss;
        hh = final_t / 3600;
        mm = final_t % 3600 / 60;
        ss = final_t % 60;
        
        cout << "Test Case " << t << ": ";
        if (hh < 10) {
            cout << "0";
        }
        cout << hh << ":";
        if (mm < 10) {
            cout << "0";
        }
        cout << mm << ":";
        if (ss < 10) {
            cout << "0";
        }
        cout << ss << " ";
        
        cout.precision(2);
        cout << fixed << final_s << "\n\n";
        cin >> n;
    }
    return 0;
}

