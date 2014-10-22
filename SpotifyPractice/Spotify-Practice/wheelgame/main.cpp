//
//  main.cpp
//  wheelgame
//
//  Created by Haoquan Guo on 2/15/12.
//  Copyright 2012 NYU. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int * p;

int links(vector<int> queue);

int links(vector<int> queue) {
    if (queue.size() == 1) {
        if (queue[0] == 0) {
            return -1;
        }
        if (queue[0] == 1) {
            return -1;
        }
    }
    bool pos = false, neg = false;
    
//    for (int i = 0; i < queue.size(); i ++) {
//        int sum_val = -1;
//        for (int j = 0; j < queue.size(); j ++) {
//            if (i != j) {
//                sum_val *= p[queue[j]];
//            }
//        }
//        if (queue[i] < 2) {
//            if (sum_val == 1) {
//                pos = true;
//            }
//            if (sum_val == -1) {
//                neg = true;
//            }
//        }
//        else {
//            for (int j = 0; j < queue[i] - 1; j ++) {
//                int val = sum_val * p[j] * p[queue[i] - j - 2];
//                if (val == 1) {
//                    pos = true;
//                }
//                if (val == -1) {
//                    neg = true;
//                }
//            }
//        }
//        
//    }
    
    for (int i = 0; i < queue.size(); i ++) {
        if (queue[i] == 0) {
            continue;
        }
        int val;
        if (queue[i] == 1) {
            vector<int> new_queue = queue;
            new_queue[i] = new_queue.back();
            new_queue.pop_back();
            val = -1 * links(new_queue);
            if (val == 1) {
                pos = true;
            }
            if (val == -1) {
                neg = true;
            }
        }
        if (queue[i] == 2) {
            vector<int> new_queue = queue;
            new_queue[i] = 0;
            val = -1 * links(new_queue);
            if (val == 1) {
                pos = true;
            }
            if (val == -1) {
                neg = true;
            }
        }
        if (queue[i] > 2) {
            for (int j = 0; j < queue[i] - 2; j ++) {
                vector<int> new_queue = queue;
                new_queue[i] = j;
                new_queue.push_back(queue[i] - j - 3);
                val = -1 * links(new_queue);
//                cout << "with ";
//                for (int k = 0; k < new_queue.size(); k ++) {
//                    cout << new_queue[k] << " ";
//                }
//                cout << "\nval = " << val << "\n";
                if (val == 1) {
                    pos = true;
                }
                if (val == -1) {
                    neg = true;
                }
                if (pos && neg) {
                    return 0;
                }
            }
        }
    }
    if (pos && neg) {
        return 0;
    }
    if (pos && !neg) {
        return 1;
    }
    if (!pos && neg) {
        return -1;
    }
    return -1;
}

int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    p = new int[n];
    p[0] = 1;
    p[1] = -1;
    p[2] = -1;
    for (int i = 3; i < n; i ++) {
        bool pos = false, neg = false;
        if (-1 * p[i-2] == 1) {
            pos = true;
        }
        if (-1 * p[i-2] == -1) {
            neg = true;
        }
        for (int j = 0; j <= i - 3; j ++) {
            int val = -1 * p[j] * p[i - j - 3];
            if (val == 1) {
                pos = true;
            }
            if (val == -1) {
                neg = true;
            }
        }
        if (pos && neg) {
            p[i] = 0;
        }
        if (pos && !neg) {
            p[i] = 1;
        }
        if (!pos && neg) {
            p[i] = -1;
        }
    }
    
    for (int i = 0; i < n; i ++) {
        cout << "p[" << i << "]\t" << p[i] << "\n";
    }
    
    for (int i = 0; i < n; i ++) {
        vector<int> s;
        s.push_back(i);
        int ss = links(s);
        cout << "s[" << i << "]\t" << ss << "\n";
        if (p[i+1] != 1 && ss == 1) {
            cout << "!!" << i + 3 << "\n";
        }
    }
    
    cout << "p[n-2]:" << p[n-2] << "\n";
//    cout << "s[n-3]:" << ss << "\n";
//    if (p[n-2] == 1 || ss == 1) {
        cout << "The robot is your friend\n";
//    }
//    else {
        cout << "Destroy the robot before it is too late\n";
//    }
    return 0;
}

